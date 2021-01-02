#include "xWGraph.h"

#include <queue>
using std::priority_queue;

using std::vector;

double xWGraph::Prim()
{
	size_t V = xWDigraph::num_vertices();
	// �����бߴ�������EdgeVector��.
	vector<xWEdge> EdgeVector(2 * E);
	// ���������ܻ���
	double cost =  0;
	// �洢��ָ�����С���ȼ�����PQ
	priority_queue<xWEdge*, vector<xWEdge*>, greater_xWEdgePointer> PQ;
	// ��ʼ������0���붥�㼯P, �������㲻��P��.
	for (size_t u = 1; u < V; u++)
		marked[u] = false;
	marked[0] = true;
	// �������Զ���0Ϊ�˵�ıߵ�ָ�����PQ.
	size_t pos = 0;		// ��¼����EdgeVector�Ŀ���λ��
	for (auto c_iter = WL[0].begin(); c_iter != WL[0].end(); ++c_iter)
	{
		EdgeVector[pos] = xWEdge(0, c_iter->v, c_iter->weight);
		PQ.push(&EdgeVector[pos]);
		pos++;
	}
	size_t e_count = 0;	// �߼�����
	// Ѱ��V - 1���������С������
	while (e_count < V - 1)
	{
		xWEdge* ePointer = PQ.top();	// ȡȨ��С�ı�e��ָ��ePointer
		PQ.pop();						// ɾ����СԪ
		// ��ePointer->u��ePointer->v����һ����P�����¶������P, 
		// ע�����ǵ��㷨��֤�˲������������㶼����P��.
		if ( !(marked[ePointer->u] && marked[ePointer->v]) )
		{
			cost += ePointer->weight;	// �����ܻ���
			e_count++;					// �ҵ�һ����
			// ��ǰ����P�еĶ���Ϊx.
			size_t x;
			if (!marked[ePointer->u])
				x = ePointer->u;
			else
				x = ePointer->v;
			marked[x] = true;			// ������x����P
			// ��һ���˵�Ϊ����x����һ�˵㲻��P�еıߵ�ָ��������ȼ�����PQ��.
			for (auto c_iter = WL[x].begin(); c_iter != WL[x].end(); ++c_iter)
				if (!marked[c_iter->v])
				{
					EdgeVector[pos] = xWEdge(x, c_iter->v, c_iter->weight);
					PQ.push(&EdgeVector[pos]);
					pos++;
				}
		}
    }
	return cost;
}