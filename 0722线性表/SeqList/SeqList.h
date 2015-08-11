#pragma once
#include <iostream>
using namespace std;

template <typename T,size_t N>
class CSeqList
{
private:
	T data[N];
	size_t m_unLen;
public:
	// 关系枚举
	enum  Erel
	{
		REL_EQUAL = 0x01,		// 等于
		REL_ABOVE = 0x02,		// 大于
		REL_BELOW = 0x04,		// 小于
		REL_UNEQUAL = 0x06,		// 不等于
		REL_MORE = 0x03,		// 大于等于
		REL_LESS = 0x05
	};
	// 逻辑枚举
	enum ESet
	{
		SET_AND = 0x10,			// 交集
		SET_OR = 0x20,			// 并集
		SET_DEC = 0x40,			// 差集
	};
private:
	// 内部接口
	bool IsFull() const;
	bool IsEmpty() const;
public:
	CSeqList();
	CSeqList(const CSeqList<T, N> &r_obj);
	CSeqList<T, N> & operator = (const CSeqList<T, N> &r_obj);
	~CSeqList();
	// 增
	CSeqList &push_back(const T &val);			
	CSeqList &push_front(const T &val);
	CSeqList &insert(size_t index, const T &val);
	// 删
	void erase(size_t index);
	// 改
	CSeqList &modify(size_t index, const T &val);
	T &operator [] (size_t index);
	// 查
	size_t find( const T &val) const;
	size_t size() const;
	// 增强型查找
	size_t* find_if(ERel rel, const T& val);		// 查询符合关系条件的数组
	size_t* operator ==(const T& val);				// 查询等于这个数值的下标
	size_t* operator >(const T& val);				// 查询大于这个数值的下标
	size_t* operator <(const T& val);				// 查询小于这个数值的下标
	size_t* operator !=(const T& val);				// 查询不等于这个数值的下标
	size_t* operator >=(const T& val);				// 查询大于或等于这个数值的下标
	size_t* operator <=(const T& val);
	// 条件筛选
	size_t* deal(ESet set, size_t* list1, size_t* list2);	// 集合处理
	size_t* and(const CSeqList &list2);						// 交集
	size_t* or(const CSeqList & list2);						// 并集
	size_t* dec(const CSeqList & list2);
	friend istream& operator >>(istream& in, CSeqList<T, N>& obj)
	{
		size_t i;
		obj.m_nSize = 0;
		for (i = 0; i < N; i++)
		{
			if (!(in >> obj.m_tData[i]))
			{
				in.setstate(in.failbit);
				return in;
			}
			obj.m_nSize++;
		}
		return in;
	}
	friend ostream& operator <<(ostream& out, const CSeqList<T, N>& obj)
	{
		size_t i;
		ostringstream tmp;
		for (i = 0; i < obj.m_nSize; i++)
			tmp << obj.m_tData[i] << " ";
		out << tmp.str();
		return out;
	}
};

template <typename T, size_t N>
CSeqList<T, N>::CSeqList()
	:m_unLen(0)
{
	
}

template <typename T, size_t N>
CSeqList<T, N>::CSeqList(const CSeqList<T, N> &r_obj)
{
	int i;
	for (i = 0; i < N; i++)
	{
		data[i] = r_obj.data[i];
	}
	m_unLen = r_obj.m_unLen;
}

template <typename T, size_t N>
CSeqList<T, N> & CSeqList<T, N>::operator = (const CSeqList<T, N> &r_obj)
{
	int i;
	for (i = 0; i < N; i++)
	{
		data[i] = r_obj.data[i];
	}
	m_unLen = r_obj.m_unLen;
	return *this;
}

template <typename T, size_t N>
CSeqList<T, N>::~CSeqList()
{

}


template <typename T, size_t N>
CSeqList &CSeqList<T, N>::push_back(const T &val)
{
	if (IsFull())
		return *this;
	data[m_unLen] = val;

}

template <typename T, size_t N>
CSeqList &CSeqList<T, N>::push_front(const T &val)
{
	if (IsFull())
		return *this;
	insert(0, val);
}

