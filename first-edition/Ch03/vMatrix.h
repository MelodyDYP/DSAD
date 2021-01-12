#include <vector>

#ifndef V_MATRIX
#define V_MATRIX

template <typename T>
class matrix {
public:
	// ���캯��.
	explicit matrix(size_t p = 0, size_t q = 0, const T& initVal = T());
	// ����(i, j)λ�õ�Ԫ��.
	T& operator()(size_t i, size_t j);
	// ����(i, j)λ�õ�Ԫ��, �����汾.
	const T& operator()(size_t i, size_t j) const;
	// ���ؾ��������.
	size_t dimX() const
	{
		return nRows;
	}
	// ���ؾ��������.
	size_t dimY() const
	{
		return nCols;
	}
private:
	// �ڲ�ʵ����һ������������, 
	// ����Ȥ�Ķ��߿ɲ���sizeof(vector<T>)��ֵ��˼��.
	std::vector<std::vector<T>> mat;
	// ���������.
	size_t nRows;
	// ���������.
	size_t nCols;
};

// ���캯��ʵ��.
template <typename T>
matrix<T>::matrix(size_t p, size_t q, const T& initVal)
	: mat(p), nRows(p), nCols(q)
{
	for (size_t i = 0; i < p; i++)
	{
		mat[i].resize(q);
		for (size_t j = 0; j < q; j++)
			mat[i][j] = initVal;
	}
}

// ����(i, j)λ�õ�Ԫ��.
template <typename T>
T& matrix<T>::operator()(size_t i, size_t j)
{
	return mat[i][j];
}

// ����(i, j)λ�õ�Ԫ��, �����汾.
template <typename T>
const T& matrix<T>::operator()(size_t i, size_t j) const
{
	return mat[i][j];
}

#endif	// V_MATRIX
