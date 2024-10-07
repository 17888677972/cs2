#pragma once 
#include <windows.h>  // Windows API
#include <iostream>
#include <thread>
#include <chrono>     // ��������֮���ʱ����

// ���Ź��ܿ�����ʾ�� (����, ģ��һ��������ʾ��)
void playEnableSound() {
    // ʹ��������Ƶ����ģ�⡰���ˡ�
    Beep(1200, 150); // 1200 Hz, 150ms (��)
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // ���
    Beep(1400, 150); // 1400 Hz, 150ms (��)
}

// ���Ź��ܹر���ʾ�� (����, ģ��һ�ֵͳ�����ʾ��)
void playDisableSound() {
    // ʹ�������ϵ�Ƶ������ģ�⡰���ˡ�
    Beep(900, 200); // 900 Hz, 200ms (��)
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // ���
    Beep(700, 200); // 700 Hz, 200ms (��)
}

void genTone(STone& Tone) {
	Beep(Tone.frequency, Tone.duration);
};