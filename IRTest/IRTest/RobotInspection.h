#pragma once
#include"stdafx.h"
#include<vector>
using namespace std;
//typedef unsigned char BYTE;
//typedef unsigned short WORD;
#ifdef ROBOTINSPECTION_EXPORTS
#define ROBOTINSPECTION_API __declspec(dllexport)
#else
#define ROBOTINSPECTION_API __declspec(dllimport)
#endif

//�������
#define NO_ERROR 0
#define ERROR_GETDEVICEINFO_FAIL 1
#define ERROR_OPENSTREAM_FAIL 2
#define ERROR_CLOSESTREAM_FAIL 3
#define ERROR_CHANGEIPADDRESS_FAIL 4
#define ERROR_SLAP_FAIL 5
#define ERROR_STARTSCOPE_FAIL 6
#define ERROR_STOPSCOPE_FAIL 7
#define ERROR_SHUTTER_FAIL 8
#define ERROR_PALETTE_FAIL 9
#define ERROR_NEARFOCUS_FAIL 10
#define ERROR_FARFOCUS_FAIL 11
#define ERROR_AUTOFOCUS_FAIL 12
#define ERROR_STOPFOCUS_FAIL 13
#define ERROR_GETSTEPPINGMOTORPOS_FAIL 14
#define ERROR_SETSTEPPINGMOTORPOS_FAIL 15
#define ERROR_QUERYVERSIONINFO_FAIL 16
#define ERROR_OPENFILE_FAIL 17
#define ERROR_ADDRECTANALYSER_FAIL 18
#define ERROR_DELETERECTANALYSER_FAIL 19
#define ERROR_CHANGEANALYSERTEMPERATURESHOWTYPE_FAIL 20
#define ERROR_DECODEH264STREAM_FAIL 21
#define ERROR_STOPDECODEH264STREAM_FAIL 22
#define ERROR_ENABLEADDSTRING_FAIL 23
#define ERROR_ADDSTRING_FAIL 24
#define ERROR_DISABLEADDSTRING_FAIL 25
#define ERROR_ENABLESHUTTER_FAIL 26
#define ERROR_DISABLESHUTTER_FAIL 27
#define ERROR_SETSHUTTERTIME_FAIL 28
#define ERROR_GETDEVICESERIALNUMBER_FAIL 29
#define ERROR_GETSDKVERSION_FAIL 30

enum LiveStream_DeviceState
{
	LiveStream_Y8DataRecvSuccess = 1,
	LiveStream_Y8DataRecvFail = 2,
	LiveStream_Y16DataRecvSuccess = 3,
	LiveStream_Y16DataRecvFail = 4,
};

struct LiveStream_LiveVideoStreamRGBCallBack
{
	unsigned char* pRGBData;
	int nWidth;
	int nHeight;
	int nSessionID;
};

struct LiveStream_H264StreamCallBack
{
	unsigned char* pPackageData;
	int nSize;
	int nSessionID;
};

typedef struct POINT_INFO
{
	float temp;
	int x;
	int y;
};

