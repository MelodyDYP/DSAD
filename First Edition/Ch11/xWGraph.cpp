#include "xWGraph.h"

xWGraph::xWGraph(size_t V)
	: xWDigraph(V)
{
	// ֻ��ʹ��xWDigraph��Ĺ��캯������.
}

void xWGraph::add_edge(size_t u, size_t v, double weight)
{
	// ����{u, v}�൱�����ӱ�(u, v)��(v, u). 
	xWDigraph::add_edge(u, v, weight);
	xWDigraph::add_edge(v, u, weight);
	// ע����ֻ��������һ����, E�����1.
	E--;
}

void xWGraph::remove_edge(size_t u, size_t v)
{
	// ɾ����{u, v}, ǰ���Ǹñ���ͼ��.
	// ɾ��{u, v}�൱��ɾ����(u, v)��(v, u).
	xWDigraph::remove_edge(u, v);
	xWDigraph::remove_edge(v, u);
	// ע����ֻ����ɾ��һ����, E�����1.
	E++;
}
