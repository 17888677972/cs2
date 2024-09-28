#include <Windows.h>
#include <iostream>
#include <CommCtrl.h>
#include "StringUtil/StringTypesFlow.h"
#include "Define/Definition.h"
#include "AutoAim/AutoAimSetting.h"
#include "AutoAim/AutoAimTarget.h"
#include "resource.h"
#include "Player/GetAngle.h"
#include "Player/GetPlayerList.h"
#include "StringUtil/RandomClan.h"
#include "Window/GetProcessPidByName.h"
#include "Time/Time.h"
#include "Window/GetModule.h"
#include "GameInfo/GetGameStatus.h"
#include "Player/GetDistance.h"
#include "Player/GetPosition.h"
#include "GameInfo/GameSystemSetting.h"
#include "Window/GetFocWinTitle.h"
#include "Player/InsAssemble.h"
#include "Window/VersionCheck.h"
#include "Main.h"

LRESULT CALLBACK Wndproc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	g_HWND = hwnd;

	static HINSTANCE hInstance = GetModuleHandleW(NULL);

	switch (uMsg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		// ���ú�ɫ����
		SetTextColor(hdc, RGB(255, 255, 255));

		// �������ֱ���͸��
		SetBkMode(hdc, TRANSPARENT);

		// ��������
		DrawText(hdc, L"1.0.0.01", -1, &ps.rcPaint, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

		EndPaint(hwnd, &ps);

		break;
	}
	case 999: {
		MessageBoxW(0, L"�Զ�����Ϣ", L"��ʾ", 0);
		break;
	}
	case WM_CREATE: {

		TestGameEnvironment_Button_hwnd = CreateWindowW(WC_BUTTON, L"������", WS_CHILD | WS_VISIBLE | WS_BORDER, 900, 680, 100, 40, hwnd, (HMENU)0x404, hInstance, 0);
		//MessageBoxW(0, L"�Ѻ���ȫ�ֹ���", L"��ʾ", 0);
		break;
	}
	case WM_COPYDATA: {
		//ȫ�ֹ���
		PCOPYDATASTRUCT pCopyData = (PCOPYDATASTRUCT)lParam;
		MessageBoxW(0, (LPCWSTR)pCopyData->lpData,0,0);
		break;
	}
	case WM_COMMAND: {
		DWORD ControlId = DWORD(wParam);
		if (ControlId == 0x404) {
			MessageBoxW(hwnd, L"ƫ����ʧЧ����ţ�0x404������ϵ����Ա���£�����", L"����", MB_OK| MB_ICONHAND);
			SendMessageW(hwnd, WM_CLOSE, 0, 0);
		}
		else if (ControlId == 0x666) {
			SendMessageW(hwnd, WM_CLOSE, 0, 0);
		}
		break;
	}

	case WM_KEYUP: {

		switch (wParam)
		{
		case VK_HOME: {
			int Result_MessageBoxW_01 = MessageBoxW(0, L"���ּ�ΪС���̡�\n������ģʽ��				\n\n	��׼����\n		���ּ�1���з������ּ�2���Ѿ������ּ�3��ȫ����\n	��׼��ʽ��\n		���ּ�6��΢���飬�ʺϾ���ģʽ��������׼�Ľ���\n		�����ظ�Ϊ����һ���뾶Ϊ10���׵�Բ��\n\n		���ּ�7��ǿ�����ʺ������������������������\n\n		���ּ�8(��ʱʧЧ)����ǿ�����飬�ʺϣ����¾�����\n\n		��׼�ľ��������ض�����", L"ʹ��˵��", MB_YESNO | MB_ICONASTERISK);
			break;
		}
		case VK_DELETE: {
			SendMessageW(hwnd, WM_COMMAND, 0x666, 0);
			break;
		}
		case VK_INSERT: {
			//�������Ƿ����
			PauseMs(100);
			if (GameStatus) {
				ReportPositionWidth = 350;
				ReportPositionHeight = 240;
				SetWindowPos(hwnd, NULL, 0, 0, ReportPositionWidth, ReportPositionHeight, SWP_NOZORDER | SWP_NOMOVE);
				MessageBoxW(hwnd, L"��ǰ״̬��ע��ɹ�", L"��ʾ", MB_APPLMODAL);
				AutoAim_Button_Switch = FALSE;
				ReportPosition_Button_Switch = FALSE;
			}
			else {
				MessageBoxW(hwnd, L"δ��⵽����cs2.exe", L"����", MB_APPLMODAL);
			}
			break;
		}
		case VK_F1: {
			if (ReportPosition_Button_Switch == FALSE) {
				if (GameStatusInfoS.MapStatus != 0) {
					MessageBoxA(0, "A", "A", 0);
					ReportPosition_Button_Switch = TRUE;
					//SetDlgItemTextW(hwnd, 0x2000, L"����(����)");

					Enemy01_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����1", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 0, 60, 40, hwnd, (HMENU)0x2101, hInstance, 0);
					Enemy02_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����2", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 50, 60, 40, hwnd, (HMENU)0x2102, hInstance, 0);
					Enemy03_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����3", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 100, 60, 40, hwnd, (HMENU)0x2103, hInstance, 0);
					Enemy04_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����4", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 150, 60, 40, hwnd, (HMENU)0x2104, hInstance, 0);
					Enemy05_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����5", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 200, 60, 40, hwnd, (HMENU)0x2105, hInstance, 0);
					Enemy06_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����6", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 250, 60, 40, hwnd, (HMENU)0x2106, hInstance, 0);
					Enemy07_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����7", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 300, 60, 40, hwnd, (HMENU)0x2107, hInstance, 0);
					Enemy08_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����8", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 350, 60, 40, hwnd, (HMENU)0x2108, hInstance, 0);
					Enemy09_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����9", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 400, 60, 40, hwnd, (HMENU)0x2109, hInstance, 0);
					Enemy10_ID_Static_hwnd = CreateWindowW(WC_STATICW, L"����10", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 60, 450, 60, 40, hwnd, (HMENU)0x210A, hInstance, 0);

					Enemy01_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 0, 150, 40, hwnd, (HMENU)0x2301, hInstance, 0);
					Enemy02_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 50, 150, 40, hwnd, (HMENU)0x2302, hInstance, 0);
					Enemy03_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 100, 150, 40, hwnd, (HMENU)0x2303, hInstance, 0);
					Enemy04_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 150, 150, 40, hwnd, (HMENU)0x2304, hInstance, 0);
					Enemy05_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 200, 150, 40, hwnd, (HMENU)0x2305, hInstance, 0);
					Enemy06_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 250, 150, 40, hwnd, (HMENU)0x2306, hInstance, 0);
					Enemy07_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 300, 150, 40, hwnd, (HMENU)0x2307, hInstance, 0);
					Enemy08_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 350, 150, 40, hwnd, (HMENU)0x2308, hInstance, 0);
					Enemy09_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 400, 150, 40, hwnd, (HMENU)0x2309, hInstance, 0);
					Enemy10_Where_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 120, 450, 150, 40, hwnd, (HMENU)0x230A, hInstance, 0);


					Enemy01_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 0, 50, 40, hwnd, (HMENU)0x2201, hInstance, 0);
					Enemy02_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 50, 50, 40, hwnd, (HMENU)0x2202, hInstance, 0);
					Enemy03_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 100, 50, 40, hwnd, (HMENU)0x2203, hInstance, 0);
					Enemy04_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 150, 50, 40, hwnd, (HMENU)0x2204, hInstance, 0);
					Enemy05_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 200, 50, 40, hwnd, (HMENU)0x2205, hInstance, 0);
					Enemy06_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 250, 50, 40, hwnd, (HMENU)0x2206, hInstance, 0);
					Enemy07_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 300, 50, 40, hwnd, (HMENU)0x2207, hInstance, 0);
					Enemy08_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 350, 50, 40, hwnd, (HMENU)0x2208, hInstance, 0);
					Enemy09_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 400, 50, 40, hwnd, (HMENU)0x2209, hInstance, 0);
					Enemy10_HP_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 10, 450, 50, 40, hwnd, (HMENU)0x220A, hInstance, 0);

					Enemy01_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 0, 80, 40, hwnd, (HMENU)0x2401, hInstance, 0);
					Enemy02_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 50, 80, 40, hwnd, (HMENU)0x2402, hInstance, 0);
					Enemy03_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 100, 80, 40, hwnd, (HMENU)0x2403, hInstance, 0);
					Enemy04_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 150, 80, 40, hwnd, (HMENU)0x2404, hInstance, 0);
					Enemy05_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 200, 80, 40, hwnd, (HMENU)0x2405, hInstance, 0);
					Enemy06_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 250, 80, 40, hwnd, (HMENU)0x2406, hInstance, 0);
					Enemy07_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 300, 80, 40, hwnd, (HMENU)0x2407, hInstance, 0);
					Enemy08_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 350, 80, 40, hwnd, (HMENU)0x2408, hInstance, 0);
					Enemy09_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 400, 80, 40, hwnd, (HMENU)0x2409, hInstance, 0);
					Enemy10_Distance_Edit_hwnd = CreateWindowW(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT, 270, 450, 80, 40, hwnd, (HMENU)0x240A, hInstance, 0);


					ReportPositions_handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ReportPositions, 0, 0, 0); if (ReportPositions_handle != 0) { CloseHandle(ReportPositions_handle); };
				}
				else {
					MessageBoxW(hwnd, L"δ���뵽�Ծ���", L"����", MB_APPLMODAL);
				}
			}
			else {
				ReportPosition_Button_Switch = FALSE;
				//SetDlgItemTextW(hwnd, 0x2000, L"����(�ر�)");
				DestroyWindow(Enemy01_ID_Static_hwnd);
				DestroyWindow(Enemy02_ID_Static_hwnd);
				DestroyWindow(Enemy03_ID_Static_hwnd);
				DestroyWindow(Enemy04_ID_Static_hwnd);
				DestroyWindow(Enemy05_ID_Static_hwnd);
				DestroyWindow(Enemy06_ID_Static_hwnd);
				DestroyWindow(Enemy07_ID_Static_hwnd);
				DestroyWindow(Enemy08_ID_Static_hwnd);
				DestroyWindow(Enemy09_ID_Static_hwnd);
				DestroyWindow(Enemy10_ID_Static_hwnd);


				DestroyWindow(Enemy01_Where_Edit_hwnd);
				DestroyWindow(Enemy02_Where_Edit_hwnd);
				DestroyWindow(Enemy03_Where_Edit_hwnd);
				DestroyWindow(Enemy04_Where_Edit_hwnd);
				DestroyWindow(Enemy05_Where_Edit_hwnd);
				DestroyWindow(Enemy06_Where_Edit_hwnd);
				DestroyWindow(Enemy07_Where_Edit_hwnd);
				DestroyWindow(Enemy08_Where_Edit_hwnd);
				DestroyWindow(Enemy09_Where_Edit_hwnd);
				DestroyWindow(Enemy10_Where_Edit_hwnd);

				DestroyWindow(Enemy01_HP_Edit_hwnd);
				DestroyWindow(Enemy02_HP_Edit_hwnd);
				DestroyWindow(Enemy03_HP_Edit_hwnd);
				DestroyWindow(Enemy04_HP_Edit_hwnd);
				DestroyWindow(Enemy05_HP_Edit_hwnd);
				DestroyWindow(Enemy06_HP_Edit_hwnd);
				DestroyWindow(Enemy07_HP_Edit_hwnd);
				DestroyWindow(Enemy08_HP_Edit_hwnd);
				DestroyWindow(Enemy09_HP_Edit_hwnd);
				DestroyWindow(Enemy10_HP_Edit_hwnd);

				DestroyWindow(Enemy01_Distance_Edit_hwnd);
				DestroyWindow(Enemy02_Distance_Edit_hwnd);
				DestroyWindow(Enemy03_Distance_Edit_hwnd);
				DestroyWindow(Enemy04_Distance_Edit_hwnd);
				DestroyWindow(Enemy05_Distance_Edit_hwnd);
				DestroyWindow(Enemy06_Distance_Edit_hwnd);
				DestroyWindow(Enemy07_Distance_Edit_hwnd);
				DestroyWindow(Enemy08_Distance_Edit_hwnd);
				DestroyWindow(Enemy09_Distance_Edit_hwnd);
				DestroyWindow(Enemy10_Distance_Edit_hwnd);
			}
			break;
		}
		case VK_F2: {
			if (AutoAim_Button_Switch == FALSE) {
				if (GameStatusInfoS.MapStatus != 0)
				{
					AutoAim::AutoAimSetting= AutoAim::GetUserInI(AutoAim::AutoAimSetting);
					AutoAim_Button_Switch = TRUE;
					SetDlgItemTextW(hwnd, 0x1000, L"����(����)");
					Auto_Aim_handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Auto_Aim, 0, 0, 0); if (Auto_Aim_handle != 0) { CloseHandle(Auto_Aim_handle); };
				}
				else {
					MessageBoxW(hwnd, L"δ���뵽�Ծ���", L"����", MB_APPLMODAL);
				}


			}
			else {
				AutoAim_Button_Switch = FALSE;
				SetDlgItemTextW(hwnd, 0x1000, L"����(�ر�)");
				MessageBoxW(hwnd, L"�Ѿ��ر�����", L"��ʾ", MB_APPLMODAL);

			}
			break;
		}
		
		case VK_F3: {
			if (POP) {
				POP = 0;
				Show_Xray(ClientModuleAddress,GameProcess);
			}
			else {
				POP = 1;
				UnShow_Xray(ClientModuleAddress, GameProcess);
			}
			break;
		}
		case VK_F4: {
			if (temp) {
				temp = 0;
			}
			else {
				temp = 1;
				
			}
			break;
		}
		case VK_NUMPAD1: {
			Auto_Aim_Object = AimAtTheEnemy;
			MessageBoxW(0, L"���󣺵з�", L"��ʾ", MB_OK);
			break;
		}
		case VK_NUMPAD2: {
			Auto_Aim_Object = AimAtTheAlly;
			MessageBoxW(0, L"�����Ѿ�", L"��ʾ", MB_OK);
			break;
		}
		case VK_NUMPAD3: {
			Auto_Aim_Object = AimAtTheAll;
			MessageBoxW(0, L"����ȫ��", L"��ʾ", MB_OK);
			break;
		}
		case VK_NUMPAD6: {
			Auto_Aim_Model =AimByAngle;
			MessageBoxW(0, L"��ʽ��΢����", L"��ʾ", MB_OK);
			break;
		}
		case VK_NUMPAD7: {
			Auto_Aim_Model = AimByDistance;
			MessageBoxW(0, L"��ʽ��ǿ��", L"��ʾ", MB_OK);
			break;
		}
		case VK_NUMPAD8: {
			MessageBoxW(0, L"������", L"��ʾ", MB_OK);
			break;
		}
		case VK_NUMPAD9: {
			Auto_Aim_Object = ��װ����;
			MessageBoxW(0, L"��װ����", L"��ʾ", MB_OK);
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CLOSE: {
		int result = MessageBoxW(0, L"���ڼ����ر�", L"��ʾ", MB_OK);
		UnShow_Xray(ClientModuleAddress, GameProcess);
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		break;
	}

	}

	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
};