struct LiveStream_MeasureDataCallBack
{
	short* y16IRData; //y16����
	int y16DataLen;
	float* MeasureMatrix; //�¶Ⱦ���
	int matrixDataLen;
	short* CurveData;
	int CurveLen;
	int ImgWidth;
	int ImgHeight;
	int iSectionID;
	int iMFocusSpeed; //�ֶ������ٶ�
	int iTouchNearSwitch; //�Ƿ�����������λ���� 0-�� 1-��
	int iTouchFarSwitch; //�Ƿ�����Զ����λ���� 0-�� 1-��
	int iAutoFocusFinish; //�Զ��Խ��Ƿ���� 0-�� 1-��
	int iAFocusForwardSpeed; //�Զ��Խ�ǰ���ٶ�
	int iAFocusBackSpeed; //�Զ��Խ������ٶ�
	int iAFocusTotalFrame; //�Զ��Խ�ͳ��֡��
	int iDimmingMode; //����ģʽ
	short AutoThrowPointRatio; //�Զ��׵����
	short Brightness; 	//����
	short Contrast; 		//�Աȶ�
	short MDimY16Min;  //�ֶ������Y16Min
	short MDimY16Max;  //�ֶ������Y16Max
	short LsothermY16Min; //������Y16Min
	short LsothermY16Max; //������Y16Max
	int iSpecialColorNum; //����ɫ�ʱ��
	int iLsothermMode; //������ģʽ
	int iPaletteNum; //��ɫ��
	int iShutterCompensationTimeSetting; //���Ŷ�ʱ����ʱ������
	int iShutterStatus; //����״̬��0-û�д���� 1-���ڴ����
	int iRecoveryStatus; //�ָ�״̬��1-�ָ��������óɹ� 2-�ָ��û����óɹ�
	int iSaveSetting; //�������� 1-����ɹ�
	int iTimingCompensationFunction; //��ʱ�������� 0-�� 1-��
	short CursorStatus; //���״̬
	short CursorXValue; //X����
	short CursorYValue; //Y����
	short CursorADValue; //��괦ADֵ
	int iTestImageModeSetting; //����ͼ��ģʽ����
	int iRemoveBarAlgorithmSwitch; //ȥ�����㷨����
	int iRemoveNoiseAlgorithmSwitch; //ȥ���㷨����
	int iEnhanceAlgorithmSwitch; //��ǿ�㷨����
	int iFreezeSwitch; //���񿪹�
	int iDigitalContextSelectFlag; //���ֿڴ�������ѡ���־
	int iNETDTest; //NETD���Կ���
	int iFrameRate; //֡Ƶ 25/9
	short DetectorTemp; //̽������ƽ���¶�	
	short	ProgramVersion;  //����汾
	int iGFID;
	int iVSK;
	int iGAIN;
	int iIntegrationTime;	
	int iEmiss;
	int iDistance;
	int iRelHum;
	int iBackgroundTemp;
	int iBackgroundTempFlag;
	short MeasureRangeInfo; //���·�Χ��Ϣ
	short VersionInfo; //��ʽ�����԰���Ϣ
	short DetectorGear;	//̽������λ
	short SecondChangeGearTime; //�ڶ����е�ʱ��
	short Y16_Max;//����Y16���ֵ
	short Y16_Max_x;
	short Y16_Max_y;
	short Y16_Average;//y16�м�ֵ
	short Y16_Min;//y16��Сֵ
	short Y16_Min_x;
	short Y16_Min_y;
	short Y16_Center;//Y16�м�ֵCenterAD
	short Y16_Center_x;
	short Y16_Center_y;
	int iMeasureCursorShowMode; //���¹����ʾģʽ 0-�����ʾ���ֵ������ֵ��Ĭ�ϣ� 1-���ֵ����Сֵ 2-����ֵ����Сֵ
	int iAnalyzeMode; //����ģʽ 0-�رշ��� 1-����� 2-�������
	short Temp101; //�źŰ�101�´��¶�
	short Area_x; //�������Ͻ�X����
	short Area_y; //�������Ͻ�Y����
	short AreaWidth; //�����
	short AreaHeight; //����
	short LastShutterTemp; //��һ�ο����¶�
	int iY16Flag;
	short AtmosphereTemp;  //�����¶�
	short RealShutterTemp; //ʵʱ�����¶�
	int iT_Center;
	int iT_Max;
	int TempBeforeCorrection;
	int StartTemp;
	int iT_Min;
	int iT_Avg;
};

