// ����std::swap
#include <utility>

#ifndef xVECTOR_H
#define xVECTOR_H

template <typename T>
class xVector {
public:
	explicit xVector(size_t size = 0, const T& initVal = T());
	xVector(const xVector<T>& obj);
	~xVector();
	void swap(xVector<T>& rhs);
	xVector& operator= (const xVector<T>& rhs);
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	T& operator[] (size_t i);
	const T& operator[] (size_t i) const;
	void push_back(const T& item);
	void pop_back();
	size_t size() const;
	bool empty() const;
	size_t capacity() const;
	void reserve(size_t n);
private:
	size_t vCapacity;	
	size_t vSize;		
	T* V;
	void vAllocate(size_t n);
	// ��ʱ��Ҫ�ڳ�ʼ������һ����������, �˴�ȡ16
	static const size_t positive_capacity = 16;
};

// �����¿ռ䲢��������
template <typename T>
void xVector<T>::vAllocate(size_t n)
{
	V = new T[n];		// ��V����������ڴ�ռ�
	vCapacity = n;
}

// Ϊ���������������������С, ����ѧ�߲�����ʹ��.
template <typename T>
void xVector<T>::reserve(size_t n)
{
	// n�������е�vCapacity����Ч
	if (n > vCapacity)
	{
		T* Vx = new T[n];	// �������ڴ�ռ�
		for(size_t i = 0; i < vSize; i++)
			Vx[i] = V[i];
		delete[] V;			// �ͷ�ԭ�пռ�
		V = Vx;				// ��V���Vxָ��Ŀռ�
		vCapacity = n;
	}
}

// ���캯����ʵ��
template <typename T>
xVector<T>::xVector(size_t size, const T& initVal)
	: vSize(0), V(NULL)
{
	// ���캯��ֻ��Ҫ��һ��, ��������ж��޹غ�����. ����, ע��size����Ϊ��.
	if (size > 0)
	{
		vAllocate(2 * size);
		vSize = size;
		// �Թ��캯���ĳ�ֵ����initVal������������Ԫ�ظ�ֵ
		for (size_t i = 0; i < vSize; i++)
			V[i] = initVal;
	}
	else	// Ϊ�����ӱ�����, ��ʼ������һ����������
		vAllocate(positive_capacity);
}

// ���ƹ��캯����ʵ��
template <typename T>
xVector<T>::xVector(const xVector<T>& obj)
	: vSize(obj.vSize)
{
	vAllocate(obj.vCapacity);	// ����obj�������������ڴ�ռ�
	for (size_t i = 0; i < vSize; i++)
		V[i] = obj.V[i];		// �������
}

// ����������ʵ��
template <typename T>
xVector<T>::~xVector()
{
	delete[] V;
}

// ���ݽ�������
template <typename T>
void xVector<T>::swap(xVector<T>& rhs)
{
	std::swap(this->V, rhs.V);
	std::swap(this->vCapacity, rhs.vCapacity);
	std::swap(this->vSize, rhs.vSize);
}

// �����=������ʵ��
template <typename T>
xVector<T>& xVector<T>::operator=(const xVector<T>& rhs)
{
	// ���÷�: copy and swap
	xVector<T> temp(rhs);
	// ����this��temp�����ݲ���
	swap(temp);
	return *this;
}

// ���������ײ�
template <typename T>
T& xVector<T>::front()
{
	return V[0];
}

// ���������ײ��ĳ����汾
template <typename T>
const T& xVector<T>::front() const
{
	return V[0];
}

// ��������ĩβ
template <typename T>
T& xVector<T>::back()
{
	return V[vSize - 1];
}

// ��������ĩβ�ĳ����汾
template <typename T>
const T& xVector<T>::back() const
{
	return V[vSize - 1];
}

// �����[]������ʵ��
template <typename T>
T& xVector<T>::operator[] (size_t i)
{
	return V[i];
}

// �����[]������ʵ�ֵĳ����汾
template <typename T>
const T& xVector<T>::operator[] (size_t i) const
{
	return V[i];
}

// ������ĩβ�����Ԫ��
template <typename T>
void xVector<T>::push_back(const T& item)
{
	// �������������, ����������������������.
	if (vSize == vCapacity)
	{
		// ��ֹitemΪV�е�Ԫ��, ��ǰ���渱��.
		T item_copy = item;
		reserve(2 * vCapacity);
		V[vSize] = item_copy;
	}
	else
		V[vSize] = item;
	vSize++;
}

// ȥ��������ĩβԪ��
template <typename T>
void xVector<T>::pop_back()
{
	vSize--;
}

// ���������Ĵ�С
template <typename T>
size_t xVector<T>::size() const
{
	return vSize;
}

// �ж������Ƿ�Ϊ��
template <typename T>
bool xVector<T>::empty() const
{
	return (vSize == 0);
}

// ���������ĵ�ǰ����
template <typename T>
size_t xVector<T>::capacity() const
{
	return vCapacity;
}

#endif  // xVECTOR_H
