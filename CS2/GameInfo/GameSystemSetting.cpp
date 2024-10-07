#include "GameSystemSetting.h"
#include "../Define/Definition.h"

//�õ���Ϸ�����е����������
LPVOID MouseSenvitivity_Frist_Address; long long MouseSenvitivity_Second_Address; float Senvitivity_Mouse;

float GetMouseSenvitivity(HANDLE hProcess, HMODULE ClientModuleAddress) {

	MouseSenvitivity_Frist_Address = (LPVOID)(((long long)ClientModuleAddress + Sensitivity_Mouse_Frist_Offset));

	ReadProcessMemory(hProcess, (void*)(MouseSenvitivity_Frist_Address), &MouseSenvitivity_Second_Address, 8, 0);

	ReadProcessMemory(hProcess, (void*)(MouseSenvitivity_Second_Address + Sensitivity_Mouse_Second_Offset), &Senvitivity_Mouse, 4, 0);

	return Senvitivity_Mouse;
};