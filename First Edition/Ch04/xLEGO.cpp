#include "xLEGO.h"
#include "book.h"

LEGO::LEGO(int N, int given_spot_x, int given_spot_y)
	: baseplate(N, N, -1), length(N),
		init_spot_x(given_spot_x), init_spot_y(given_spot_y) 
{
	// ��ʼ����ƽ��λ�ñ��Ϊ0.
	baseplate(init_spot_x, init_spot_y) = 0;
}

void LEGO::SolveLEGO(int N, int start_x, int start_y, 
	int spot_x, int spot_y)
{
	if (N > 1)
	{
		int half = N / 2;
		int i, j;
		// spot_x_temp��spot_y_temp������С�װ������λ������.
		int spot_x_temp[2][2];
		int spot_y_temp[2][2];
		// ��ͳһ��������λ��4���������, Ҳ����for���ʵ��(������).
		spot_x_temp[0][0] = start_x + half - 1;
		spot_y_temp[0][0] = start_y + half - 1;
		spot_x_temp[0][1] = start_x + half - 1;
		spot_y_temp[0][1] = start_y + half;
		spot_x_temp[1][0] = start_x + half;
		spot_y_temp[1][0] = start_y + half - 1;
		spot_x_temp[1][1] = start_x + half;
		spot_y_temp[1][1] = start_y + half;
		// �ٽ�����λ��4�����в���Ҫ��ש��λ��Ϊ����������λ��.
		int p = (spot_x - start_x) / half;
		int q = (spot_y - start_y) / half;
		spot_x_temp[p][q] = spot_x;
		spot_y_temp[p][q] = spot_y;
		// ��ʱ���治��Ҫ��ש��λ��ԭ�е�ֵ.
		int temp = baseplate(spot_x_temp[p][q], spot_y_temp[p][q]);
		// ������λ�ý���һ����ש����
		baseplate(spot_x_temp[0][0], spot_y_temp[0][0]) = label;
		baseplate(spot_x_temp[0][1], spot_y_temp[0][1]) = label;
		baseplate(spot_x_temp[1][0], spot_y_temp[1][0]) = label;
		baseplate(spot_x_temp[1][1], spot_y_temp[1][1]) = label;
		// �ָ�����Ҫ��ש��λ��ԭ�е�ֵ, �˷�ʽ�������ж����.
		baseplate(spot_x_temp[p][q], spot_y_temp[p][q]) = temp;
		// ����ש�ı����1, Ϊ�´���ש׼��.
		label++;
		// ���ƽ���ָ�Ϊ4���С�ߴ�ĵװ���еݹ���ש.
		SolveLEGO(half, start_x, start_y,
			spot_x_temp[0][0], spot_y_temp[0][0]);
		SolveLEGO(half, start_x, start_y + half,
			spot_x_temp[0][1], spot_y_temp[0][1]);
		SolveLEGO(half, start_x + half, start_y,
			spot_x_temp[1][0], spot_y_temp[1][0]);
		SolveLEGO(half, start_x + half, start_y + half,
			spot_x_temp[1][1], spot_y_temp[1][1]);
	}
}

void LEGO::Solve()
{
	label = 1;
	SolveLEGO(length, 0, 0, init_spot_x, init_spot_y);
}

void LEGO::Output()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
			cout << setw(5) << baseplate(i, j);
		cout << endl;
	}
}