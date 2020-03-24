#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  m_root = nullptr;
  copyNode = nullptr;
  out = "";
  m_key = -1;
  m_count = 0;
}

BinaryTree::~BinaryTree()
{
  clear();
}

void BinaryTree::addItem(int entry)
{
  recAdd(entry, m_root);
}

void BinaryTree::recAdd(int entry, BinaryNode<int>* curPtr)
{
  if(m_root == nullptr)
  {
    m_root = new BinaryNode<int>(entry);
  }
  else if(entry < curPtr->getEntry())
  {
    if(curPtr->getLeft() == nullptr)
    {
      BinaryNode<int>* temp = new BinaryNode<int>(entry);
      curPtr->setLeft(temp);
    }
    else
    {
      recAdd(entry, curPtr->getLeft());
    }
  }
  else if(entry >= curPtr->getEntry())
  {
    if(curPtr->getRight() == nullptr)
    {
      BinaryNode<int>* temp = new BinaryNode<int>(entry);
      curPtr->setRight(temp);
    }
    else
    {
      recAdd(entry, curPtr->getRight());
    }
  }
}

void BinaryTree::deleteItem(int entry)
{
  if(search(entry))
  {
    m_root = recRemove(entry, m_root);
  }
  else
  {
    throw(std::runtime_error("Entry does not exist\n"));
  }
}

BinaryNode<int>* BinaryTree::removeNode(BinaryNode<int>* curPtr)
{
  BinaryNode<int>* temp = curPtr;
  while(temp && temp->getLeft() != nullptr)
  {
    temp = temp->getLeft();
  }
  return temp;
}

BinaryNode<int>* BinaryTree::recRemove(int entry, BinaryNode<int>* curPtr)
{
  if(curPtr == nullptr)
  {
    return curPtr;
  }
  if(curPtr->getEntry() > entry)
  {
    curPtr->setLeft(recRemove(entry, curPtr->getLeft()));
  }
  else if(curPtr->getEntry() < entry)
  {
    curPtr->setRight(recRemove(entry, curPtr->getRight()));
  }
  else
  {
    if(curPtr->getLeft() == nullptr)
    {
      BinaryNode<int>* temp = curPtr->getRight();
      delete curPtr;
      return temp;
    }
    else if(curPtr->getRight() == nullptr)
    {
      BinaryNode<int>* temp = curPtr->getLeft();
      delete curPtr;
      return temp;
    }
    BinaryNode<int>*  minNode = removeNode(curPtr->getRight());
    int successor = minNode->getEntry();
    curPtr->setEntry(minNode->getEntry());
    curPtr->setRight(recRemove(successor, curPtr->getRight()));
  }
  return curPtr;
}
bool BinaryTree::search(int entry)
{
  bool temp = false;
  try
  {
    if(entry == recSearch(entry, m_root))
    {
      temp = true;
    }
  }
  catch(std::runtime_error &rte)
  {
    std::cout << rte.what() << '\n';
  }
  return temp;
}

int BinaryTree::recSearch(int entry, BinaryNode<int>* curPtr)
{
  if(curPtr->getEntry() == entry)
  {
    return curPtr->getEntry();
  }
  else if(curPtr->getEntry() > entry)
  {
    if(curPtr->getLeft() != nullptr)
    {
      return recSearch(entry, curPtr->getLeft());
    }
  }
  else if(curPtr->getEntry() < entry)
  {
    if(curPtr->getRight() != nullptr)
    {
      return recSearch(entry, curPtr->getRight());
    }
  }
  throw(std::runtime_error("No entry matched\n"));
}

void BinaryTree::clear()
{
  if(m_root != nullptr)
  {
    recClear(m_root);
  }
}

void BinaryTree::recClear(BinaryNode<int>* curPtr)
{
  if(curPtr != nullptr)
  {
    recClear(curPtr->getLeft());
    recClear(curPtr->getRight());
    delete curPtr;
  }
}

int BinaryTree::InorderSuccessor(int entry)
{
  if(search(entry))
  {
    copyNode = InorderSuccessorHelper(entry, m_root);
  }
  else
  {
    throw(std::runtime_error("Cant get InorderSuccessor\n"));
  }
  return copyNode->getEntry();
}

