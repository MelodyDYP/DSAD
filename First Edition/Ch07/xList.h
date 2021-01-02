// ����std::swap.
#include <utility>

#ifndef xLIST_CLASS
#define xLIST_CLASS

// Ϊ��Ԫ������ʹ����ǰ����������.
template <typename T>
class xList_iterator;
template <typename T>
class xList_const_iterator;
template <typename T>
class xDLnode;
template <typename T>
class xList;

// ��������Ķ�����ʵ��.
template <typename T>
class xList_iterator {
public:
	friend class xList<T>;
	friend class xList_const_iterator<T>;
	xList_iterator()
		: nodePtr(NULL)
	{
		// ʹ��xList_iterator<T>�������Ĭ�Ϲ��캯��,
		// ��ʹ�ú����list<T>::iterator�಻��Ҫ���.
	}
	// ==�����.
	bool operator== (const xList_iterator& rhs) const
	{
		return (nodePtr == rhs.nodePtr);
	}
	// !=�����.
	bool operator!= (const xList_iterator& rhs) const
	{
		return (nodePtr != rhs.nodePtr);
	}
	// *�����, ע��˴���T&ʹ����Щ�����ֻ��ʹ�ó���������.
	T& operator* ()
	{
		return nodePtr->data;
	}
	// ��Ϊǰ׺ʹ�õ�++�����.
	xList_iterator& operator++ ()
	{
		nodePtr = nodePtr->next;
		return *this;  // ������ֵ.
	}
	// ��Ϊ��׺ʹ�õ�++�����, ��(int)����־.
	xList_iterator operator++ (int)
	{
		xList_iterator temp = *this;
		nodePtr = nodePtr->next;
		return temp;  // ����ԭֵ.
	}
	// ��Ϊǰ׺ʹ�õ�--�����.
	xList_iterator& operator-- ()
	{
		nodePtr = nodePtr->prev;
		return *this;  // ������ֵ.
	}
	// ��Ϊ��׺ʹ�õ�--�����, ��(int)����־.
	xList_iterator operator-- (int)
	{
		xList_iterator temp = *this;
		nodePtr = nodePtr->prev;
		return temp;  // ����ԭֵ.
	}

private:
	// �ؼ�����, ָ��˫�����ָ��.
	xDLnode<T>* nodePtr;
	xList_iterator(xDLnode<T>* p)
		: nodePtr(p)
	{
		// ˽�й��캯��, ��xList<T>��.
	}
};

// ������������Ķ�����ʵ��.
template <typename T>
class xList_const_iterator {
public:
	friend class xList<T>;
	xList_const_iterator()
		: nodePtr(NULL)
	{
		// ʹ��xList_const_iterator<T>�������Ĭ�Ϲ��캯��,
		// ��ʹ�ú����list<T>::const_iterator�಻��Ҫ���.
	}

	// �ӵ������ൽ�����������ĸ��ƹ��캯��.
	xList_const_iterator(const xList_iterator<T>& obj)
	{
		nodePtr = obj.nodePtr;
	}
	bool operator== (const xList_const_iterator& rhs) const
	{
		return (nodePtr == rhs.nodePtr);
	}

	bool operator!= (const xList_const_iterator& rhs) const
	{
		return (nodePtr != rhs.nodePtr);
	}
	const T& operator* () const
	{
		return nodePtr->data;
	}
	// ��Ϊǰ׺ʹ�õ�++�����.
	const xList_const_iterator& operator++ ()
	{
		nodePtr = nodePtr->next;
		return *this;  // ������ֵ.
	}
	// ��Ϊ��׺ʹ�õ�++�����, ��(int)����־.
	const xList_const_iterator operator++ (int)
	{
		xList_const_iterator temp = *this;
		nodePtr = nodePtr->next;
		return temp;  // ����ԭֵ.
	}
	// ��Ϊǰ׺ʹ�õ�--�����.
	const xList_const_iterator& operator-- ()
	{
		nodePtr = nodePtr->prev;
		return *this;  // ������ֵ.
	}
	// ��Ϊ��׺ʹ�õ�--�����, ��(int)����־.
	const xList_const_iterator operator-- (int)
	{
		xList_const_iterator temp = *this;
		nodePtr = nodePtr->prev;
		return temp;  // ����ԭֵ.
	}

private:
	xDLnode<T>* nodePtr;
	xList_const_iterator(xDLnode<T>* p)
		: nodePtr(p)
	{
		// ˽�й��캯��, ��xList<T>��.
	}
};

// xDLnode��Ķ�����ʵ��.
template <typename T>
class xDLnode {
	friend class xList<T>;
	friend class xList_iterator<T>;
	friend class xList_const_iterator<T>;
private:
	T data;
	xDLnode<T>* prev;	// ָ��ǰһ������ָ��.
	xDLnode<T>* next;	// ָ���һ������ָ��.
	xDLnode(const T& value = T())
		: data(value)
	{
		// Ĭ��ָ������.
		prev = next = this;
	}
};

