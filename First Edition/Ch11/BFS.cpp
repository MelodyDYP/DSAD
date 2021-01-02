#include "xDigraph.h"

#include <queue>
using std::queue;

void xDigraph::BFS(size_t v)
{
	// ���ж�������Ϊδ����
	for (size_t i = 0; i < marked.size(); i++)
		marked[i] = false;
	queue<size_t> Q;
	Q.push(v);
	marked[v] = true;
	while (!Q.empty())
	{
		size_t QF = Q.front();
		Q.pop();
		visit(QF);		// ���ʶ���Ԫ��QF
		// ���QF������������δ���ֵ��ڽӶ������
		for (auto c_iter = AL[QF].cbegin(); c_iter != AL[QF].cend(); ++c_iter)
			if (!marked[*c_iter])
			{
				Q.push(*c_iter);
				marked[*c_iter] = true;	// ���Ϊ�ѷ���
				// ���ܸö��㻹δ������, �����ѽ������, ����һ���ᱻ����.
			}
	}
}