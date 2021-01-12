#include "xWDigraph.h"

#include <queue>
using std::queue;

#include <utility>
using std::pair;

using std::vector;

bool xWDigraph::BFM(size_t s, vector<size_t>& path, 
	vector<double>& length)
{
	// �趥����ΪV, ������Ҫ��֤path��length���ǳ�ΪV������.
	size_t V = num_vertices();
	// ��ʼ��path����, ��������Ԫ�س�ֵΪs.
	path = vector<size_t>(V, s);
	// ��ʼ��length����.
	// ��ʱ������length�����е�Ԫ��Ϊ�������. 
	length = vector<double>(V, POSITIVE_INFINITY);
	// sλ��·�����ȳ�ֵΪ0.
	length[s] = 0;
	// ���д�Ŷ�����ö������ڵĵ������.
	queue<pair<size_t, size_t>> Q;
	// ��ʼ���붥��s, ��������Ϊ0. 
	Q.push({s, 0});
	// Ϊ�����ظ����, ��marked������Ƕ����Ƿ��ڶ�����, ��ʼֻ��s��Q��. 
	for (size_t i = 0; i < V; i++)
		marked[i] = false;
	marked[s] = true;
	// �𲽵��������·������, ����V - 1��.
	while (!Q.empty())
	{
		// ������γ���V, ��Ȼ���ڸ���.
		if (Q.front().second > V)
			return false;
		// ����Ԫ�ض�Ӧ����Ϊu, �������Ϊlevel. 
		size_t u = Q.front().first;
		size_t level = Q.front().second;
		Q.pop();
		marked[u] = false;	// ����u�Ѿ����ڶ�����.
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
				// ����length[v]����, ��v���ڶ����������, ע�������μ�1.
				if (!marked[v])
				{
					Q.push({v, level + 1});
					marked[v] = true;	// ����v���ڶ�����.
				}
			}
	}
	return true;
}