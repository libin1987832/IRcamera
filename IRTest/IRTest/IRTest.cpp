// IRTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "IRTest.h"
#include "RobotInspection.h"
#include "opencv/highgui.h"
#include "opencv/cv.h"
using namespace cv;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;
typedef int (*Dllfun)(const char* strIpAddr, HWND hWnd, H264STREAMRECV_CB h264StreamCallBack, LIVEVIDEOSTREAMRGBRECV_CB liveVideoStreamRGBCallback, LIVEVIDEOMEASUREDATARECV_CB liveVideoMeasureDataCallBack, LIVEVIDEOSTREAMSTATERECV_CB liveVideoStreamStateCallBack, LIVEVIDEOMEASURESTATERECV_CB liveVideoMeasureStateCallBack);
typedef int (*Dllfun2)(const char* strIpAddr, HWND hWnd, int palIndex, LIVEVIDEORGBANDMEASUREDATARECV_CB liveVideoRGBAndMeasureDataCallBack, LIVEVIDEOMEASURESTATERECV_CB liveVideoMeasureStateCallBack);
typedef int (*Dllfun3)(int iSessionID);
typedef int (*Dllfun4)(const char* filename, int iSessionID);
bool stop =true;
Mat contour(Mat& image)
{
	Mat gray;
	Vec3b p;
	cvtColor(image, gray, CV_BGR2GRAY);
	GaussianBlur(gray, gray, Size(3, 3), 3, 3);
	Mat img;
	threshold(gray, img, 0, 255, THRESH_OTSU);
	Mat img1;
	img.copyTo(img1);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(img, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
	Mat resultImage = Mat::zeros(img.size(), CV_8U);
	for (int j = 0; j < contours.size(); j++)
	{
		vector<Point> poly;
		approxPolyDP(Mat(contours[j]), poly, 5, true);
		Rect r = boundingRect(Mat(poly));
		int needPoint = 50;
		int nowPoint = 0;
		while(nowPoint<needPoint&&poly.size()>10)
		{
			int rx = rand() % (r.width) + r.x;
			int ry = rand() % (r.height) + r.y;
			double d=pointPolygonTest(poly, Point2f(rx, ry), false);
			if (d > 0) {
				nowPoint++;
				p[0] = 255;
				p[1] = 0;
				p[2] = 0;
				image.at<Vec3b>(ry, rx) = p;
			}

		}

		vector<Point>::const_iterator itp = poly.begin();
		while (itp != (poly.end() - 1))
		{
			line(image, *itp, *(itp + 1), Scalar(255), 2);
			++itp;
		}
		line(image, *itp, *(poly.begin()), Scalar(255), 2);
	}
	return image;
}
int CALLBACK rgbcallback(const LiveStream_RGBAndMeasureDataCallBack *pInfo)
{
	//return 0;
	//printf("picture %d",);
	static int index=0;
	printf("picture w(%d),h(%d),size(%d,%d),%d",pInfo->ImgWidth,pInfo->ImgHeight,pInfo->RGBDataLen,3*pInfo->ImgWidth*pInfo->ImgHeight,pInfo->matrixDataLen);
			int row=pInfo->ImgHeight;
		int col=pInfo->ImgWidth;
	Mat mask=Mat::zeros(row,col,CV_8U);
	char imageName[100];
		sprintf(imageName, "image/i_%d.jpg", index++);
	if(pInfo->MeasureMatrix!=NULL)
	{

		//float* mem = new float[pInfo->ImgWidth*pInfo->ImgHeight];
		//memcpy(mem, pInfo->MeasureMatrix, pInfo->ImgWidth*pInfo->ImgHeight);
		/*Mat src(row,col,CV_32F,mem);
		float belt=255.0f/170.0f;
		float alph=20.0f*belt;
		Mat m;
		printf("tem:%f,%f\n",pInfo->MeasureMatrix[pInfo->ImgWidth*200+200],src.at<float>(200,200));
		src.convertTo(m,CV_8U,belt,alph);
		uchar uu=m.at<uchar>(200,200);
		printf("tem:%d\n,%d",(int)uu,sizeof(float));*/
		float belt=255.0f/170.0f;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(pInfo->MeasureMatrix[i*col+j]>20&&pInfo->MeasureMatrix[i*col+j]<40)
				{
					mask.at<uchar>(i,j)=255;
					//mask.at<uchar>(i,j)=(pInfo->MeasureMatrix[i*col+j]+20)*belt;
				}
				else
					mask.at<uchar>(i,j)=0;
			}
		}
		//printf("tem:%f,%d\n",pInfo->MeasureMatrix[pInfo->ImgWidth*200+200],(int)mask.at<uchar>(200,200));
		//imwrite(imageName,mask);
		//threshold(m,mask,-10.0f*belt+alph,255,THRESH_TOZERO);
		//threshold(mask,mask,130.0f*belt+alph,255,THRESH_TOZERO_INV);
		//threshold(mask,mask,-10.0f*belt+alph,255,THRESH_BINARY);
		//imwrite(imageName,mask);
		//delete [] mem;
		//return 1;
	}
	if(pInfo->pRGBData != NULL)
	{		
		
	
		BYTE* mem = new BYTE[3*pInfo->ImgWidth*pInfo->ImgHeight];
		memcpy(mem, pInfo->pRGBData, 3*pInfo->ImgWidth*pInfo->ImgHeight);
		Mat rgbsrc(row,col,CV_8UC3,mem);
		//imshow("windows1",src);
		//waitKey(1);
		//contour(src);
		Mat ss(row,col,CV_8UC3);
		rgbsrc.copyTo(ss,mask);
		imwrite(imageName,ss);
		delete [] mem;
		//imshow("aa",src);
		//waitKey(1);
	}
	return 1;

}
int CALLBACK statscallback(const int state)
{

	return 1;
}
void fule()
{}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
			Dllfun2 maopao1;
			Dllfun3 maopao3;
			Dllfun4 maopao4;
			HINSTANCE hdll;
			//cv::namedWindow("aa");
			//cv::namedWindow("windows1",0); //创建一个窗口 
			//HWND hWnd = (HWND)cvGetWindowHandle("windows1");//获取子窗口的HWND
			hdll=LoadLibrary(L"RobotInspection.dll");
			if(hdll==NULL)
			{
				FreeLibrary(hdll);
			}
			maopao1=(Dllfun2)GetProcAddress(hdll,"LiveStream_OpenDevice");
			maopao3=(Dllfun3)GetProcAddress(hdll,"LiveStream_CloseDevice");
			LIVEVIDEORGBANDMEASUREDATARECV_CB rgb=rgbcallback;
			LIVEVIDEOMEASURESTATERECV_CB stat=statscallback;
			int iSessionID=maopao1("192.168.1.168",NULL,1,rgb,stat);
			printf("iSessionID=%d",iSessionID);
			//Sleep(10000);
			//maopao4=(Dllfun4)GetProcAddress(hdll,"LiveStream_Slap");
			//maopao4("image/aa.jpg",iSessionID);
			printf("/n/n/n/ndsaf");
			char input=' ';
			scanf("%c",&input);
			maopao3(iSessionID);
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
