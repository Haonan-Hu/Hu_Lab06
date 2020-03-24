/*
Author: Haonan Hu
File: BinaryNode.cpp
Date:3/10/2020
Brief:File is cpp file
*/
template <typename T>
BinaryNode<T>::BinaryNode(T entry)
{
  m_entry = entry;
  m_left = nullptr;
  m_right = nullptr;
}

template <typename T>
T BinaryNode<T>::getEntry()const
{
  return m_entry;
}

template <typename T>
void BinaryNode<T>::setEntry(T entry)
{
  m_entry = entry;
}

template <typename T>
BinaryNode<T>* BinaryNode<T>::getLeft()const
{
  return m_left;
}

template <typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* left)
{
  m_left = left;
}

template <typename T>
BinaryNode<T>* BinaryNode<T>::getRight()const
{
  return m_right;
}

template <typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* right)
{
  m_right = right;
}
