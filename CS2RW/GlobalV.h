#pragma once
#include <Windows.h>
//ȫ�ִ��ھ��
HWND g_HWND = 0;
//ģ���ַ
HMODULE ClientModuleAddress = 0;
HMODULE Engine2ModuleAddress = 0;
HMODULE MatchmakingModuleAddress = 0;
HMODULE ServerModuleAddress = 0;
HMODULE SDL3ModuleAddress = 0;
//�汾��Ϣ
BOOL VersionCheck = 1;
//��ȡCS2.exe���̾��
DWORD GamePid = 0;
HANDLE GameProcess = 0;
char GameFile[MAX_PATH] = "Hello, CS2!";
//�ҵ���Ϣ
LPVOID Localplayer_Address;