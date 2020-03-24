/*
Author: Haonan Hu
File: BinaryNode.h
Date:3/10/2020
Brief:File is header file
*/
#ifndef BINARY_NODE_H
#define BINARY_NODE_H
#include <string>

template <typename T>
class BinaryNode
{
public:
  BinaryNode(T entry);

  T getEntry()const;
  void setEntry(T entry);

  BinaryNode<T>* getLeft()const;
  void setLeft(BinaryNode<T>* left);

  BinaryNode<T>* getRight()const;
  void setRight(BinaryNode<T>* right);

private:
  T m_entry;
  BinaryNode<T>* m_left;
  BinaryNode<T>* m_right;
};
#include "BinaryNode.cpp"
#endif