int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
){
	//���
	WNDCLASSW MainWndClass = { 0 };
	MainWndClass.lpszClassName = L"ReverseCsWnd";
	MainWndClass.lpfnWndProc = Wndproc;
	MainWndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);;
	MainWndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCEW(IDI_ICON1));

	//ע��
	RegisterClassW(&MainWndClass);


	int Result_MessageBoxW_01 = MessageBoxW(0, L"	��лʹ�ã�						\n	��Ins���ע��״̬�������ʾע��ɹ�����Լ������²�����\n	��F1��������ģʽ��\n	��F2�������顣\n	��F3����͸�ӡ�\n	��HOME����˵��\n\n	���'��'��ʼע�뼴��ʹ�ø���������", L"��ʾ", MB_YESNO | MB_ICONASTERISK); if (Result_MessageBoxW_01 == IDNO) { return 0; }



	GetExeStatus_handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GetExeStatus, 0, 0, &GetExeStatus_ThreadId);
	GetGameModelStatus_handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GetGameModelStatus, 0, 0, &GetGameModelStatus_ThreadId);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GetPlayerList, 0, 0, 0);

	//����
	HWND MyWindow = CreateWindowExW(
		WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TRANSPARENT,
		MainWndClass.lpszClassName,
		RandomWstring(NULL, RSS_CHINESE, 6, 32).c_str(),
		WS_POPUP,
		10, 400, 5, 5,
		NULL,
		NULL,
		hInstance,
		0
	);
	SetLayeredWindowAttributes(g_HWND, RGB(255, 255, 255), 128, LWA_ALPHA);
	//��ʾ
	ShowWindow(MyWindow, nShowCmd);

	UpdateWindow(g_HWND);

	SetWindowPos(g_HWND, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	//


	//SendMessageW(QHWND, WM_KEYUP,VK_F1,0);


	//��Ϣ����
	MSG msg = { 0 };
	while (GetMessageW(&msg, 0, 0, 0))
	{
		DispatchMessageW(&msg);
	};


	return 0;
};

