/*
Author: Haonan Hu
File: Executive.cpp
Date:3/10/2020
Brief:File is cpp file
*/
#include "Executive.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <limits>

executive::executive(std::string fileName)
{
  std::ifstream infile;
  int data;

  infile.open(fileName);
  if(infile.is_open())  //  file read successful
  {
    while(infile >> data)
    {
      m_tree.addItem(data);
    }
    std::cout << "\e[1mFile reading done, ready for next step:\e[0m\n";
    std::cout << "..................................\n\n";
  }
  else
    std::cout << "Unable to open file\n";
}

executive::~executive(){}

void executive::run()
{
  int choice;
  for(;;)
  {
    std::cout << "make a selection: \n";
    std::cout << "1) Add Item\n";
    std::cout << "2) Delete Item\n";
    std::cout << "3) Inorder Successor\n";
    std::cout << "4) Level Order\n";
    std::cout << "5) Spiral Level Order\n";
    std::cout << "6) Left Side View\n";
    std::cout << "7) Right Side View\n";
    std::cout << "8) Kth Smallest Item\n";
    std::cout << "9) Exit\n";
    std::cin >> choice;
    std::cout << '\n';
    while(1)
    {
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input!\n\n";
        std::cout << "..................................\n\n";
        std::cout << "Choose one operation from the options below: \n\n";
        std::cout << "make a selection: \n";
        std::cout << "1) Add Item\n";
        std::cout << "2) Delete Item\n";
        std::cout << "3) Inorder Successor\n";
        std::cout << "4) Level Order\n";
        std::cout << "5) Spiral Level Order\n";
        std::cout << "6) Left Side View\n";
        std::cout << "7) Right Side View\n";
        std::cout << "8) Kth Smallest Item\n";
        std::cout << "9) Exit\n";
        std::cin >> choice;
        std::cout << '\n';
      }
      if(!std::cin.fail())
        break;
    }
    if(choice == 1)
    {
      int input;
      std::cout << "Enter the element to be added: ";
      std::cin >> input;
      m_tree.addItem(input);
      std::cout << "Element " << input << " was successfully added\n";
    }
    else if(choice == 2)
    {
      int input;
      std::cout << "Enter the element to be deleted: ";
      std::cin >> input;
      m_tree.deleteItem(input);
      std::cout << "Element " << input << " was successfully deleted\n";
    }
    else if(choice == 3)
    {
      int input;
      std::cout << "Enter the element to which you want to know the inorder successor: ";
      std::cin >> input;
      try
      {
          std::cout << "here\n";
          int temp = m_tree.InorderSuccessor(input);
          std::cout << "The inorder successor of " << input << " is " << temp << '\n';
      }
      catch (std::runtime_error &rte)
      {
          std::cout << rte.what() << '\n';
      }
    }
    else if(choice == 4)
    {
      std::cout << "Level order: " << m_tree.level_order() << '\n';
    }
    else if(choice == 5)
    {
      std::cout << "Spiral Level order: " << m_tree.spiral_level_order() << '\n';
    }
    else if(choice == 6)
    {
      std::cout << "Left side view: " << m_tree.LeftSideView() << '\n';
    }
    else if(choice == 7)
    {
      std::cout << "Right side view: " << m_tree.RightSideView() << '\n';
    }
    else if(choice == 8)
    {
      int input;
      std::cout << "Enter the value of k: ";
      std::cin >> input;
      try
      {
          std::cout << m_tree.kthSmallItem(input) << '\n';
      }
      catch(std::runtime_error& rte)
      {
          std::cout << rte.what() << '\n';
      }
    }
    else if(choice == 9)
    {
      std::cout << "Program execution complete!\n";
      break;
    }
    else
    {
      std::cout << " Wrong input!\n\n";
      std::cout << "..................................\n\n";
    }
  }
}
