#include "book.h"

// ��������R�鲢��������L��, ����L��������.
template <typename T>
void Merge(forward_list<T>& L, forward_list<T>& R)
{
	// ��λ�鲢Ŀ��λ�õĵ�����.
	auto iter_dest = L.before_begin();
	// ����L�ĵ�����, ��ʼλ��ΪL.begin().
	auto iter_L = L.begin();
	// ����R�ĵ�����, ��ʼλ��ΪR.begin().
	auto iter_R = R.begin();
	// L��R����Ԫ�ؿ����ڹ鲢.
	while (iter_L != L.end() && iter_R != R.end())
	{
		if (*iter_L < *iter_R)
			++iter_L;	// L�ĵ�����ǰ��, �������.
		else
		{
			// ��R��Ԫ�ز���Ŀ��λ��.
			L.insert_after(iter_dest, *iter_R);
			++iter_R;	// R�ĵ�����ǰ��.
		}
		++iter_dest;	// Ŀ��λ�õ�����ǰ��.
	}
	// ��R��ʣ�ಿ��[iter_R, R.end())��ΧԪ�ز���, ����Ԫ���򲻻����.
	L.insert_after(iter_dest, iter_R, R.end());
}

// �Ե���data��Ԫ�ؽ��й鲢����.
template <typename T>
void MergeSort(forward_list<T>& data)
{
	// ���������������ĵ���L_in_L.
	forward_list<forward_list<T>> L_in_L;
	size_t n = 0;		// ��¼���ݸ���.
	// �������ɵ���, ÿ������ֻ��һ��data�е�Ԫ��.
	// ע��iter�ڲ���֮�󱻸�ֵΪ�²���Ԫ�����ڵ�λ��.
	auto iter = L_in_L.before_begin();
	for (auto iter_d = data.begin(); iter_d != data.end(); ++iter_d)
	{
		iter = L_in_L.insert_after(iter, forward_list<T>(1, *iter_d));
		n++;
	}
	// ����������ʣ������Ԫ��������鲢.
	while (n > 1)
	{
		// ��L_in_L�в�ֹһ��������, �����һ�˹鲢.
		size_t L = n;
		auto iter_L = L_in_L.begin();
		// һ�˹鲢��ÿ�ν������������鲢��һ��, ������ɹ鲢�򲻶Ͻ���.
		while (L > 1)
		{
			auto iter_R = iter_L;
			++iter_R;
			// ��iter_L��iter_Rָʾ�ĵ����鲢.
			Merge(*iter_L, *iter_R);
			// ��ǰ������λ������Ϊiter_L, iter_R, iter_N.
			// ɾ��iter_R��ָʾ�ĵ���, ����iter_L��Ϊiter_N.
			iter_L = L_in_L.erase_after(iter_L);
			// ���˹鲢��ʣ���������������2.
			L -= 2;
			// L_in_L��������������1.
			n--;
		}
	}
	// ���ֻʣ��һ��������, ������ɹ�.
	if (n == 1)
		data = L_in_L.front();
}
