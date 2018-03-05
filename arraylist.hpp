//Programmer: Michael Ward
//Section: B
//Date: 2/22/16
//Filen Name: arraylist.hpp

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#include <iostream>


template<typename T>
ArrayList<T>::ArrayList(int s, const T& x)
{
  m_size = s;
  m_max = s+10;
  m_data = new T[m_max];
  for (int k = 0; k < m_size; k++)
    m_data[k] = x;
}

template<typename T>
ArrayList<T>::~ArrayList()
{
  clear();
}

template<typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  if (this != &rhs)
  {
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    delete [] m_data;
    m_data = new T[m_max];
    for (int k = 0; k < m_size; k++)
      m_data[k] = rhs.m_data[k];

  }
  return *this;
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_data = NULL;
  *this = cpy;
}

template<typename T>
void ArrayList<T>::insert(const T&x, int i)
{
  if (i < 0 || i > m_size)
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)" << std::endl;
    return;
  }
  //if m_size = 0
  if (m_size == 0)
  {
    m_max = 1;
    m_data = new T[m_max];
  }

  //if m_size = m_max
  else if (m_size == m_max)
  {
    m_max *= 2;
    T* tmp = new T[m_max];
    for (int k = 0; k < m_size; k++)
      tmp[k] = m_data[k];
    delete [] m_data;
    m_data = tmp; 
  }

  for (int k = m_size; k > i; k--)
    m_data[k] = m_data[k-1];
  m_data[i] = x;

  m_size++;
  return;
} 


template<typename T>
int ArrayList<T>::size() const
{
  return m_size;
}


template<typename T>
void ArrayList<T>::clear()
{
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max=0;
}

template<typename T>
int ArrayList<T>::find(const T&x) const
{
  int loc = -1, pos = 0;
  while (loc == -1 && pos < m_size)
  {
    if (m_data[pos] == x)
      loc = pos;
    pos++;
  }
  return loc;
}

template<typename T>
const T& ArrayList<T>::first() const
{
  if (m_size != 0)
    return m_data[0];
  std::cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)" << std::endl;
  return m_errobj;
}

template<typename T>
T& ArrayList<T>::operator[](int i)
{
  if (i < m_size && i >= 0)
    return m_data[i];
  std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << std::endl;
  return m_errobj;
}

template<typename T>
const T& ArrayList<T>::operator[](int i) const
{
  if (i < m_size && i >= 0)
    return m_data[i];
  std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << std::endl;
  return m_errobj;
}

template<typename T>
void ArrayList<T>::insert_back(const T& x)
{
  insert(x, m_size);
  return;
}

template<typename T>
void ArrayList<T>::swap(int i, int k)
{
  if (i >= 0 && i < m_size && k >= 0 && k < m_size )
  {
    T tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
  }
  else
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)" << std::endl;
  return;
}

template<typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  for (int k = 0; k < alist.m_size; k++)
    insert_back(alist.m_data[k]);
  return;
}

template<typename T>
void ArrayList<T>::remove(int i)
{
  if (i >= 0 && i < m_size)
  {
    for (int pos = i; pos < m_size -1; pos++)
      m_data[pos] = m_data[pos+1];
    m_size -= 1;
    //shrink array
    if (m_size < m_max/4)
    {
      m_max /= 2;
      T* tmp = new T[m_max];
      for (int k = 0; k < m_size; k++)
        tmp[k] = m_data[k];
      delete [] m_data;
      m_data = tmp;
    }
  }
  else
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)" << std::endl;
  return;
}

template<typename T>
void ArrayList<T>::resize(int s, const T& x)
{
  if (s != m_size)
  {
    if (s < m_size)
      while (s < m_size)
        remove(m_size - 1);
    else
      while (s > m_size)
        insert_back(x);
  }


  return;
}

#endif