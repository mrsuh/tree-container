/* 
 * File:   main.cpp
 * Author: damin
 *
 * Created on September 15, 2014, 8:45 PM
 */


#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Tree.h"
#include "fstream"
#include <string>
using namespace std;

/*
 * 
 */
int main() {
    unsigned int size = 512;//размер массива для getline
    char line[size];//массив для getline
    const char delim[] = "-., ;:?!";//разделители
    Tree<string, int> tree;//создадим объект Tree
    Node<string, int> *NodePtr;
    char *tmp;
    
    ifstream file("/home/damin/1.txt");
    
    while(file.getline(line, size)){//пока не конец строки
        tmp = std::strtok(line,delim);//разделяет по словам 
    while(tmp!=NULL){
    tree.insert_elem(tmp,1);//добавим элемент в узел
    tmp = strtok(NULL,delim);
        }
    }
    
    
    
    
    
    tree.setPostorder();
    std::cout<<"\nVALUE:";
    for (int i = 0; i >= tree.getSize(); i++)
    std::cout<<tree.getValue(i).key<<" :"<<tree.getValue(i).data<<"\n";
    
   
    
    return 0;
}