//��ȡ��Ϸ����״̬
void WINAPI GetExeStatus() {
	while (1) {
		if (GetExeStatus_switch) {
			GamePid = GetProcessPidByName(L"cs2.exe");
			if (GamePid != 0) {
				GameStatus = TRUE;
				GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePid);
				if (GameProcess != 0) {
					GetModuleFileNameExA(GameProcess, NULL, GameFile, MAX_PATH);
					VersionCheck = VersionCheckFun(GameFile);
					ClientModuleAddress = GetModule(GameProcess, "client.dll");
					Engine2ModuleAddress = GetModule(GameProcess, "engine2.dll");
					MatchmakingModuleAddress = GetModule(GameProcess, "matchmaking.dll");
					ServerModuleAddress = GetModule(GameProcess, "server.dll");
					SDL3ModuleAddress = GetModule(GameProcess, "SDL3.dll");
					//if (MatchmakingModuleAddress != 0) {
					//	CurrentMap_Address = (LPVOID)(((long long)MatchmakingModuleAddress + MAP_MATCH_Frist_Offset_01));
					//}
					if (ClientModuleAddress != 0) {
						Localplayer_Address = (LPVOID)(((long long)ClientModuleAddress + PLAYER_MainVeiw_Offset));
					}
					FocWinTitle = GetFocWinTitle(); if (FocWinTitle == "���־�Ӣ��ȫ����"|| FocWinTitle == "Counter-Strike 2") { IFCS2FocalPoint = TRUE; }
					else { IFCS2FocalPoint = FALSE; };

				}
				else {
					if (ReportPosition_Button_Switch == TRUE) {
						SendMessageW(g_HWND, WM_COMMAND, 0x2000, 0);
					}
					if (AutoAim_Button_Switch == TRUE) {
						SendMessageW(g_HWND, WM_COMMAND, 0x1000, 0);
					}
					IFCS2FocalPoint = FALSE;
				}
			}
			else {
				GameStatus = FALSE;
				ReSetVariableValue();
				if (ReportPosition_Button_Switch) {
					SendMessageW(g_HWND,WM_KEYUP , VK_F1, 0);
				}
			}
		}
		PauseMs(2000);
	}
};
//��ȡ��ǰ�Ƿ������Ϸ״̬
void WINAPI GetGameModelStatus() {
	while (1) {
		if (GameStatus != FALSE && GameProcess != 0 && MatchmakingModuleAddress != 0) {
			if (!VersionCheck) {
				int result_off = MessageBoxW(0, L"��ǰ�汾�ѹ��ڣ�������", L"�汾����", MB_CANCELTRYCONTINUE | MB_ICONWARNING | MB_DEFBUTTON2);
				if (result_off != IDRETRY && result_off != IDTRYAGAIN) {
					SendMessageW(g_HWND, WM_COMMAND, 0x404, 0);
				}
			};
			GameStatusInfoS = GetBasicGameStatus(GameStatusInfoS, ClientModuleAddress, GameProcess);
			if (GameStatusInfoS.OffsetUseful==FALSE&& GameStatus == TRUE&& GameProcess != 0) {
				GameStatusInfoS = GetBasicGameStatus(GameStatusInfoS, ClientModuleAddress, GameProcess);		
			}
			GameStatusInfoS = IfGameScreen(GameStatusInfoS, SDL3ModuleAddress, GameProcess);
			GameStatusInfoS = GetRatioOfC2CT(GameStatusInfoS, ServerModuleAddress, GameProcess);
			if (GameStatusInfoS.InGameChess == FALSE && GameStatusInfoS.MapStatus == NULL) {
				if (ReportPosition_Button_Switch) {
					//SendMessageW(g_HWND, WM_KEYUP, VK_F1, 0);
				}
			}
		}
		else {
			if (ReportPosition_Button_Switch) {
				SendMessageW(g_HWND, WM_KEYUP, VK_F1, 0);
			}
		}
		PauseMs(500);
	}
};

