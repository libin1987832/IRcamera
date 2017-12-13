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

//错误代码
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
	short* y16IRData; //y16数据
	int y16DataLen;
	float* MeasureMatrix; //温度矩阵
	int matrixDataLen;
	short* CurveData;
	int CurveLen;
	int ImgWidth;
	int ImgHeight;
	int iSectionID;
	int iMFocusSpeed; //手动调焦速度
	int iTouchNearSwitch; //是否碰到近焦限位开关 0-否 1-是
	int iTouchFarSwitch; //是否碰到远焦限位开关 0-否 1-是
	int iAutoFocusFinish; //自动对焦是否完成 0-否 1-是
	int iAFocusForwardSpeed; //自动对焦前推速度
	int iAFocusBackSpeed; //自动对焦后推速度
	int iAFocusTotalFrame; //自动对焦统计帧数
	int iDimmingMode; //调光模式
	short AutoThrowPointRatio; //自动抛点比例
	short Brightness; 	//亮度
	short Contrast; 		//对比度
	short MDimY16Min;  //手动调光的Y16Min
	short MDimY16Max;  //手动调光的Y16Max
	short LsothermY16Min; //等温线Y16Min
	short LsothermY16Max; //等温线Y16Max
	int iSpecialColorNum; //特殊色彩编号
	int iLsothermMode; //等温线模式
	int iPaletteNum; //调色板
	int iShutterCompensationTimeSetting; //快门定时补偿时间设置
	int iShutterStatus; //快门状态：0-没有打快门 1-正在打快门
	int iRecoveryStatus; //恢复状态：1-恢复工厂设置成功 2-恢复用户设置成功
	int iSaveSetting; //保存设置 1-保存成功
	int iTimingCompensationFunction; //定时补偿功能 0-关 1-开
	short CursorStatus; //光标状态
	short CursorXValue; //X坐标
	short CursorYValue; //Y坐标
	short CursorADValue; //光标处AD值
	int iTestImageModeSetting; //测试图像模式设置
	int iRemoveBarAlgorithmSwitch; //去竖条算法开关
	int iRemoveNoiseAlgorithmSwitch; //去噪算法开关
	int iEnhanceAlgorithmSwitch; //增强算法开关
	int iFreezeSwitch; //定格开关
	int iDigitalContextSelectFlag; //数字口传输内容选择标志
	int iNETDTest; //NETD测试开关
	int iFrameRate; //帧频 25/9
	short DetectorTemp; //探测器焦平面温度	
	short	ProgramVersion;  //程序版本
	int iGFID;
	int iVSK;
	int iGAIN;
	int iIntegrationTime;	
	int iEmiss;
	int iDistance;
	int iRelHum;
	int iBackgroundTemp;
	int iBackgroundTempFlag;
	short MeasureRangeInfo; //测温范围信息
	short VersionInfo; //正式版或测试版信息
	short DetectorGear;	//探测器档位
	short SecondChangeGearTime; //第二次切档时间
	short Y16_Max;//整场Y16最大值
	short Y16_Max_x;
	short Y16_Max_y;
	short Y16_Average;//y16中间值
	short Y16_Min;//y16最小值
	short Y16_Min_x;
	short Y16_Min_y;
	short Y16_Center;//Y16中间值CenterAD
	short Y16_Center_x;
	short Y16_Center_y;
	int iMeasureCursorShowMode; //测温光标显示模式 0-光标显示最大值和中心值（默认） 1-最大值和最小值 2-中心值和最小值
	int iAnalyzeMode; //分析模式 0-关闭分析 1-点分析 2-区域分析
	short Temp101; //信号板101温传温度
	short Area_x; //区域左上角X坐标
	short Area_y; //区域左上角Y坐标
	short AreaWidth; //区域宽
	short AreaHeight; //区域长
	short LastShutterTemp; //上一次快门温度
	int iY16Flag;
	short AtmosphereTemp;  //大气温度
	short RealShutterTemp; //实时快门温度
	int iT_Center;
	int iT_Max;
	int TempBeforeCorrection;
	int StartTemp;
	int iT_Min;
	int iT_Avg;
};

