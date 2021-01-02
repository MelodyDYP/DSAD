#include "xUF.h"
#include <stack>

xUF::xUF(size_t n)
	: PR(n, -1), countUF(n)
{
	// ���캯����PR��n��Ԫ��ȫ��ֵΪ-1
}

void xUF::Union(int x, int y)
{
	int r_x = Find(x);	// Ѱ��x���ڼ��ϵĴ���Ԫr_x
	int r_y = Find(y);	// Ѱ��y���ڼ��ϵĴ���Ԫr_y
	// x��y����һ������������кϲ�
	if (r_x != r_y)
	{
		countUF--;
		// ��ѡ���Ƚ�С(�Ƚϴ�)����֮�������Ϊ�µĴ���Ԫ
		if (PR[r_x] > PR[r_y])
			PR[r_x] = r_y;			// r_yΪ�´���Ԫ
		else if (PR[r_x] < PR[r_y])
			PR[r_y] = r_x;			// r_xΪ�´���Ԫ
		else
		{
			// ���������ѡһ�������, ����ѡr_x
			PR[r_y] = r_x;			// r_xΪ�´���Ԫ
			PR[r_x]--;				// ���ȼ�1(���ȼ�1)
		}
	}
}

int xUF::Find(int x)
{
	std::stack<int> S;
	// �ڲ��Ҵ���Ԫ��������ջ����·�������н��
	while (PR[x] >= 0)
	{
		S.push(x);
		x = PR[x];
	}
	// ������·��ѹ��
	while (!S.empty())
	{
		PR[S.top()] = x;
		S.pop();
	}
	return x;
}

size_t xUF::size() const
{
	return PR.size();
}

size_t xUF::count() const
{
	return countUF;
}
