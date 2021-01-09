#include <vector>

#ifndef xUNORDEREDVECTOR_H
#define xUNORDEREDVECTOR_H

template <typename T>
class unordered_vector_with_large_capacity {
public:
  // 构造函数.
  unordered_vector_with_large_capacity();
  // 将key放入集合中.
  void insert(const T& key);
  // 将pos位置所在的元素删除, 前提是pos在0到size() - 1之间.
  void erase(size_t pos);
  // 若key在集合中则返回其位置, 否则返回size().
  size_t find(const T& key) const;
  // 返回集合中最大元素的位置, 若集合为空则返回size().
  size_t maximum_at() const;
  // 返回集合中最小元素的位置, 若集合为空则返回size().
  size_t minimum_at() const;
  // 返回pos位置元素的常量引用, 注意未提供非常量版本.
  const T& operator()(size_t pos) const;
  // 返回集合中元素的个数.
  size_t size() const;
private:
  std::vector<T> data;
};

template <typename T>
unordered_vector_with_large_capacity<T>
  ::unordered_vector_with_large_capacity()
{
  // 为其设置较大容量, 初始向量长度定为3142, 元素个数定为0.
  data.reserve(3142);
}

template <typename T>
void unordered_vector_with_large_capacity<T>::
  insert(const T& key)
{
  // 在data末尾加入新元素key.
  data.push_back(key);
}

template <typename T>
void unordered_vector_with_large_capacity<T>::
  erase(size_t pos)
{
  // 注意执行erase的前提是size() > 0.
  data[pos] = data.back();
  // 删除向量末尾元素.
  data.pop_back();
}

template <typename T>
size_t unordered_vector_with_large_capacity<T>::
  find(const T& key) const
{
  // 采用线性查找获取所在位置下标, 通过调用std::find函数实现.
  return std::find(data.cbegin(), data.cend(), key) - data.cbegin();
}

template <typename T>
size_t unordered_vector_with_large_capacity<T>::
  maximum_at() const
{
  size_t max_pos = 0;
  // for循环的设置可保证集合为空时返回正确值.
  for (size_t i = 1; i < data.size(); i++)
    if (data[max_pos] < data[i])
      max_pos = i;
  return max_pos;
}

template <typename T>
size_t unordered_vector_with_large_capacity<T>::
  minimum_at() const
{
  size_t min_pos = 0;
  // for循环的设置可保证集合为空时返回正确值.
  for (size_t i = 1; i < data.size(); i++)
    if (data[i] < data[min_pos])
      min_pos = i;
  return min_pos;
}

template <typename T>
const T& unordered_vector_with_large_capacity<T>::
  operator()(size_t pos) const
{
  return data[pos];
}

template <typename T>
size_t unordered_vector_with_large_capacity<T>::
  size() const
{
  return data.size();
}

#endif  // xUNORDEREDVECTOR_H
