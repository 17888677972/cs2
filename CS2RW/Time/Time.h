//����ʱ��Ŀ�
#pragma once
#include <thread>
#include <chrono>
//����
void PauseMs(int milliseconds); 
//΢��
void PauseUs(int microseconds);

std::chrono::steady_clock::time_point NowTime();

std::chrono::microseconds DuringTimeUs(std::chrono::steady_clock::time_point Start, std::chrono::steady_clock::time_point End);