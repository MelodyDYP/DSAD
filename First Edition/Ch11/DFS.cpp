#include "xDigraph.h"

void xDigraph::DepthFirstSearch(size_t v)
{
	visit(v);			// ���ʶ���v
	marked[v] = true;	// �øö���Ϊ�ѷ���
	for (auto c_iter = AL[v].cbegin(); c_iter != AL[v].cend(); ++c_iter)
		if (!marked[*c_iter])
			DepthFirstSearch(*c_iter);
}

void xDigraph::DFS(size_t v)
{
	// ���ж�����Ϊδ����
	for (size_t i = 0; i < marked.size(); i++)
		marked[i] = false;
	DepthFirstSearch(v);
}