//����ǽ�����Ϸ���ȡ�������
DWORD WINAPI GetPlayerList() {
	PauseMs(2000);
	while (1) {
		if (GameStatusInfoS.MapStatus != 0 && GameStatus != FALSE && GameStatusInfoS.InGameChess == TRUE) {
			Localplayer = GetLocalPlayer(Localplayer, Localplayer_Address, GameProcess);
			int AllPlayerNums = 0;
			if (GameStatusInfoS.CNum >= 6 || GameStatusInfoS.CTNum >= 6) {
				PeopleMultiple = 2;
			}
			else {
				PeopleMultiple = 1;
			}
			for (int i = 0; i < MaxNum_PeopleOnline; i++) {
				player = GetEveryPlayer(player, ClientModuleAddress, GameProcess, i);
				player.distance = GetDistance_3D_M_4(player.Head_x, Localplayer.Head_x, player.Head_y, Localplayer.Head_y, player.Head_z, Localplayer.Head_z);
				if (player.state == 512 && player.HP > 0 && player.HP <= 100) {
					if (player.distance > 0.2) {
						AllPlayerArray[AllPlayerNums] = player;
						AllPlayerNums++;
					};
				};
			};
			
			AllPlayerNum = AllPlayerNums;

			//Pause(1);
		}
		else {
			AllPlayerNum = 0;
			PauseMs(800);
		}
	}
};
//��ȡ�������б�Ϳ�ʼ����
std::string Iswhere; std::string WhereIAmDebug; int ENEMYLIVENUM = 0; int ENEMYNUM = 0; std::wstring wstr_distance;
DWORD WINAPI ReportPositions() {
	while (true)
	{
		if (!ReportPosition_Button_Switch) {
			PauseMs(20);
			if (!ReportPosition_Button_Switch) {
				SetWindowPos(g_HWND, NULL, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOMOVE);
				ExitThread(0);
			}
		}
		if (GameStatusInfoS.MapStatus != 0 && GameStatus == TRUE) {
			if (Localplayer.Camp == 2) {
				ENEMYNUM = GameStatusInfoS.CTNum;
			}
			else if (Localplayer.Camp == 3) {
				ENEMYNUM = GameStatusInfoS.CNum;
			}
			else {
				ENEMYNUM = 0;
			}
			ENEMYLIVENUM = 0;
			if (AllPlayerNum > 0) {
				for (int i = 0; i < AllPlayerNum; i++) {
					if (AllPlayerArray[i].Camp != Localplayer.Camp && AllPlayerArray[i].state == 512 && AllPlayerArray[i].HP > 0 && AllPlayerArray[i].HP <= 100) {
						Iswhere = GetWhere(GameStatusInfoS.MapStatus, AllPlayerArray[i].Head_x, AllPlayerArray[i].Head_y, AllPlayerArray[i].Foot_z);
						ENEMYLIVENUM++;
						wstr_distance = std::to_wstring(AllPlayerArray[i].distance);
						wstr_distance = TakeN_DecimalPlaces(wstr_distance, 4);

						SetDlgItemTextW(g_HWND, 0x2300 + ENEMYLIVENUM, string2wstring(Iswhere).c_str());
						SetDlgItemTextW(g_HWND, 0x2200 + ENEMYLIVENUM, std::to_wstring(AllPlayerArray[i].HP).c_str());
						SetDlgItemTextW(g_HWND, 0x2400 + ENEMYLIVENUM, wstr_distance.c_str());
						if (0) {
							WhereIAmDebug = GetWhere(GameStatusInfoS.MapStatus, Localplayer.Foot_x, Localplayer.Foot_y, Localplayer.Foot_z);
							SetDlgItemTextW(g_HWND, 0x2300, string2wstring(WhereIAmDebug).c_str());
						}
					}
				}
			}
			if (ENEMYLIVENUM == 0) {
				ReportPositionWidth = 0; ReportPositionHeight = 300;
			}
			else if (ENEMYLIVENUM > 0) {
				ReportPositionWidth = 350; ReportPositionHeight = 48 * ENEMYLIVENUM;
			}
			else {
				ReportPositionWidth = 350; ReportPositionHeight = 240;
			}
			//SetWindowPos(g_HWND, NULL, 0, 0, ReportPositionWidth, ReportPositionHeight, SWP_NOZORDER | SWP_NOMOVE);
			PauseMs(50);
		}
		else {
			PauseMs(2000);
		}
	};
};
//��ȡ�������б�Ϳ�ʼ���飬��Ҫ������˭��ֱ�Ӳ������з�����ô���һ���з��±�Ϊ���������һ��forѭ��֮�󣬵õ��±꣬��׼��
DWORD WINAPI Auto_Aim() {
	while (1) {
		StartTime = NowTime();
		pausetime = 1600;
		if (AllPlayerNum > 10) {
			pausetime = 6500;
		}
		double rateofspeed = double(DuringTime)*0.000004;
		//�رպ���
		if (!AutoAim_Button_Switch) { PauseMs(20); if (!AutoAim_Button_Switch) { ExitThread(0); } };
		//�ж���������
		if (GameStatus == FALSE || GameStatusInfoS.MapStatus == 0 || AllPlayerNum <= 0 || IFCS2FocalPoint == FALSE|| GameStatusInfoS.InGameScreen==FALSE ) { continue; };
		//if (AutoAimSetting.HotKey != �������ȼ�) { if (!(GetAsyncKeyState(AutoAimSetting.HotKey) & 0x8000)) { continue; }; };
		//�������黷�ڣ��������������ģʽ�ж�
		switch (Auto_Aim_Object) {
		case UNKNOWN: {
			PauseMs(800);
			break;
		}
		case AimAtTheEnemy: {
			switch (Auto_Aim_Model)
			{
			case AimByDistance: {
				PauseUs(pausetime);
				index_Player_LowestDistance_InMain = GetPlayer_LowestDistance(AllPlayerArray, AllPlayerNum, Localplayer, AimAtTheEnemy); if (index_Player_LowestDistance_InMain == -1) { PauseMs(800); continue; }
				if (AllPlayerArray[index_Player_LowestDistance_InMain].HP && AllPlayerArray[index_Player_LowestDistance_InMain].HP > 0 && AllPlayerArray[index_Player_LowestDistance_InMain].HP <= 100 && AllPlayerArray[index_Player_LowestDistance_InMain].state == 512) {

					
					
					AutoAim::UpAngleData(IniSelfVeiwAngleTarget,Localplayer.Angle_H, Localplayer.Angle_V, Localplayer.Head_x, Localplayer.Head_y, Localplayer.Head_z, IniTargetCoor.x, IniTargetCoor.y, IniTargetCoor.z);
					mouse_event(MOUSEEVENTF_MOVE, (IniSelfVeiwAngleTarget.HorizontalAngle) * (45.0 / GetMouseSenvitivity(GameProcess, ClientModuleAddress)), (IniSelfVeiwAngleTarget.VerticalAngle) * (45.0 / GetMouseSenvitivity(GameProcess, ClientModuleAddress)), 0, 0);
					
				}
				break;
			}
			default:
				PauseMs(800);
				break;
			};
			break;
		};
		
		default: {
			PauseMs(800);
			break;
		}	
		}
	};
	return 0;
};