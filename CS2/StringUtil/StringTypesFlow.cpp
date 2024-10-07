#include "StringTypesFlow.h"
#include <cstring>
std::wstring TakeN_DecimalPlaces(std::wstring& wstr, int n) {
    size_t dotIndex = wstr.find('.');
    if (dotIndex != std::string::npos) {
        wstr = wstr.substr(0, dotIndex + 1+n); 
        return wstr;
    }
    return wstr;
}


std::wstring string2wstring(std::string &str)
{
    std::wstring result;
    //��ȡ��������С��������ռ䣬��������С���ַ�����  
    int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
    TCHAR* buffer = new TCHAR[len + 1];
    //���ֽڱ���ת���ɿ��ֽڱ���  
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
    buffer[len] = '\0';             //����ַ�����β  
    //ɾ��������������ֵ  
    result.append(buffer);
    delete[] buffer;
    return result;
}


unsigned long string2DWORD(std::string& str) {
    try {
        unsigned long dw = std::stoi(str);     
    }
    catch (const std::invalid_argument& e) {
        int length = strlen(e.what()); 
        std::string str(e.what(), length); 
        const wchar_t *b = string2wstring(str).c_str();
        MessageBoxW(0, b, L"����", MB_ICONWARNING);
    }
    catch (const std::out_of_range& e) {
        int length = strlen(e.what());
        std::string str(e.what(), length);
        const wchar_t* b = string2wstring(str).c_str();
        MessageBoxW(0, b, L"����", MB_ICONWARNING);
    }
    return 404;
};

std::string LPCWSTR2string(LPCWSTR lpcwszStr)
{
    std::string str;
    DWORD dwMinSize = 0;
    LPSTR lpszStr = NULL;
    dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, NULL, 0, NULL, FALSE);
    if (0 == dwMinSize)
    {
        return FALSE;
    }
    lpszStr = new char[dwMinSize];
    WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, lpszStr, dwMinSize, NULL, FALSE);
    str = lpszStr;
    delete[] lpszStr;
    return str;
}
std::string LPWSTR2string(LPWSTR lpcwszStr)
{
    std::string str;
    DWORD dwMinSize = 0;
    LPSTR lpszStr = NULL;
    dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, NULL, 0, NULL, FALSE);
    if (0 == dwMinSize)
    {
        return FALSE;
    }
    lpszStr = new char[dwMinSize];
    WideCharToMultiByte(CP_OEMCP, NULL, lpcwszStr, -1, lpszStr, dwMinSize, NULL, FALSE);
    str = lpszStr;
    delete[] lpszStr;
    return str;
}