struct LiveStream_RGBAndMeasureDataCallBack
{
	BYTE* pRGBData;				// Y8����
	int RGBDataLen;				// Y8���ݳ���
	short* y16IRData; //y16����
	int y16DataLen;
	float* MeasureMatrix; //�¶Ⱦ���
	int matrixDataLen;
	short* CurveData;
	int CurveLen;
	int ImgWidth;
	int ImgHeight;
	int iSectionID;
	int iMFocusSpeed; //�ֶ������ٶ�
	int iTouchNearSwitch; //�Ƿ�����������λ���� 0-�� 1-��
	int iTouchFarSwitch; //�Ƿ�����Զ����λ���� 0-�� 1-��
	int iAutoFocusFinish; //�Զ��Խ��Ƿ���� 0-�� 1-��
	int iAFocusForwardSpeed; //�Զ��Խ�ǰ���ٶ�
	int iAFocusBackSpeed; //�Զ��Խ������ٶ�
	int iAFocusTotalFrame; //�Զ��Խ�ͳ��֡��
	int iDimmingMode; //����ģʽ
	short AutoThrowPointRatio; //�Զ��׵����
	short Brightness; 	//����
	short Contrast; 		//�Աȶ�
	short MDimY16Min;  //�ֶ������Y16Min
	short MDimY16Max;  //�ֶ������Y16Max
	short LsothermY16Min; //������Y16Min
	short LsothermY16Max; //������Y16Max
	int iSpecialColorNum; //����ɫ�ʱ��
	int iLsothermMode; //������ģʽ
	int iPaletteNum; //��ɫ��
	int iShutterCompensationTimeSetting; //���Ŷ�ʱ����ʱ������
	int iShutterStatus; //����״̬��0-û�д���� 1-���ڴ����
	int iRecoveryStatus; //�ָ�״̬��1-�ָ��������óɹ� 2-�ָ��û����óɹ�
	int iSaveSetting; //�������� 1-����ɹ�
	int iTimingCompensationFunction; //��ʱ�������� 0-�� 1-��
	short CursorStatus; //���״̬
	short CursorXValue; //X����
	short CursorYValue; //Y����
	short CursorADValue; //��괦ADֵ
	int iTestImageModeSetting; //����ͼ��ģʽ����
	int iRemoveBarAlgorithmSwitch; //ȥ�����㷨����
	int iRemoveNoiseAlgorithmSwitch; //ȥ���㷨����
	int iEnhanceAlgorithmSwitch; //��ǿ�㷨����
	int iFreezeSwitch; //���񿪹�
	int iDigitalContextSelectFlag; //���ֿڴ�������ѡ���־
	int iNETDTest; //NETD���Կ���
	int iFrameRate; //֡Ƶ 25/9
	short DetectorTemp; //̽������ƽ���¶�	
	WORD	ProgramVersion;  //����汾
	int iGFID;
	int iVSK;
	int iGAIN;
	int iIntegrationTime;	
	int iEmiss;
	int iDistance;
	int iRelHum;
	int iBackgroundTemp;
	int iBackgroundTempFlag;
	WORD MeasureRangeInfo; //���·�Χ��Ϣ
	WORD VersionInfo; //��ʽ�����԰���Ϣ
	short DetectorGear;	//̽������λ
	WORD SecondChangeGearTime; //�ڶ����е�ʱ��
	short Y16_Max;//����Y16���ֵ
	short Y16_Max_x;
	short Y16_Max_y;
	short Y16_Average;//y16�м�ֵ
	short Y16_Min;//y16��Сֵ
	short Y16_Min_x;
	short Y16_Min_y;
	short Y16_Center;//Y16�м�ֵCenterAD
	short Y16_Center_x;
	short Y16_Center_y;
	int iMeasureCursorShowMode; //���¹����ʾģʽ 0-�����ʾ���ֵ������ֵ��Ĭ�ϣ� 1-���ֵ����Сֵ 2-����ֵ����Сֵ
	int iAnalyzeMode; //����ģʽ 0-�رշ��� 1-����� 2-�������
	short Temp101; //�źŰ�101�´��¶�
	short Area_x; //�������Ͻ�X����
	short Area_y; //�������Ͻ�Y����
	short AreaWidth; //�����
	short AreaHeight; //����
	short LastShutterTemp; //��һ�ο����¶�
	int iY16Flag;
	short AtmosphereTemp;  //�����¶�
	short RealShutterTemp; //ʵʱ�����¶�
	int iT_Center;
	int iT_Max;
	int TempBeforeCorrection;
	int StartTemp;
	int iT_Min;
	int iT_Avg;
};

