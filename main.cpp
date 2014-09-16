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
using namespace std;

/*
 * 
 */
int main() {
    string word;//передаем в контейнер
    unsigned int size = 256;//размер массива для getline
    char line[size];//массив для getline
    char delim[] = " ,.:!;*";//разделители
    Tree<string, int> tree;//создадим объект Tree
    Node<string, int> *NodePtr;
    char *tmp;
    
    ifstream file("/home/damin/1.txt");//сам файл
    if(!file)//проверяем существует ли файл
        cout<<"file not found\n";
    
    while(!file.eof()){
        file.getline(line, size);//считывает строку из файла 
    tmp = std::strtok(line,delim);//разделяет по словам
    
    while(tmp!=NULL){
            tree.insert_elem(tmp,1);//добавим найденный узел
    tmp = strtok(NULL,delim);
    }
    }
    
    NodePtr = tree.find_elem("alf");
    if(NodePtr == NULL)
        std::cout<<"\nfind error";
    else
    std::cout<<"\n"<<NodePtr->getKey()<<" :"<<NodePtr->getData();
    NodePtr = tree.find_elem("beta");
    if(NodePtr == NULL)
        std::cout<<"\nfind error";
    else
    std::cout<<"\n"<<NodePtr->getKey()<<" :"<<NodePtr->getData();
    
    
    tree.setPostorder();
    for (int i = 0; i<tree.getSize(); i++)
    std::cout<<"\nk:"<<tree.getValue(i).key<<" :"<<tree.getValue(i).data;
    
 
    return 0;
}

