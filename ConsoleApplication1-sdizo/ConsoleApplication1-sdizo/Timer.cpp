#include "Header.h"


void Timer::startTimerT()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Error!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counter = li.QuadPart;
}
void Timer::getTimeT()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operation took: " << (li.QuadPart - counter) / PCFreq << " miliseconds \n";

}
