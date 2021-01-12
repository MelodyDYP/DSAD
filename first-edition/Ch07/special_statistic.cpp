#include "book.h"

void InputandPreprocess(list<int>& L, int& MAX)
{
	L.clear();		// ���L����������.
	int data;
	cin >> data;
	MAX = data;		// ע�������ʱMAXΪ������.
	while (data >= 0)
	{
		// ʹ��push_back���Ա������ݵ��������.
		L.push_back(data);
		// ͬʱͳ�����ֵ.
		if (data > MAX)
			MAX = data;
		cin >> data;	// ��������.
	}
}

void Output(const list<int>& L)
{
	// ���ڴ˴α������ı�����״̬, ����ʹ�ó���������c_iter.
	// �������������Ա�֤��L�ĳ�������, �ر���cbegin��cend������begin��end.
	// ����Ҫ�ر�ע��for�����ʹ�ó��������������Ĺ��÷�.
	for (auto c_iter = L.cbegin(); c_iter != L.cend(); ++c_iter)
		cout << *c_iter << ' ';
}

void MeanofLarger(list<int>& L, int d, int MAX)
{
	// ע�������ʱ���ܵ��ñ�����, ��������µ���Ȼ�����о�����ȷ����ֵ.
	// ������ֵ, ����MAX���, ֻ����ڵ�����ֵ����.
	int threshold = MAX - d;
	// ����Ҫ�����֮�ܺ�, ��double�ʹ洢���ں�������.
	double sum = 0;
	int n = 0;					// ����Ҫ�����Ȼ������.
	// ʹ��auto���������iter, ע�����������ɾ��Ԫ��,
	// ��Ϊɾ����ı�����״̬, ����iter��list<int>::iterator�͵ĵ�����.
	auto iter = L.begin();
	while (iter != L.end())
	{
		if (*iter >= threshold)
		{
			sum += *iter;
			n++;
			++iter;		// ��������ǰ.
		}
		else
			iter = L.erase(iter);	// ɾ����iter�ᱻ��ֵ����һԪ��λ��.
	}
	cout << "The mean of the larger numbers is " << sum / n << endl;
	cout << "Larger numbers: ";
	// Ҫ������������������Щ��Ȼ��, ������Ҫ�ٴα���.
	Output(L);
}