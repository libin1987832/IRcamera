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
	//printf("picture %d",);
	static int index=0;
	printf("picture w(%d),h(%d),size(%d,%d),%d",pInfo->ImgWidth,pInfo->ImgHeight,pInfo->RGBDataLen,3*pInfo->ImgWidth*pInfo->ImgHeight,pInfo->matrixDataLen);
	if(pInfo->pRGBData != NULL)
	{		
		char imageName[100];
		sprintf(imageName, "image/i_%d.jpg", index++);
		BYTE* mem = new BYTE[3*pInfo->ImgWidth*pInfo->ImgHeight];

		memcpy(mem, pInfo->pRGBData, 3*pInfo->ImgWidth*pInfo->ImgHeight);
		int row=pInfo->ImgHeight;
		int col=pInfo->ImgWidth;
		Mat src(row,col,CV_8UC1,mem);
		imwrite(imageName,src);
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
			HINSTANCE hdll;
			//cv::namedWindow("aa");
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
