#include "xWDigraph.h"

#ifndef X_WEIGHTED_GRAPH
#define X_WEIGHTED_GRAPH

class xWGraph : public xWDigraph {
public:
	// ���캯��, VΪԤ�趥����
	xWGraph(size_t V = 0);
	// �����(u, v), ȨֵΪweight(Ĭ��ֵΪ0).
	void add_edge(size_t u, size_t v, double weight = 0);
	// ɾ����(u, v)
	void remove_edge(size_t u, size_t v);
	// Kruskal�㷨
	double Kruskal();
	// Prim�㷨
	double Prim();
};

# endif	// X_WEIGHTED_GRAPH

