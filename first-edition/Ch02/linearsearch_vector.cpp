size_t LinearSearch(int k, const vector<int>& vdata)
{
	// ����: k - ����ֵ; vdata - ���ݼ�.
	// ���: ����return��䷵��.
	// vdata��һ�����int�����ݵ�����, ע�������������ݼ�����vdata.size().
	// ��forѭ�����������������N�Ա�ʾʵ��Ԫ�ظ���.
	for (size_t pos = 0; pos < vdata.size(); pos++)
		if (vdata[pos] == k)
			return pos;		// �ҵ�k, ����λ����Ϣ.
	return vdata.size();	// δ�ҵ�k, ����vdata.size().
}