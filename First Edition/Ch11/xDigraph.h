#include <vector>
#include <list>

#ifndef X_DIGRAPH
#define X_DIGRAPH

class xDigraph {
public:
	// ���캯��, VΪԤ�趥����
	xDigraph(size_t V = 0);
	// ������
	size_t num_vertices() const;
	// ����
	size_t num_edges() const;
	// ���Ա�(u, v)�Ƿ���ͼ��
	bool edge(size_t u, size_t v) const;
	// �����(u, v)
	void add_edge(size_t u, size_t v);
	// ɾ����(u, v)
	void remove_edge(size_t u, size_t v);
	// ����һ������, ���Ϊ��ǰ����ż�1
	void add_vertex();
	// �����������
	void DFS(size_t v);
	// �����������
	void BFS(size_t v);
	// ���ʶ��㺯��
	void visit(size_t v);
protected:
	std::vector<std::list<size_t>> AL;	// �ڽӱ�
	std::vector<bool> marked;			// ����������
	size_t E;							// ����
	void DepthFirstSearch(size_t v);	// ˽�еݹ�DFS���ʺ���
};

# endif	// X_DIGRAPH