typedef int (CALLBACK *LIVEVIDEOSTREAMSTATERECV_CB)(const int state);
typedef int (CALLBACK *LIVEVIDEOMEASURESTATERECV_CB)(const int state);
typedef int (CALLBACK *H264STREAMRECV_CB)(const LiveStream_H264StreamCallBack *pInfo);
typedef int (CALLBACK *LIVEVIDEOSTREAMRGBRECV_CB)(const LiveStream_LiveVideoStreamRGBCallBack *pInfo);
typedef int (CALLBACK *LIVEVIDEOMEASUREDATARECV_CB)(const LiveStream_MeasureDataCallBack *pInfo);
typedef int (CALLBACK *LIVEVIDEORGBANDMEASUREDATARECV_CB)(const LiveStream_RGBAndMeasureDataCallBack *pInfo);

//��ȡ�豸ͼ��ֱ���
extern "C" ROBOTINSPECTION_API int LiveStream_GetDeviceInfo(int* width, int* height);

//����Ƶ y8+Y16
extern "C" ROBOTINSPECTION_API int LiveStream_OpenStream(const char* strIpAddr, HWND hWnd, H264STREAMRECV_CB h264StreamCallBack, LIVEVIDEOSTREAMRGBRECV_CB liveVideoStreamRGBCallback, LIVEVIDEOMEASUREDATARECV_CB liveVideoMeasureDataCallBack, LIVEVIDEOSTREAMSTATERECV_CB liveVideoStreamStateCallBack, LIVEVIDEOMEASURESTATERECV_CB liveVideoMeasureStateCallBack);

//�ر���Ƶ
extern "C" ROBOTINSPECTION_API int LiveStream_CloseStream(int iSessionID);

//����Ƶ Y16
extern "C" ROBOTINSPECTION_API int LiveStream_OpenDevice(const char* strIpAddr, HWND hWnd, int palIndex, LIVEVIDEORGBANDMEASUREDATARECV_CB liveVideoRGBAndMeasureDataCallBack, LIVEVIDEOMEASURESTATERECV_CB liveVideoMeasureStateCallBack);

//�ر���Ƶ
extern "C" ROBOTINSPECTION_API int LiveStream_CloseDevice(int iSessionID);

//H264����������ʾ
extern "C" ROBOTINSPECTION_API int LiveStream_DecodeH264Stream(LiveStream_H264StreamCallBack* h264Stream, HWND hWnd);

//ֹͣH264����
extern "C" ROBOTINSPECTION_API int LiveStream_StopDecodeH264Stream();

//�����
extern "C" ROBOTINSPECTION_API int LiveStream_Shutter(const char* strIpAddr);

//����ʹ�ܿ�
extern "C" ROBOTINSPECTION_API int LiveStream_EnableShutter(const char* strIpAddr);

//����ʹ�ܹ�
extern "C" ROBOTINSPECTION_API int LiveStream_DisableShutter(const char* strIpAddr);

//���ÿ��Ų���ʱ��
extern "C" ROBOTINSPECTION_API int LiveStream_SetShutterTime(const char* strIpAddr, int min);

//�л�ɫ��
extern "C" ROBOTINSPECTION_API int LiveStream_Palette(const char* strIpAddr,int index);

//����
extern "C" ROBOTINSPECTION_API int LiveStream_NearFocus(const char* strIpAddr);

//Զ��
extern "C" ROBOTINSPECTION_API int LiveStream_FarFocus(const char* strIpAddr);

//�Զ�����
extern "C" ROBOTINSPECTION_API int LiveStream_AutoFocus(const char* strIpAddr);

//ֹͣ����
extern "C" ROBOTINSPECTION_API int LiveStream_StopFocus(const char* strIpAddr);

//�޸�IP��ַ
extern "C" ROBOTINSPECTION_API int LiveStream_ChangeDeviceAddress(const char* sNewIP, const char* sNetMask, const char* sNewGateWay, const char* sNewDNS, const char* sOriIP);

