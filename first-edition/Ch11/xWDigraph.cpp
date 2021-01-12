#include "xWDigraph.h"
#include <algorithm>

// ���岢��ʼ���������Ȩֵ
double xWDigraph::POSITIVE_INFINITY = std::numeric_limits<double>::max();

xWDigraph::xWDigraph(size_t V)
	: WL(V), marked(V), E(0)
{
	// �ڽӱ��ʼ����ΪV, ��Ҳ�Ƕ�����.
	// ������������ʼ����ΪV.
	// ������ʼΪ0.
}

size_t xWDigraph::num_vertices() const
{
	return WL.size();
}

size_t xWDigraph::num_edges() const
{
	return E;
}

bool xWDigraph::edge(size_t u, size_t v) const
{
	// ����һ������oe, �ڽӶ���Ϊv, ��Ȩ��ȡ(�˴�ȡ0).
	xWOutEdge oe(v, 0);
	// ��AL[u]�в���v, ���ص�������ΪAL[u].end()�����δ�ҵ�.
	return ( std::find(WL[u].begin(), WL[u].end(), oe) != WL[u].end() );
}

void xWDigraph::add_edge(size_t u, size_t v, double weight)
{
	// ��������ڶ�Ӧ����WL[u]�����Ӷ���v��Ȩweight. 
	WL[u].push_back(xWOutEdge(v, weight));
	E++;
}

void xWDigraph::remove_edge(size_t u, size_t v)
{
	// ɾ����(u, v), ǰ���Ǹñ���ͼ��.
	// ����һ������oe, �ڽӶ���Ϊv, ��Ȩ��ȡ(�˴�ȡ0).
	xWOutEdge oe(v, 0);
	WL[u].remove(oe);	// ɾ��(u, v)
	E--;				// ������1
}

void xWDigraph::add_vertex()
{
	// ��ǰ������Ϊ0, 1, ... , V - 1.
	// ����һ���¶���, �����ΪV, �ڽӱ��������Ϣ��Ӧ����.
	WL.push_back(std::list<xWOutEdge>());
	marked.push_back(false);
}
