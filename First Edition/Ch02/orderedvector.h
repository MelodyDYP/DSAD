#include <vector>

#ifndef xORDEREDVECTOR_H
#define xORDEREDVECTOR_H

template <typename T>
class S1 {
public:
	// ���캯��.
	S1();
	// ��key���뼯����.
	void insert(const T& key);
	// ��posλ�����ڵ�Ԫ��ɾ��, ǰ����pos��0��size() - 1֮��.
	void erase(int pos);
	// ��key�ڼ������򷵻���λ��, ���򷵻�size().
	int search(const T& key) const;
	// ���ؼ��������Ԫ�ص�λ��, ������Ϊ���򷵻�size().
	int maximum_at() const;
	// ���ؼ�������СԪ�ص�λ��, ������Ϊ���򷵻�size().
	int minimum_at() const;
	// ����posλ��Ԫ�صĳ�������, ע��δ�ṩ�ǳ����汾
	const T& operator()(int pos) const;
	// ���ؼ�����Ԫ�صĸ���.
	int size() const;
private:
	std::vector<T> data;
	int count;					// ʵ�����ݸ���
};

template <typename T>
S1<T>::S1()
	: data(1024), count(0)
{
	// Ϊ�����ýϴ�����, ��ʼ�������ȶ�Ϊ1024, Ԫ�ظ�����Ϊ0.
}

template <typename T>
void S1<T>::insert(const T& key)
{
	int i = 0;
	// �����������Բ��ҵķ������ҳ����ʵĲ���λ��pos.
	// ���Ҳ������ʵ�λ������ζӦ����ĩβ, ���ע��pos�ĳ�ֵ.
	// ���õķ����ǻ��ڶ��ֲ��ҿ����ҵ�pos.
	int pos = count;
	while (i < count)
	{
		if (key < data[i])
		{
			pos = i;
			i = count;
		}
		else
			i++;
	}
	if (count == data.size())
	{
		// ��ֹkeyΪdata�е�Ԫ��, ��ǰ���渱��.
		T key_copy = key;
		data.resize( 2 * data.size() );
		for (i = count; i > pos; i--)
			data[i] = data[i - 1];
		data[pos] = key_copy;
	}
	else
	{
		for (i = count; i > pos; i--)
			data[i] = data[i - 1];
		data[pos] = key;
	}
	count++;
}

template <typename T>
void S1<T>::erase(int pos)
{
	// ����: �ȼ���count, �����ֱ��ʹ��i < count
	count--;
	for (int i = pos; i < count; i++)
		data[i] = data[i + 1];
}

template <typename T>
int S1<T>::search(const T& key) const
{
	int low = 0;
	int high = count - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (key < data[mid])
			high = mid - 1;
		else if (data[mid] < key)
			low = mid + 1;
		else
			return mid;		// �ҵ�
	}
	return count;			// δ�ҵ�
}

template <typename T>
int S1<T>::maximum_at() const
{
	// ����ѭ��ʽ���, �ܳ�Ϊcount + 1, 
	// ѭ����(count - 1 + count + 1) % (count + 1),
	// ��˿ɱ�֤����Ϊ��ʱ�����ص�λ����Ϣ.
	return (count + count) % (count + 1);
	// ����� return count > 0 ? count - 1 : 0;
}

template <typename T>
int S1<T>::minimum_at() const
{
	// ע�⼯��Ϊ��ʱ��Ȼ����0.
	return 0;
}

template <typename T>
const T& S1<T>::operator()(int pos) const
{
	return data[pos];
}

template <typename T>
int S1<T>::size() const
{
	return count;
}

#endif  // xORDEREDVECTOR_H
