#include <deque>

#ifndef xSTACK_H
#define xSTACK_H

// Ĭ���ڲ�ʹ��deque��Ϊ�洢
template <typename T, typename Sequence = std::deque<T>>
class xStack {
public:
	// ��������Sequence::const_iterator��ΪǶ������
	// ʹ��xStack<T>::const_iteratorʵΪSequence::const_iterator
	typedef typename Sequence::const_iterator const_iterator;
	xStack();
	T& top();
	const T& top() const;
	void push(const T& item);
	void pop();
	size_t size() const;
	bool empty() const;
	const_iterator begin() const;
	const_iterator end() const;
private:
	Sequence c;
};

// ���캯����ʵ��
template <typename T, typename Sequence>
xStack<T, Sequence>::xStack()
{
}

// ����ջ��Ԫ��
template <typename T, typename Sequence>
T& xStack<T, Sequence>::top()
{
	return c.back();
}

// ����ջ��Ԫ�صĳ����汾
template <typename T, typename Sequence>
const T& xStack<T, Sequence>::top() const
{
	return c.back();
}

// ����Ԫ����ջ
template <typename T, typename Sequence>
void xStack<T, Sequence>::push(const T& item)
{
	c.push_back(item);
}

// ջ��Ԫ�س�ջ
template <typename T, typename Sequence>
void xStack<T, Sequence>::pop()
{
	c.pop_back();
}

// ����ջ�Ĵ�С
template <typename T, typename Sequence>
size_t xStack<T, Sequence>::size() const
{
	return c.size();
}

// �ж�ջ�Ƿ�Ϊ��
template <typename T, typename Sequence>
bool xStack<T, Sequence>::empty() const
{
	return (c.size() == 0);
}

template <typename T, typename Sequence>
inline typename xStack<T, Sequence>::const_iterator
	xStack<T, Sequence>::begin() const
{
	return c.begin();
}

template <typename T, typename Sequence>
inline typename xStack<T, Sequence>::const_iterator
	xStack<T, Sequence>::end() const
{
	return c.end();
}

#endif  // xSTACK_H
