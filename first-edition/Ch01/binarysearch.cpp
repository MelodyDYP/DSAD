template <typename T>
void BinarySearch(const T& key, const T data[], int N, bool& found, int& pos)
{
	// ����: key - ����Ԫ��; data - �������ݼ�(��С��������); N - ���ݼ�����.
	// ���: found - ���key�Ƿ��ҵ�; pos - ���ҵ���λ��.
	found = false;
	pos = N;
	int low = 0;
	int high = N - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (key < data[mid])		// С��ȥǰ�벿�ּ�������
			high = mid - 1;
		else if (data[mid] < key)	// ����ȥ��벿�ּ�������
			low = mid + 1;
		else
		{
			pos = mid;
			found = true;
			break;					// �ҵ�������ѭ��
		}
	}
}