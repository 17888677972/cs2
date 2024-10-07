#pragma once
#include <Windows.h>
#include <fstream>
#include <string>

struct Version {
	std::string VersionDate="Oct 06 2024";
	std::string VersionTime="13:42:25";
}IniVersion;

BOOL VersionCheckFun() {
	GetModuleFileNameExA(GameProcessInfo.GameProcess, NULL, GameProcessInfo.GameFile, MAX_PATH);
	std::string GameFiles(GameProcessInfo.GameFile);
	size_t index = GameFiles.find("game");
	std::string InfFile = GameFiles.substr(0, index) + "game\\csgo\\steam.inf";
	std::ifstream inputFile(InfFile);
	if (!inputFile.is_open()) {
		MessageBoxA(0,"�Ҳ��������ļ����޷�ȷ���汾��Ϣ��\n����δ֪��Ϊ�𻵴��̣��������������̣�", "һ������", 0);
		return FALSE;
	}
	std::string line; 
	BOOL �Ƿ����ýڵ�ͷ = 0; size_t equals_pos; std::string Key = ""; std::string Value = "";
	while (std::getline(inputFile, line)) {
		equals_pos = line.find('=');
		if (equals_pos != std::string::npos) { Key = line.substr(0, equals_pos); Value = line.substr(equals_pos + 1, line.length());}else { Key = ""; Value = ""; continue; }; if (Key == "" || Value == "") { continue; };
		if (Key == "VersionDate"&& Value!= IniVersion.VersionDate) {
			inputFile.close();
			return FALSE;
		}
		else if (Key == "VersionTime" && Value != IniVersion.VersionTime) {
			inputFile.close();
			return FALSE;
		}
	};
	inputFile.close();
	return TRUE;
}