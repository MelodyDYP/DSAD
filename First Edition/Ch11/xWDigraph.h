#include <vector>
#include <list>
#include "vMatrix.h"

#ifndef X_WEIGHTED_DIGRAPH
#define X_WEIGHTED_DIGRAPH

// ��Ȩ������, ����ڽӶ������Ȩ
struct xWOutEdge {
	xWOutEdge(size_t init_v, double w = 0)
		: v(init_v), weight(w)
	{
		// ���캯��
	}
	bool operator==(const xWOutEdge& rhs) const
	{
		// �������ڽӶ����������
		return (v == rhs.v);
	}
	// �Ӷ���u��v�ı�, �ڽӶ���Ϊv, ȨΪweight.
	size_t v;			// �ڽӶ���
	double weight;		// ��Ȩ
};

// ��Ȩ�������
struct xWEdge {
	xWEdge(size_t init_u = 0, size_t init_v = 0, double w = 0)
		: u(init_u), v(init_v), weight(w)
	{
		// ���캯��
	}
	// �Ӷ���u��v�ı�, ȨΪweight.
	size_t u;
	size_t v;
	double weight;
};

// ΪxWEdge��ָ�붨��ĺ�������, ���ڱȽϸ���ָ����ָ������Ȩ֮��Ĵ��ڹ�ϵ
class greater_xWEdgePointer {
public:
	bool operator()(const xWEdge* a, const xWEdge* b) const
	{
		return (a->weight > b->weight);
	}
};

class xWDigraph {
public:
	// ���캯��, VΪԤ�趥����
	xWDigraph(size_t V = 0);
	// ������
	size_t num_vertices() const;
	// ����
	size_t num_edges() const;
	// ���Ա�(u, v)�Ƿ���ͼ��
	bool edge(size_t u, size_t v) const;
	// �����(u, v), ȨֵΪweight(Ĭ��ֵΪ0)
	void add_edge(size_t u, size_t v, double weight = 0);
	// ɾ����(u, v)
	void remove_edge(size_t u, size_t v);
	// ����һ������, ���Ϊ��ǰ����ż�1
	void add_vertex();
	// �������Ȩֵ
	static double POSITIVE_INFINITY;
	// Dijkstra�㷨
	void Dijkstra(size_t s, std::vector<size_t>& path, 
		std::vector<double>& length);
	// Bellman-Ford-Moore�㷨
	bool BFM(size_t s, std::vector<size_t>& path, 
		std::vector<double>& length);
	// Floyd-Warshall�㷨
	void FW(matrix<size_t>& path, matrix<double>& length);
protected:
	std::vector<std::list<xWOutEdge>> WL;	// �ڽӱ�, �洢���ߵ��ڽӶ������Ȩ
	std::vector<bool> marked;				// ����������
	size_t E;								// ����
};

# endif	// X_WEIGHTED_DIGRAPH

