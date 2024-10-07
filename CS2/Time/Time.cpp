#include "Time.h"
//����
void PauseMs(int milliseconds){
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
//΢��
void PauseUs(int microseconds) {
	std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
}
//��ȡ��ǰʱ��
std::chrono::steady_clock::time_point NowTime() {
	return std::chrono::high_resolution_clock::now();
}
//��ʱ��΢���
std::chrono::microseconds DuringTimeUs(std::chrono::steady_clock::time_point Start, std::chrono::steady_clock::time_point End) {
	return std::chrono::duration_cast<std::chrono::microseconds>(End - Start);
}