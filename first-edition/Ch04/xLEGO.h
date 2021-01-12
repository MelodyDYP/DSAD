#include "book.h"

#ifndef LEGO_CLASS
#define LEGO_CLASS

class LEGO {
public:
	LEGO(int N, int init_spot_x, int init_spot_y);
	// ���캯��.
	void Solve();
	// ���.
	void Output();
	// ����Ļ������ⷨ.
private:
	void SolveLEGO(int N, int start_x, int start_y, 
		int spot_x, int spot_y);
	// NΪ�����װ嵱ǰ�߳�, start_x��start_yΪ�õװ����Ͻ�����,
	// spot_x��spot_yΪ��ǰ�װ������̵�λ��.
	matrix<int> baseplate;			// �洢�װ������ݵľ���.
	int init_spot_x, init_spot_y;	// ��ʼ����ƽ�ߵ�λ������.
	int length;						// �װ峤��.
	int label;						// ���, Ϊ����ש��Ǳ���Ҳ�������.
};

#endif