BinaryNode<int>* BinaryTree::InorderSuccessorHelper(int entry, BinaryNode<int>* curPtr)
{
  BinaryNode<int>* temp = nullptr;
  if(!curPtr)
  {
    return nullptr;
  }

  while(curPtr->getEntry() != entry)
  {
    if(curPtr->getEntry() > entry)
    {
      temp = curPtr;
      curPtr= curPtr->getLeft();
    }
    else
    {
      curPtr = curPtr->getRight();
    }
  }
  if(curPtr && curPtr->getRight())
  {
    temp = minFinder(curPtr->getRight());
  }
  return temp;
}

BinaryNode<int>* BinaryTree::minFinder(BinaryNode<int>* curPtr)
{
  if(!curPtr)
  {
    return nullptr;
  }
  while(curPtr->getLeft())
  {
    curPtr = curPtr->getLeft();
  }
  return curPtr;
}

int BinaryTree::getHeight(BinaryNode<int>* curPtr)
{
  if(curPtr == nullptr)
  {
    return 0;
  }
  else
  {
    int left = getHeight(curPtr->getLeft());
    int right = getHeight(curPtr->getRight());
    if(left > right)
    {
      return left + 1;
    }
    else
    {
      return right + 1;
    }
  }
}
std::string BinaryTree::level_order()
{
  out = "";
  for(int i = 1; i <= getHeight(m_root); i++)
  {
    recLevel(i, m_root);
  }
  if(m_root != nullptr && out.size() != 0)
  {
    out.resize(out.size() - 1);
  }
  return out;
}

void BinaryTree::recLevel(int level, BinaryNode<int>* curPtr)
{
  if(curPtr != nullptr)
  {
    if(level == 1)
    {
      out = out + std::to_string(curPtr->getEntry()) + ',';
    }
    else if(level > 1)
    {
      recLevel(level - 1, curPtr->getLeft());
      recLevel(level - 1, curPtr->getRight());
    }
  }
}

std::string BinaryTree::spiral_level_order()
{
  out = "";
  for(int i = 1; i <= getHeight(m_root); i++)
  {
    if(i % 2 == 0)
    {
      recSpiral(i, m_root);
    }
    else
    {
      recLevel(i, m_root);
    }
  }
  if(m_root != nullptr && out.size() != 0)
  {
    out.resize(out.size() - 1);
  }
  return out;
}

void BinaryTree::recSpiral(int level, BinaryNode<int>* curPtr)
{
  if(curPtr != nullptr)
  {
    if(level == 1)
    {
      out = out + std::to_string(curPtr->getEntry()) + ',';
    }
    else if(level > 1)
    {
      recSpiral(level - 1, curPtr->getRight());
      recSpiral(level - 1, curPtr->getLeft());
    }
  }
}

std::string BinaryTree::LeftSideView()
{
  out = "";
  BinaryNode<int>* temp = m_root;
  while(temp)
  {
    out = out + std::to_string(temp->getEntry()) + ',';
    temp = temp->getLeft();
  }
  if(m_root != nullptr && out.size() != 0)
  {
    out.resize(out.size() - 1);
  }
  return out;
}

std::string BinaryTree::RightSideView()
{
  out = "";
  BinaryNode<int>* temp = m_root;
  while(temp)
  {
    out = out + std::to_string(temp->getEntry()) + ',';
    temp = temp->getRight();
  }
  if(m_root != nullptr && out.size() != 0)
  {
    out.resize(out.size() - 1);
  }
  return out;
}

std::string BinaryTree::kthSmallItem(int entry)
{
  m_count = 0;
  out = "";
  entry--;
  if(entry < 0)
  {
    throw(std::runtime_error("Entry is not valid\n"));
  }
  m_key = entry;
  inorder(m_root);

  return out;
}

void BinaryTree::inorder(BinaryNode<int>* curPtr)
{
  if(curPtr != nullptr)
  {
    inorder(curPtr->getLeft());
    if(m_count < m_key)
    {
      out = std::to_string(curPtr->getEntry());
      m_count++;
    }
    inorder(curPtr->getRight());
  }
}