//����
extern "C" ROBOTINSPECTION_API int LiveStream_Slap(const char* filename, int iSessionID);

//��ʼ¼��
extern "C" ROBOTINSPECTION_API int LiveStream_ScopeStart(const char* filename, int iSessionID);

//����¼��
extern "C" ROBOTINSPECTION_API int LiveStream_ScopeStop(int iSessionID);

//��ȡ���������λ��
extern "C" ROBOTINSPECTION_API int LiveStream_GetSteppingMotorPosition(const char* strIpAddr);

//���ò��������λ��
extern "C" ROBOTINSPECTION_API int LiveStream_SetSteppingMotorPosition(const char* strIpAddr, int pos);

//��ѯ�̼��汾��
extern "C" ROBOTINSPECTION_API int LiveStream_QueryVersionInfo(const char* strIpAddr, char* armVersion, char* fpgaVersion);

//��ȡͼƬ��������¶�
extern "C" ROBOTINSPECTION_API int LiveStream_GetPointTemperatureFromPicture(const char* filename, int x, int y, float* pointT);

//��ȡͼƬȫͼ�¶Ⱦ���
extern "C" ROBOTINSPECTION_API int LiveStream_GetGlobalTemperatureFromPicture(const char* filename, float* imageT);

//��ȡͼƬ������¶���Ϣ
extern "C" ROBOTINSPECTION_API int LiveStream_GetRectTemperatureFromPicture(const char* filename, int x, int y, int width, int height, POINT_INFO* maxInfo, POINT_INFO* minInfo, float* avgT);

//��ӷ�������
extern "C" ROBOTINSPECTION_API int LiveStream_AddRectAnalyser(const char* strIpAddr, int x, int y, int width, int height, int type);

//ɾ����������
extern "C" ROBOTINSPECTION_API int LiveStream_DeleteRectAnalyser(const char* strIpAddr);

//�л����������¶���ʾģʽ
extern "C" ROBOTINSPECTION_API int LiveStream_ChangeAnalyserTemperatureShowType(const char* strIpAddr, int type);

//���������ַ�����
extern "C" ROBOTINSPECTION_API int LiveStream_EnableAddStringToStream(const char* strIpAddr);

//ͼ������ַ���
extern "C" ROBOTINSPECTION_API int LiveStream_AddStringToStream(const char* strIpAddr, int x, int y, const char* content);

//�رյ����ַ�����
extern "C" ROBOTINSPECTION_API int LiveStream_DisableAddStringToStream(const char* strIpAddr);

//��ȡ�����豸��
extern "C" ROBOTINSPECTION_API int LiveStream_GetDeviceSerialNumber(const char* strIpAddr, char* serialNum);

//��ȡSDK�汾��Ϣ
extern "C" ROBOTINSPECTION_API int LiveStream_GetSDKVersion(char* sdkVersion);

//��ȡ�����¶�
extern "C" ROBOTINSPECTION_API int LiveStream_GetAlarmTemp(const char* strIpAddr, int* temp);

//���ñ����¶�
extern "C" ROBOTINSPECTION_API int LiveStream_SetAlarmTemp(const char* strIpAddr, int temp);

//ȡ�������¶�
extern "C" ROBOTINSPECTION_API int LiveStream_CancleAlarmTemp(const char* strIpAddr);

//�����豸��ǰ���� 
extern "C" ROBOTINSPECTION_API int LiveStream_SetCurrentDate(const char* strIpAddr, const char* date);

//�����豸��ǰʱ��
extern "C" ROBOTINSPECTION_API int LiveStream_SetCurrentTime(const char* strIpAddr, const char* time);

//����Y16֡Ƶ
extern "C" ROBOTINSPECTION_API int LiveStream_SetFrameFrequency(const char* strIpAddr, int fps);

//��ȡ�ϴδ���
extern "C" ROBOTINSPECTION_API int LiveStream_GetLastError();

