#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "../KeyBoard/VK_Value.h"

#define ͷ�� 0x01
#define ���� 0x02
#define �ظ� 0x03
#define �ɲ� 0x04
#define �Ȳ� 0x05
#define �Ų� 0x06

namespace AutoAim{

    enum class AllBodyPart :unsigned int{ 
        HEAD = ͷ��, NECK = ����, CHEST = �ظ�, CROTCH = �ɲ�, LEGS = �Ȳ�, FEET = �Ų� 
    };

    struct AutoAim
    {
        int HotKey;
        int Range;
        AllBodyPart BodyPart;
        float RotationAngle;
        AutoAim() {
            this->HotKey = ����Ҽ�;
            this->Range = 30;
            this->BodyPart = AllBodyPart::HEAD;
            this->RotationAngle = 363.65;
        }
    };

    AutoAim AutoAimSetting;

    std::string GetBracketedString(const std::string& line) {
        std::string str1 = "";
        std::regex bracketRegex("\\[.*?\\]");
        if (std::regex_search(line, bracketRegex)) {
            size_t index1 = line.find('[');
            size_t index2 = line.find(']');
            str1 = line.substr(index1 + 1, index2 - 1);
        };
        return str1;
    };

    std::string removeSpaces(const std::string& str) {
        std::string result;
        for (size_t i = 0; i < str.length(); ) {
            if (str[i] != ' ') {
                result += str[i];
                i++;
            }
            else {
                i++;
            }
        }
        return result;
    }
    void GetUserInI(AutoAim &AutoAimSetting) {

        std::ifstream inputFile("Setting.ini");

        if (!inputFile.is_open()) {
            return;
        }

        std::string line; BOOL �Ƿ����ýڵ�ͷ = 0; std::string �Ⱥ����; std::string �Ⱥ��ұ�; size_t equals_pos; std::string �� = ""; std::string ֵ = "";

        while (std::getline(inputFile, line)) {

            if (GetBracketedString(line) == "����") { �Ƿ����ýڵ�ͷ = TRUE; continue; }
            else if (GetBracketedString(line) == "END") { �Ƿ����ýڵ�ͷ = FALSE; };

            if (!�Ƿ����ýڵ�ͷ) { continue; };

            equals_pos = line.find('=');

            if (equals_pos != std::string::npos) {

                �Ⱥ���� = line.substr(0, equals_pos);
                �Ⱥ��ұ� = line.substr(equals_pos + 1, line.length());
                �� = removeSpaces(�Ⱥ����);
                ֵ = removeSpaces(�Ⱥ��ұ�);
            }
            else { �� = ""; ֵ = ""; continue; };

            if (�� == "" || ֵ == "") { continue; };

            if (�� == "�����") {
                if (ֵ == "�������ȼ�") { AutoAimSetting.HotKey = �������ȼ�; }
                else if (ֵ == "������") { AutoAimSetting.HotKey = ������; }
                else if (ֵ == "����Ҽ�") { AutoAimSetting.HotKey = ����Ҽ�; }
                else if (ֵ == "X1��갴ť") { AutoAimSetting.HotKey = X1��갴ť; }
                else if (ֵ == "X2��갴ť") { AutoAimSetting.HotKey = X2��갴ť; }
                else if (ֵ == "BACKSPACE��") { AutoAimSetting.HotKey = BACKSPACE��; }
                else if (ֵ == "Tab��") { AutoAimSetting.HotKey = Tab��; }
                else if (ֵ == "SHIFT��") { AutoAimSetting.HotKey = SHIFT��; }
                else if (ֵ == "CTRL��") { AutoAimSetting.HotKey = CTRL��; }
                else if (ֵ == "Alt��") { AutoAimSetting.HotKey = Alt��; }
                else if (ֵ == "CAPSLOCK��") { AutoAimSetting.HotKey = CAPSLOCK��; }
                else if (ֵ == "Q��") { AutoAimSetting.HotKey = Q��; }
                else if (ֵ == "E��") { AutoAimSetting.HotKey = E��; }
                else if (ֵ == "F��") { AutoAimSetting.HotKey = F��; }
                else if (ֵ == "�ո��") { AutoAimSetting.HotKey = �ո��; }
                else { AutoAimSetting.HotKey = ����Ҽ�; };
            };

            if (�� == "���鲿λ") {
                if (ֵ == "�����鲿λ") { AutoAimSetting.BodyPart = AllBodyPart::CHEST; }
                else if (ֵ == "ͷ��") { AutoAimSetting.BodyPart = AllBodyPart::HEAD; }
                else if (ֵ == "����") { AutoAimSetting.BodyPart = AllBodyPart::NECK; }
                else if (ֵ == "�ظ�") { AutoAimSetting.BodyPart = AllBodyPart::CHEST; }
                else if (ֵ == "�ɲ�") { AutoAimSetting.BodyPart = AllBodyPart::CROTCH; }
                else if (ֵ == "�Ȳ�") { AutoAimSetting.BodyPart = AllBodyPart::LEGS; }
                else if (ֵ == "�Ų�") { AutoAimSetting.BodyPart = AllBodyPart::FEET; }
                else { AutoAimSetting.BodyPart = AllBodyPart::CHEST; };
            };

            if (�� == "΢���鷶Χ") {
                float ΢���鷶Χ;
                try {
                    ΢���鷶Χ = std::stof(ֵ);
                    AutoAimSetting.Range = ΢���鷶Χ;
                }
                catch (const std::invalid_argument& e) {
                    MessageBoxA(0, "���鷶Χ���ֲ����Ϲ淶", "��������", 0);
                    AutoAimSetting.Range = 10;
                }
                catch (const std::out_of_range& e) {
                    MessageBoxA(0, "���鷶Χ���ֳ�������", "��������", 0);
                    AutoAimSetting.Range = 10;
                }
            }

            if (�� == "������ת��") {
                float ������ת��;
                try {
                    ������ת�� = std::stof(ֵ);
                    AutoAimSetting.RotationAngle = ������ת��;
                }
                catch (const std::invalid_argument& e) {
                    MessageBoxA(0, "������ת�����ֲ����Ϲ淶", "��������", 0);
                    AutoAimSetting.RotationAngle = 45;
                }
                catch (const std::out_of_range& e) {
                    MessageBoxA(0, "������ת�����ֳ�������", "��������", 0);
                    AutoAimSetting.RotationAngle = 45;
                }
            }
        };

        inputFile.close();

        return;
    };
}
