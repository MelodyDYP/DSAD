#include "xBuffer.h"

#ifndef xQUEUE_H
#define xQUEUE_H

template <typename T>
class xQueue {
public:
	xQueue();
	~xQueue();
	T& front();
	const T& front() const;
	void push(const T& item);
	void pop();
	size_t size() const;
	bool empty() const;
private:
	void MapReserve(size_t n);			// Ϊӳ�仺���������ռ�
	static const int blockSize = 16;	// ���ݿ鳤��
	xBuffer<xBuffer<T>*> qMap;		// �����ݿ�ָ���γɵĶ���
	size_t qCount;						// ������ʵ��Ԫ�ظ���
};

// ���캯����ʵ��
template <typename T>
xQueue<T>::xQueue()
	: qMap(blockSize * blockSize), qCount(0)
{
	// ��ʼ��Ϊ�����ݿ�
	for (size_t i = 0; i < qMap.capacity(); i++)
		qMap.buffer[i] = NULL;
}

// ����������ʵ��
template <typename T>
xQueue<T>::~xQueue()
{
	// �ͷ��������ݿ�
	for (size_t i = 0; i < qMap.capacity(); i++)
		delete qMap.buffer[i];
}

// ���ض���
template <typename T>
T& xQueue<T>::front()
{
	return qMap.front()->front();
}

// ���ض��׵ĳ����汾
template <typename T>
const T& xQueue<T>::front() const
{
	return qMap.front()->front();
}

template <typename T>
void xQueue<T>::MapReserve(size_t n)
{
	// n�������Ŀǰ������������
	size_t pos = qMap.capacity();	// ��¼ԭ������
	qMap.buffer.resize(n);
	size_t i;
	for (i = pos; i < qMap.capacity(); i++)
		qMap.buffer[i] = NULL;		// ���䲻ָ�����ݿ�
	// ע����Ҫ��������������
	if (qMap.count > 0 && qMap.bFront > qMap.bRear)
	{
		// ������ʱ��ӳ�仺�����������°����Ա�֤ѭ�������ϵ�����
		for (i = 0; i <= qMap.bRear; i++)
		{
			qMap.buffer[pos] = qMap.buffer[i];		// �ƶ����ݿ�ָ��
			qMap.buffer[i] = NULL;					// ԭ��λ�ò�ָ�����ݿ�
			pos = (pos + 1) % qMap.capacity();
		}
		qMap.bRear = (pos + qMap.capacity() - 1) % qMap.capacity();
	}
}

// ��Ӳ���
template <typename T>
void xQueue<T>::push(const T& item)
{
	// �������������ݿ�����, Ӧ����ӳ�仺��������
	if (qCount == qMap.capacity() * blockSize)
		MapReserve(2 * qMap.size());	// �ӱ�
	// ������Ҫ�������ݿ�����, ע�ⲻ��ֱ�Ӷ�qMapʹ��push����.
	// ���������κ�Ԫ�ػ��β���ݿ�������Ӧ����, �ж����ʹ�ö�·��ֵ.
	if (qCount == 0 || qMap.buffer[qMap.bRear]->full())
	{
		// ���ݿ�λ��ѭ������һ��
		qMap.bRear = (qMap.bRear + 1) % qMap.capacity();
		// ���ݿ��������
		qMap.count++;
	}
	// ���ݿ�Ϊ��, ��Ϊ�����洢�ռ�. 
	if (qMap.buffer[qMap.bRear] == NULL)
		qMap.buffer[qMap.bRear] = new xBuffer<T>(blockSize);
	qMap.buffer[qMap.bRear]->push(item);
	qCount++;
}

// ���Ӳ���
template <typename T>
void xQueue<T>::pop()
{
	qMap.front()->pop();
	// ���������ݿ�����������, Ӧ�������, ע��ʵ��ָ�����Ӧ���ݿ�����.
	if (qMap.front()->empty())
		qMap.pop();	// �˴��������б�д���Ӳ���
	qCount--;
}

// ���ض���ʵ��Ԫ�ظ���
template <typename T>
size_t xQueue<T>::size() const
{
	return qCount;
}

// �ж϶����Ƿ�Ϊ��
template <typename T>
bool xQueue<T>::empty() const
{
	return (qCount == 0);
}

#endif  // xQUEUE_H
