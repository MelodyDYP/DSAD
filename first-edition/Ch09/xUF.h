#include <vector>

#ifndef X_UF
#define X_UF

class xUF {
public:
	xUF(size_t n);				// ���캯��
	void Union(int x, int y);	// �ϲ�
	int Find(int x);			// Ѱ�Ҵ���Ԫ
	size_t size() const;		// Ԫ������
	size_t count() const;		// ���ཻ���ĸ���
private:
	std::vector<int> PR;		// �洢���׽���洢����
	size_t countUF;				// ά�����ཻ�������ļ�����
};

# endif	// X_UF
