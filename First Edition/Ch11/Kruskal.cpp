#include "xWGraph.h"
#include "xUF.h"

#include <queue>
using std::priority_queue;

using std::vector;

double xWGraph::Kruskal()
{
	size_t V = xWDigraph::num_vertices();
	// �����бߴ�������EdgeVector��, ����ʹ����Ĭ�Ϲ��캯��, Ч�ʲ���.
	// ���Ը�дΪ����������д洢���Ŀռ�, ʹ��ָ����ʵ��. 
	vector<xWEdge> EdgeVector(2 * E);
	// ���������ܻ���
	double cost =  0;
	// �洢��ָ�����С���ȼ�����PQ
	priority_queue<xWEdge*, vector<xWEdge*>, greater_xWEdgePointer> PQ;
	// �ж϶����Ƿ��ڲ�ͬ���еĲ��ཻ��
	xUF F(V);
	// ���ڽӱ��н����б߷���EdgeVector
	for (size_t pos = 0, u = 0; u < V; u++)
		for (auto c_iter = WL[u].begin(); c_iter != WL[u].end(); ++c_iter)
		{
			EdgeVector[pos] = xWEdge(u, c_iter->v, c_iter->weight);
			pos++;
		}
	// �����бߵ�ָ�����PQ
	for (size_t pos = 0; pos < EdgeVector.size(); pos++)
		PQ.push(&EdgeVector[pos]);
	size_t e_count = 0;		// �߼�����
	// Ѱ��V - 1���������С������
	while (e_count < V - 1)
	{
		xWEdge* ePointer = PQ.top();	// ȡȨ��С�ıߵ�ָ��ePointer
		// ��ePointer->u��ePointer->v����һ��������������ڵ������кϲ�
		if (F.Find(ePointer->u) != F.Find(ePointer->v))
		{
			F.Union(ePointer->u, ePointer->v);
			cost += ePointer->weight;	// �����ܻ���
			e_count++;					// �ҵ�һ����
		}
		PQ.pop();						// ɾ����СԪ
    }
	return cost;
}