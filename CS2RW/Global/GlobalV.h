#pragma once
#include <Windows.h>
//�汾��Ϣ
BOOL isCurrentVersionAvailable = TRUE;
//��Ϸ������Ϣ
struct 
{
	DWORD GamePid = 0;
	HANDLE GameProcess = 0;
	char GameFile[MAX_PATH] = "Hello, CS2!";
	HWND g_HWND = 0;
	HINSTANCE g_HINSTANCE = 0;

}GameProcessInfo;
//��Ϸģ���ַ
struct
{
	HMODULE ClientModuleAddress = 0;
	HMODULE Engine2ModuleAddress = 0;
	HMODULE MatchmakingModuleAddress = 0;
	HMODULE ServerModuleAddress = 0;
	HMODULE SDL3ModuleAddress = 0; 
	HMODULE SteamaudioModuleAddress = 0;

}ModuleInfo;
//���ܿ���
struct SFeatureFlags
{
	BOOL ESP_Flag = 0;//͸��
	BOOL ReportPosition_Flag = 0;//����
	BOOL AimBot_Flag = 0;//����

}FeatureFlags;
//�����Ϣ

//�Ծ���Ϣ

//����ʱ��
BOOL AimBotTime = FALSE;
