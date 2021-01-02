#include "xDigraph.h"
#include <algorithm>
#include <iostream>

xDigraph::xDigraph(size_t V)
	: AL(V), marked(V), E(0)
{
	// �ڽӱ��ʼ����ΪV, ��Ҳ�Ƕ�����.
	// ������������ʼ����ΪV.
	// ������ʼΪ0.
}

size_t xDigraph::num_vertices() const
{
	return AL.size();
}

size_t xDigraph::num_edges() const
{
	return E;
}

bool xDigraph::edge(size_t u, size_t v) const
{
	// ��AL[u]�в���v, ���ص�������ΪAL[u].end()�����δ�ҵ�.
	return ( std::find(AL[u].begin(), AL[u].end(), v) != AL[u].end() );
}

void xDigraph::add_edge(size_t u, size_t v)
{
	// ��������ڶ�Ӧ���������Ӷ���.
	AL[u].push_back(v);	// ����(u, v)
	E++;				// ������1
}

void xDigraph::remove_edge(size_t u, size_t v)
{
	// ɾ����(u, v), ǰ���Ǹñ���ͼ��.
	AL[u].remove(v);	// ɾ��(u, v)
	E--;				// ������1
}

void xDigraph::add_vertex()
{
	// ��ǰ������Ϊ0, 1, ... , V - 1.
	// ����һ���¶���, �����ΪV, �ڽӱ��������Ϣ��Ӧ����.
	AL.push_back(std::list<size_t>());
	marked.push_back(false);
}

void xDigraph::visit(size_t v)
{
	// �˴�����v��ֱ������Ļ�����. 
	// ���߿������޸�������ʶ��㺯���Ĺ���, Ҳ���������κζ���.
	std::cout << v << " ";
}