struct LiveStream_RGBAndMeasureDataCallBack
{
	BYTE* pRGBData;				// Y8数据
	int RGBDataLen;				// Y8数据长度
	short* y16IRData; //y16数据
	int y16DataLen;
	float* MeasureMatrix; //温度矩阵
	int matrixDataLen;
	short* CurveData;
	int CurveLen;
	int ImgWidth;
	int ImgHeight;
	int iSectionID;
	int iMFocusSpeed; //手动调焦速度
	int iTouchNearSwitch; //是否碰到近焦限位开关 0-否 1-是
	int iTouchFarSwitch; //是否碰到远焦限位开关 0-否 1-是
	int iAutoFocusFinish; //自动对焦是否完成 0-否 1-是
	int iAFocusForwardSpeed; //自动对焦前推速度
	int iAFocusBackSpeed; //自动对焦后推速度
	int iAFocusTotalFrame; //自动对焦统计帧数
	int iDimmingMode; //调光模式
	short AutoThrowPointRatio; //自动抛点比例
	short Brightness; 	//亮度
	short Contrast; 		//对比度
	short MDimY16Min;  //手动调光的Y16Min
	short MDimY16Max;  //手动调光的Y16Max
	short LsothermY16Min; //等温线Y16Min
	short LsothermY16Max; //等温线Y16Max
	int iSpecialColorNum; //特殊色彩编号
	int iLsothermMode; //等温线模式
	int iPaletteNum; //调色板
	int iShutterCompensationTimeSetting; //快门定时补偿时间设置
	int iShutterStatus; //快门状态：0-没有打快门 1-正在打快门
	int iRecoveryStatus; //恢复状态：1-恢复工厂设置成功 2-恢复用户设置成功
	int iSaveSetting; //保存设置 1-保存成功
	int iTimingCompensationFunction; //定时补偿功能 0-关 1-开
	short CursorStatus; //光标状态
	short CursorXValue; //X坐标
	short CursorYValue; //Y坐标
	short CursorADValue; //光标处AD值
	int iTestImageModeSetting; //测试图像模式设置
	int iRemoveBarAlgorithmSwitch; //去竖条算法开关
	int iRemoveNoiseAlgorithmSwitch; //去噪算法开关
	int iEnhanceAlgorithmSwitch; //增强算法开关
	int iFreezeSwitch; //定格开关
	int iDigitalContextSelectFlag; //数字口传输内容选择标志
	int iNETDTest; //NETD测试开关
	int iFrameRate; //帧频 25/9
	short DetectorTemp; //探测器焦平面温度	
	WORD	ProgramVersion;  //程序版本
	int iGFID;
	int iVSK;
	int iGAIN;
	int iIntegrationTime;	
	int iEmiss;
	int iDistance;
	int iRelHum;
	int iBackgroundTemp;
	int iBackgroundTempFlag;
	WORD MeasureRangeInfo; //测温范围信息
	WORD VersionInfo; //正式版或测试版信息
	short DetectorGear;	//探测器档位
	WORD SecondChangeGearTime; //第二次切档时间
	short Y16_Max;//整场Y16最大值
	short Y16_Max_x;
	short Y16_Max_y;
	short Y16_Average;//y16中间值
	short Y16_Min;//y16最小值
	short Y16_Min_x;
	short Y16_Min_y;
	short Y16_Center;//Y16中间值CenterAD
	short Y16_Center_x;
	short Y16_Center_y;
	int iMeasureCursorShowMode; //测温光标显示模式 0-光标显示最大值和中心值（默认） 1-最大值和最小值 2-中心值和最小值
	int iAnalyzeMode; //分析模式 0-关闭分析 1-点分析 2-区域分析
	short Temp101; //信号板101温传温度
	short Area_x; //区域左上角X坐标
	short Area_y; //区域左上角Y坐标
	short AreaWidth; //区域宽
	short AreaHeight; //区域长
	short LastShutterTemp; //上一次快门温度
	int iY16Flag;
	short AtmosphereTemp;  //大气温度
	short RealShutterTemp; //实时快门温度
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

//获取设备图像分辨率
extern "C" ROBOTINSPECTION_API int LiveStream_GetDeviceInfo(int* width, int* height);

//开视频 y8+Y16
extern "C" ROBOTINSPECTION_API int LiveStream_OpenStream(const char* strIpAddr, HWND hWnd, H264STREAMRECV_CB h264StreamCallBack, LIVEVIDEOSTREAMRGBRECV_CB liveVideoStreamRGBCallback, LIVEVIDEOMEASUREDATARECV_CB liveVideoMeasureDataCallBack, LIVEVIDEOSTREAMSTATERECV_CB liveVideoStreamStateCallBack, LIVEVIDEOMEASURESTATERECV_CB liveVideoMeasureStateCallBack);

//关闭视频
extern "C" ROBOTINSPECTION_API int LiveStream_CloseStream(int iSessionID);

//开视频 Y16
extern "C" ROBOTINSPECTION_API int LiveStream_OpenDevice(const char* strIpAddr, HWND hWnd, int palIndex, LIVEVIDEORGBANDMEASUREDATARECV_CB liveVideoRGBAndMeasureDataCallBack, LIVEVIDEOMEASURESTATERECV_CB liveVideoMeasureStateCallBack);

//关闭视频
extern "C" ROBOTINSPECTION_API int LiveStream_CloseDevice(int iSessionID);

//H264码流解码显示
extern "C" ROBOTINSPECTION_API int LiveStream_DecodeH264Stream(LiveStream_H264StreamCallBack* h264Stream, HWND hWnd);

//停止H264解码
extern "C" ROBOTINSPECTION_API int LiveStream_StopDecodeH264Stream();

//打快门
extern "C" ROBOTINSPECTION_API int LiveStream_Shutter(const char* strIpAddr);

//快门使能开
extern "C" ROBOTINSPECTION_API int LiveStream_EnableShutter(const char* strIpAddr);

//快门使能关
extern "C" ROBOTINSPECTION_API int LiveStream_DisableShutter(const char* strIpAddr);

//设置快门补偿时间
extern "C" ROBOTINSPECTION_API int LiveStream_SetShutterTime(const char* strIpAddr, int min);

//切换色带
extern "C" ROBOTINSPECTION_API int LiveStream_Palette(const char* strIpAddr,int index);

//近焦
extern "C" ROBOTINSPECTION_API int LiveStream_NearFocus(const char* strIpAddr);

//远焦
extern "C" ROBOTINSPECTION_API int LiveStream_FarFocus(const char* strIpAddr);

//自动调焦
extern "C" ROBOTINSPECTION_API int LiveStream_AutoFocus(const char* strIpAddr);

//停止调焦
extern "C" ROBOTINSPECTION_API int LiveStream_StopFocus(const char* strIpAddr);

//修改IP地址
extern "C" ROBOTINSPECTION_API int LiveStream_ChangeDeviceAddress(const char* sNewIP, const char* sNetMask, const char* sNewGateWay, const char* sNewDNS, const char* sOriIP);

//拍照
extern "C" ROBOTINSPECTION_API int LiveStream_Slap(const char* filename, int iSessionID);

//开始录像
extern "C" ROBOTINSPECTION_API int LiveStream_ScopeStart(const char* filename, int iSessionID);

//结束录像
extern "C" ROBOTINSPECTION_API int LiveStream_ScopeStop(int iSessionID);

//获取步进电机的位置
extern "C" ROBOTINSPECTION_API int LiveStream_GetSteppingMotorPosition(const char* strIpAddr);

//设置步进电机的位置
extern "C" ROBOTINSPECTION_API int LiveStream_SetSteppingMotorPosition(const char* strIpAddr, int pos);

//查询固件版本号
extern "C" ROBOTINSPECTION_API int LiveStream_QueryVersionInfo(const char* strIpAddr, char* armVersion, char* fpgaVersion);

//获取图片的任意点温度
extern "C" ROBOTINSPECTION_API int LiveStream_GetPointTemperatureFromPicture(const char* filename, int x, int y, float* pointT);

//获取图片全图温度矩阵
extern "C" ROBOTINSPECTION_API int LiveStream_GetGlobalTemperatureFromPicture(const char* filename, float* imageT);

//获取图片区域的温度信息
extern "C" ROBOTINSPECTION_API int LiveStream_GetRectTemperatureFromPicture(const char* filename, int x, int y, int width, int height, POINT_INFO* maxInfo, POINT_INFO* minInfo, float* avgT);

//添加分析对象
extern "C" ROBOTINSPECTION_API int LiveStream_AddRectAnalyser(const char* strIpAddr, int x, int y, int width, int height, int type);

//删除分析对象
extern "C" ROBOTINSPECTION_API int LiveStream_DeleteRectAnalyser(const char* strIpAddr);

//切换分析对象温度显示模式
extern "C" ROBOTINSPECTION_API int LiveStream_ChangeAnalyserTemperatureShowType(const char* strIpAddr, int type);

//开启叠加字符功能
extern "C" ROBOTINSPECTION_API int LiveStream_EnableAddStringToStream(const char* strIpAddr);

//图像叠加字符串
extern "C" ROBOTINSPECTION_API int LiveStream_AddStringToStream(const char* strIpAddr, int x, int y, const char* content);

//关闭叠加字符功能
extern "C" ROBOTINSPECTION_API int LiveStream_DisableAddStringToStream(const char* strIpAddr);

//获取机器设备号
extern "C" ROBOTINSPECTION_API int LiveStream_GetDeviceSerialNumber(const char* strIpAddr, char* serialNum);

//获取SDK版本信息
extern "C" ROBOTINSPECTION_API int LiveStream_GetSDKVersion(char* sdkVersion);

//获取报警温度
extern "C" ROBOTINSPECTION_API int LiveStream_GetAlarmTemp(const char* strIpAddr, int* temp);

//设置报警温度
extern "C" ROBOTINSPECTION_API int LiveStream_SetAlarmTemp(const char* strIpAddr, int temp);

//取消报警温度
extern "C" ROBOTINSPECTION_API int LiveStream_CancleAlarmTemp(const char* strIpAddr);

//设置设备当前日期 
extern "C" ROBOTINSPECTION_API int LiveStream_SetCurrentDate(const char* strIpAddr, const char* date);

//设置设备当前时间
extern "C" ROBOTINSPECTION_API int LiveStream_SetCurrentTime(const char* strIpAddr, const char* time);

//设置Y16帧频
extern "C" ROBOTINSPECTION_API int LiveStream_SetFrameFrequency(const char* strIpAddr, int fps);

//获取上次错误
extern "C" ROBOTINSPECTION_API int LiveStream_GetLastError();

