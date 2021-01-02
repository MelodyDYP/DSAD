#include <vector>

#ifndef xBUFFER_H
#define xBUFFER_H

template <typename T>
class xBuffer {
public:
	// ������Ԫģ����xQueue, ע����÷ǰ���ʽ
	template <typename U>
		friend class xQueue;
	xBuffer(size_t n);
	T& front();
	const T& front() const;
	void push(const T& item);
	void pop();
	size_t size() const;
	bool empty() const;
	bool full() const;
	size_t capacity() const;
private:
	std::vector<T> buffer;
	size_t count;
	size_t bFront;
	size_t bRear;
};

// ���캯����ʵ��
template <typename T>
xBuffer<T>::xBuffer(size_t n)
	: buffer(n), count(0), bFront(0), bRear(n - 1)
{
}

// ���ض���
template <typename T>
T& xBuffer<T>::front()
{
	return buffer[bFront];
}

// ���ض��׵ĳ����汾
template <typename T>
const T& xBuffer<T>::front() const
{
	return buffer[bFront];
}

// ��Ӳ���
template <typename T>
void xBuffer<T>::push(const T& item)
{
	// ���û��ж��Ƿ񻺳�������, �˴�ֻʵ�����
	bRear = (bRear + 1) % buffer.size();
	buffer[bRear] = item;
	count++;
}

// ���Ӳ���
template <typename T>
void xBuffer<T>::pop()
{
	bFront = (bFront + 1) % buffer.size();
	count--;
}

// ���ػ�����ʵ��Ԫ�ظ���
template <typename T>
size_t xBuffer<T>::size() const
{
	return count;
}

// �жϻ������Ƿ�Ϊ��
template <typename T>
bool xBuffer<T>::empty() const
{
	return (count == 0);
}

// �жϻ������Ƿ�����
template <typename T>
bool xBuffer<T>::full() const
{
	return (count == buffer.size());
}

// ���ػ������������
template <typename T>
size_t xBuffer<T>::capacity() const
{
	return buffer.size();
}

#endif  // xBUFFER_H
