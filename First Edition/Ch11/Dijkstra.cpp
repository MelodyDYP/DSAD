#include "xWDigraph.h"

#include <set>
using std::set;

#include <utility>
using std::pair;

using std::vector;

void xWDigraph::Dijkstra(size_t s, 
	vector<size_t>& path, vector<double>& length)
{
	// �趥����ΪV, ������Ҫ��֤path��length���ǳ�ΪV������.
	size_t V = num_vertices();
	// ��ʼ��path����, ��������Ԫ�س�ֵ��Ϊs. 
	path = vector<size_t>(V, s);
	// ��ʼ��length����. 
	// ��ʱ������length�����е�Ԫ��Ϊ�������. 
	length = vector<double>(V, POSITIVE_INFINITY);
	// sλ��·�����ȳ�ֵΪ0, ����������s���ȱ��ҵ�.
	length[s] = 0;
	// ��δѰ�ҵ��Ķ��㼯��ΪNS.
	set<pair<double, size_t>> NS;
	// �����ڼ���NS�е�λ�ô���vertex_iter��.
	vector<set<pair<double, size_t>>::iterator> vertex_iter(V);
	for (size_t u = 0; u < V; u++)
		vertex_iter[u] = NS.insert({length[u], u}).first;
	for (size_t i = 0; i < V; i++)
	{
		// ÿ����δ�ҵ��Ķ��㼯����, Ѱ����sΪ����·��������̵Ķ���. 
		// �豾�����ҵ��Ķ���Ϊu, ��Ӧ·������Ϊmin.
		double min = NS.begin()->first;
		size_t u = NS.begin()->second;
		// u���ҵ�, �����NS��ɾ��.
		NS.erase(NS.begin());
		// ��u���ڽӱ�Ϊ���ݸ����������.
		for (auto c_iter = WL[u].cbegin(); c_iter != WL[u].cend(); 
			++c_iter)
			if (length[u] + c_iter->weight < length[c_iter->v])
			{
				// Ϊ�������, ����ǰ��������Ϊc_iter->v���Ϊv. 
				size_t v = c_iter->v;
				// ��lenght[u] + w(u, v) < length[v], 
				// �����path[v]��length[v].
				path[v] = u;
				length[v] = length[u] + c_iter->weight;
				// ͨ��ɾ�������²���ı�NS�е���Ӧȡֵ������λ��.
				NS.erase(vertex_iter[v]);
				vertex_iter[v] = 
					NS.insert({length[v], v}).first;
			}
	}
}