template <typename T, size_t N>
CSeqList &CSeqList<T, N>::insert(size_t index, const T &val)
{
	if (index < 0 || index > m_unLen || IsFull())
		return *this;
	int i = m_unLen;
	for (i = 0; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[i] = val;
	return *this;
}

template <typename T, size_t N>
void CSeqList<T, N>::erase(size_t index)
{
	if (index < 0 || index >= m_unLen || IsFull())
		return *this;
	int i;
	for (i = index; i < m_unLen - 1; i++)
	{
		data[i] = data[i + 1];
	}
	return *this;
}

template <typename T, size_t N>
CSeqList &CSeqList<T, N>::modify(size_t index, const T &val)
{
	if (index < 0 || index >= m_unLen)
		return *this;
	data[index] = val;
}

template <typename T, size_t N>
T &CSeqList<T, N>::operator [] (size_t index)
{
	if (index < 0 || index >= m_unLen)
		return;
	return data[index];
}

template <typename T, size_t N>
size_t CSeqList<T, N>::find(const T &val) const
{
	int i;
	for (i = 0; i < m_unLen; i++)
	{
		if (val == data[i])
			return i;
	}
	return -1;
}

template <typename T, size_t N>
size_t CSeqList<T, N>::size() const
{
	return m_unLen;
}

template <class T, size_t N>
size_t* CSeqList<T, N>::find_if(ERel rel, const T& val)
{
	switch (rel)
	{
	case REL_EQUAL:
		return operator==(val);
	case REL_ABOVE:
		return operator>(val);
	case REL_BELOW:
		return operator<(val);
	case REL_UNEQUAL:
		return operator!=(val);
	case REL_MORE:
		return operator>=(val);
	case REL_LESS:
		return operator<=(val);
	}
	return nullptr;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::operator ==(const T& val)
{
	T *temp = new T[N+1];
	int i;
	int j = 0;
	for (i = 0; i < m_unLen; i++)
	{
		if (val == data[i])
			temp[j++] = val;
	}
	temp[j] = -1;
	return temp;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::operator >(const T& val)
{
	T *temp = new T[N + 1];
	int i;
	int j = 0;
	for (i = 0; i < m_unLen; i++)
	{
		if (val < data[i])
			temp[j++] = val;
	}
	temp[j] = -1;
	return temp;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::operator <(const T& val)
{
	T *temp = new T[N + 1];
	int i;
	int j = 0;
	for (i = 0; i < m_unLen; i++)
	{
		if (val > data[i])
			temp[j++] = val;
	}
	temp[j] = -1;
	return temp;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::operator !=(const T& val)
{
	T *temp = new T[N + 1];
	int i;
	int j = 0;
	for (i = 0; i < m_unLen; i++)
	{
		if (val != data[i])
			temp[j++] = val;
	}
	temp[j] = -1;
	return temp;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::operator >=(const T& val)
{
	T *temp = new T[N + 1];
	int i;
	int j = 0;
	for (i = 0; i < m_unLen; i++)
	{
		if (val >= data[i])
			temp[j++] = val;
	}
	temp[j] = -1;
	return temp;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::operator <=(const T& val)
{
	T *temp = new T[N + 1];
	int i;
	int j = 0;
	for (i = 0; i < m_unLen; i++)
	{
		if (val <= data[i])
			temp[j++] = val;
	}
	temp[j] = -1;
	return temp;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::deal(ESet set, size_t* list1, size_t* list2)
{
	return nullptr;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::and(const CSeqList<T, N> &list2)
{
	int i, j;
	int t = 0;
	bool isRepeat = false;
	T *temp = new T[N + 1];

	for (i = 0; i < m_unLen; i++)
	{
		for (j = 0; j < list2.m_unLen; j++)
		{
			isRepeat = false;
			if (data[i] == list2.data[j])
			{
				int m;
				for (m = 0; m < t; m++)
				{
					if (temp[m] == data[i])
						isRepeat = true;
				}
				if (!isRepeat)
					temp[t++] = data[i];
			}
		}
	}
	return temp;

}

template <typename T, size_t N>
size_t* CSeqList<T, N>::or(const CSeqList<T,N> & list2)
{
	int i, j;
	int t = 0;
	T *temp = new T[N+1];
	int isRepeat[2 * N] = { 0 };

	T total[2 * N];
	for (i = 0; i < m_unLen; i++)
	{
		total[i] = data[i];
	}
	for (i = 0, j = m_unLen; i < list2.m_unLen; i++)
	{
		total[j++] = list2.data[i];
	}
	//for (i = 0; i < (m_unLen + list2.m_unLen); i++)
	//{
	//	T check = total[i];
	//	for (j = 0; j < (m_unLen + list2.m_unLen); j++)
	//	{
	//		if (check == total[j])
	//			
	//	}
	//}
	for (i = 0; i < (m_unLen + list2.m_unLen); i++)
	{
		cout << total[i] << endl;
	}
	return nullptr;
}

template <typename T, size_t N>
size_t* CSeqList<T, N>::dec(const CSeqList & list2)
{
	int i, j;
	int t = 0;
	T *temp = new T[2 * N + 1];
	bool isRepeat = false;

	for (i = 0; i < m_unLen; i++)
	{
		for (j = 0; j < list2.m_unLen; j++)
		{
			isRepeat = false;
			int m;
			for (m = 0; m < t; m++)
			{
				if (temp[m] == data[i])
					isRepeat = true;
			}
			if (!isRepeat)
				temp[t++] = data[i];
		}
	}
	return nullptr;
}

template <typename T, size_t N>
bool CSeqList<T, N>::IsFull() const
{
	if (m_unLen == N - 1)
		return true;
	return false;
}

template <typename T, size_t N>
bool CSeqList<T, N>::IsEmpty() const
{
	if (m_unLen == 0)
		return true;
	return false;
}