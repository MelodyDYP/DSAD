#include "book.h"

// ǰ�����������, ������Ļ������������.
void preorderTraverse(intBTnode* p)
{
	if (p != NULL)
	{
		cout << p->data << ' ';			// ����Ļ�������ǰ����
		preorderTraverse(p->lChild);	// ǰ�����������
		preorderTraverse(p->rChild);	// ǰ�����������
	}
}

// �������������, ������Ļ������������.
void inorderTraverse(intBTnode* p)
{
	if (p != NULL)
	{
		inorderTraverse(p->lChild);		// �������������
		cout << p->data << ' ';			// ����Ļ�������ǰ����
		inorderTraverse(p->rChild);		// �������������
	}
}

// �������������, ������Ļ������������.
void postorderTraverse(intBTnode* p)
{
	if (p != NULL)
	{
		postorderTraverse(p->lChild);	// �������������
		postorderTraverse(p->rChild);	// �������������
		cout << p->data << ' ';			// ����Ļ�������ǰ����
	}
}

// ����α���������, ������Ļ������������.
void levelorderTraverse(intBTnode* p)
{
	queue<intBTnode*> Q;
	if (p != NULL)
		Q.push(p);
	while (!Q.empty())
	{
		// ����Ļ���������Ԫ������
		cout << Q.front()->data << ' ';
		// ���׶�Ӧ������Ӳ�ΪNULL�����
		if (Q.front()->lChild != NULL)
			Q.push(Q.front()->lChild);
		// ���׶�Ӧ����Һ��Ӳ�ΪNULL�����
		if (Q.front()->rChild != NULL)
			Q.push(Q.front()->rChild);
		Q.pop();	// ����Ԫ�س���
	}
}

void simpleBTexample()
{
	int h;			// ������������h
	cin >> h;
	if (h < 0)		// ����Ϊ���򲻴���
		return;
	// ��Ϊh�������������еĽ������
	int N = static_cast<int>(pow(2.0, h + 1) - 1);
	// Ϊ�������, һ�����������н������ռ�
	intBTnode* nodes = new intBTnode[N];
	int start = 0;	// ��ʼ��
	int gap = 2;	// ���
	for (int i = start; i < N; i += gap)
	{
		nodes[i].data = i;
		nodes[i].lChild = NULL;
		nodes[i].rChild = NULL;
	}
	// ִ��h��ѭ��������Ͻ�����
	for (int L = 0; L < h; L++)
	{
		start = 2 * start + 1;	// �²���ʼ��
		gap *= 2;				// �²���
		for (int i = start; i < N; i += gap)
		{
			nodes[i].data = i;
			nodes[i].lChild = nodes + i - gap / 4;
			nodes[i].rChild = nodes + i + gap / 4;
		}
	}
	// �������ָ��Ϊnodes + N / 2
	intBTnode* root = nodes + N / 2;
	preorderTraverse(root);
	cout << endl;
	inorderTraverse(root);
	cout << endl;
	postorderTraverse(root);
	cout << endl;
	levelorderTraverse(root);
	cout << endl;
	delete[] nodes;	// �ͷ����н��
}
