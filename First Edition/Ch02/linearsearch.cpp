int LinearSearch(int k, const int data[], int N)
{
	// ����: k - ����ֵ; data - ���ݼ�; N - ���ݼ�����.
	// ���: ����return��䷵��.
	for (int pos = 0; pos < N; pos++)
		if (data[pos] == k)
			return pos;		// �ҵ�k, ����λ����Ϣ.
	return N;				// δ�ҵ�k, ����N.
}