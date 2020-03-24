#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "BinaryNode.h"

class BinaryTree
{
public:
  BinaryTree();// done
  ~BinaryTree();//done

  void addItem(int entry); //done
  void deleteItem(int entry);//done
  bool search(int entry); //done
  void clear(); //done

  std::string level_order(); //done
  std::string spiral_level_order(); //done
  std::string LeftSideView(); //done
  std::string RightSideView(); //done
  std::string kthSmallItem(int entry); //done

  int InorderSuccessor(int entry); // done
  int getHeight(BinaryNode<int>* curPtr);// done
private:
  BinaryNode<int>* m_root;
  int m_key;
  int m_count;
  std::string out;
  BinaryNode<int>* copyNode;

  void recAdd(int entry, BinaryNode<int>* curPtr); //done
  void recLevel(int level, BinaryNode<int>* curPtr); //done
  void recSpiral(int level, BinaryNode<int>* curPtr); //done
  void recClear(BinaryNode<int>* curPtr); //done
  int recSearch(int entry, BinaryNode<int>* curPtr); //done

  BinaryNode<int>* recRemove(int entry, BinaryNode<int>* curPtr); //done
  BinaryNode<int>* removeNode(BinaryNode<int>* curPtr); //done

  void inorder(BinaryNode<int>* curPtr);
  BinaryNode<int>* InorderSuccessorHelper(int entry, BinaryNode<int>* curPtr);//done
  BinaryNode<int>* minFinder(BinaryNode<int>* curPtr); //done
};
#endif