template <typename T>
class xList {
public:
	// ��������xList_iterator<T>��ΪǶ������,
	// ʹ��xList<T>::iteratorʵΪxList_iterator<T>.
	typedef xList_iterator<T> iterator;
	// ������������xList_const_iterator<T>��ΪǶ������,
	// ʹ��xList<T>::const_iteratorʵΪxList_const_iterator<T>.
	typedef xList_const_iterator<T> const_iterator;
	explicit xList(size_t n = 0, const T& item = T());
	xList(const xList<T>& obj);
	~xList();
	void swap(xList<T>& rhs);
	xList<T>& operator= (const xList<T>& rhs);
	size_t size() const;
	bool empty() const;
	void push_front(const T& item);
	void push_back(const T& item);
	iterator insert(iterator iter, const T& item);
	void pop_front();
	void pop_back();
	iterator erase(iterator iter);
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
private:
	xDLnode<T>* header;		// �ƽ��ָ��.
	size_t lSize;			// ˫ѭ�����ĳ���.
};

// ���캯��.
template <typename T>
xList<T>::xList(size_t n, const T& value)
	: lSize(0)
{
	header = new xDLnode<T>;
	// insert���޸�lSize, ���lSize֮ǰ����Ϊ0.
	for(size_t i = 0; i < n; i++)
		insert(begin(), value);
}

// ���ƹ��캯��.
template <typename T>
xList<T>::xList(const xList<T>& obj)
	: lSize(0)
{
	xDLnode<T>* curr = obj.header->next;
	header = new xDLnode<T>;
	// ��obj��Ԫ�����踴�ƹ����˫ѭ����β���������, ע��insert���޸�lSize.
	while (curr != obj.header)
	{
		insert(end(), curr->data);
		curr = curr->next;
	}
}

// ��������.
template <typename T>
xList<T>::~xList()
{
	// ɾ���������ݽ�㲢�ͷ��ڴ�.
	while (!empty())
		erase(begin());
	// �ͷ��ƽ����ռ�ڴ�.
	delete header;
}

// ���ݽ�������.
template <typename T>
void xList<T>::swap(xList<T>& rhs)
{
	std::swap(this->header, rhs.header);
	std::swap(this->lSize, rhs.lSize);
}

// �����=������ʵ��.
template <typename T>
xList<T>& xList<T>::operator=(const xList<T>& rhs)
{
	// ���÷�: copy and swap.
	xList<T> temp(rhs);
	// ����this��temp�����ݲ���.
	swap(temp);
	return *this;
}

// ����Ԫ�ظ���.
template <typename T>
size_t xList<T>::size() const
{
	return lSize;
}

// �ж��Ƿ�Ϊ��.
template <typename T>
bool xList<T>::empty() const
{
	return (lSize == 0);
}

// �����������Ԫ��.
template <typename T>
void xList<T>::push_front(const T& item)
{
	insert(begin(), item);
}

// ����β�����Ԫ��.
template <typename T>
void xList<T>::push_back(const T& item)
{
	insert(end(), item);
}

// ͳһ��г�Ĳ���Ԫ�غ���.
// �ڵ�����iterǰ����Ԫ��item.
template <typename T>
typename xList<T>::iterator xList<T>::insert(iterator iter, const T& item)
{
	xDLnode<T>* curr = iter.nodePtr;
	// ��������, ָ��Ϊp.
	xDLnode<T>* p = new xDLnode<T>(item);
	p->prev = curr->prev;
	p->next = curr;
	curr->prev->next = p;
	curr->prev = p;
	lSize++;
	return iterator(p);		// �����½������λ�õĵ�����.
}

// ɾ������Ԫ��.
template <typename T>
void xList<T>::pop_front()
{
	erase(begin());
}

// ɾ����βԪ��.
template <typename T>
void xList<T>::pop_back()
{
	erase(--end());
}

// ͳһ��г��ɾ��Ԫ�غ���.
// ɾ��������iterָ���Ԫ��, ע��ɾ����˵���������, 
// ����erase���������ص�λ�����³�ʼ��iter, ����ע��typename�ؼ��ֵ�ʹ��.
template <typename T>
typename xList<T>::iterator xList<T>::erase(iterator iter)
{
	xDLnode<T>* curr = iter.nodePtr;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	iterator iter_next(curr->next);	// ����curr����һ����������Ϊ����ֵ.
	delete curr;
	lSize--;
	return iter_next;
}

// ��������Ԫ�ص�����.
template <typename T>
T& xList<T>::front()
{
	return *begin();
}

// ��������Ԫ�صĳ�������.
template <typename T>
const T& xList<T>::front() const
{
	return *begin();
}

// ������βԪ�ص�����.
template <typename T>
T& xList<T>::back()
{
	return *(--end());
}

// ������βԪ�صĳ�������.
template <typename T>
const T& xList<T>::back() const
{
	return *(--end());
}

// ע�����к������صĵ���������.

// ˫ѭ�����ĳ�ʼλ��begin(), ���ڵ�����.
template <typename T>
typename xList<T>::iterator xList<T>::begin()
{
	return iterator(header->next);
}

// ˫ѭ�����ĳ�ʼλ��begin(), ���ڳ���������.
template <typename T>
typename xList<T>::const_iterator xList<T>::begin() const
{
	return const_iterator(header->next);
}

// ˫ѭ�������ս�λ��end(), ���ڵ�����.
template <typename T>
typename xList<T>::iterator xList<T>::end()
{
	return iterator(header);
}

// ˫ѭ�������ս�λ��end(), ���ڳ���������.
template <typename T>
typename xList<T>::const_iterator xList<T>::end() const
{
	return const_iterator(header);
}

#endif   // xLIST_CLASS