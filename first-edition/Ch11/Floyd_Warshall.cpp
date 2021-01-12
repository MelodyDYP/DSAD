#include "xWDigraph.h"

void xWDigraph::FW(matrix<size_t>& path, matrix<double>& length)
{
	// �趥����ΪV, ������Ҫ��֤path��length����V * V�ľ���.
	size_t V = num_vertices();
	// ��ʼ��path��������. 
	// ����path�����С������Ҫ��. 
	path = matrix<size_t>(V, V);
	// ������path(u, v)��ֵΪu.
	for (size_t u = 0; u < V; u++)
		for (size_t v = 0; v < V; v++)
			path(u, v) = u;
	// ��ʼ��length��������.
	// ��ʱ������length�����е�Ԫ��Ϊ�������. 
	length = matrix<double>(V, V, POSITIVE_INFINITY);
	for (size_t v = 0; v < V; v++)
		length(v, v) = 0;	// �Խ��߸�0, ��Ȧ.
	// �����ڽӱ��еı�����, ÿ�����Ҷ���Ϊc_iter->v, ȨΪc_iter->weight. 
	for (size_t u = 0; u < V; u++)
		for(auto c_iter = WL[u].cbegin(); c_iter != WL[u].cend(); ++c_iter)
			length(u, c_iter->v) = c_iter->weight;
	// ���μ���k-���·��, ÿ�μ������path�����length����.
	for (size_t k = 0; k < V; k++)
		for (size_t u = 0; u < V; u++)
			for (size_t v = 0; v < V; v++)
				if (length(u, k) + length(k, v) < length(u, v))
				{
					// ��������´�u��v��·�����α�Ϊ��k��v��·��, 
					// �ʶ�������Ҫ����path(u, v)Ϊpath(k, v).
					path(u, v) = path(k, v);
					length(u, v) = length(u, k) + length(k, v);
				}
}