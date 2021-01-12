#ifndef TIMER_CLASS
#define TIMER_CLASS

#include <ctime>

class xTimer {
private:
	std::clock_t startTime;
	std::clock_t endTime;
public:
	xTimer();
	void start();
	void stop();
	double time() const;
};

// ����xTimer��ʵ�ֶ�ʹ����inline��ʽ.

inline xTimer::xTimer()
	: startTime(0), endTime(0)
{}

// ��ʱ��ʼ.
inline void xTimer::start()
{
	startTime = std::clock();
}

// ��ʱ����.
inline void xTimer::stop()
{
	endTime = std::clock();
}

// ���ؼ�ʱʱ��.
inline double xTimer::time() const
{
	return static_cast<double>(endTime - startTime)
		/ static_cast<double>(CLOCKS_PER_SEC);
	// ע��ת������double�ͣ�������ܶ�Ӧ���������ĳ������, ��������.
	// һ��CLOCKS_PER_SECΪ����1000.
}

#endif // TIMER_CLASS
