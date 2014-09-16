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
    char delim[] = " ,.:!;";//разделители
    Tree<string, int> tree;//контейнер Tree
    Node<string, int> *NodePtr;
    
    ifstream file("/home/damin/1.txt");//сам файл
    if(!file)//проверяем существует ли файл
        cout<<"file not found\n";
    
    while(!file.eof()){
        file.getline(line, size);//считывает строку из файла
        
        
        
    char* tmp = std::strtok(line,delim);//разделяет по словам
    while(tmp!=NULL){
        
        NodePtr = tree.find_elem(tmp);
        //if(NodePtr == NULL)//если такого элемента нет
            tree.insert_elem(tmp,1);//добавить его
        //else
            std::cout<<"+1";
        
      
    tmp = strtok(NULL,delim);
    }
    }
    
    NodePtr = tree.find_elem("hello");
    std::cout<<"\n"<<NodePtr->getKey()<<" :"<<NodePtr->getData()<<"\n";
    
    
        
    
    
    
    /*
    Tree<string, int> t;
    t.insert_elem("hello",3);
    Node<string, int>* ptr;
    ptr = t.find_elem("hello");
    if(ptr == NULL)
        cout<<"\nfind error";
    else
        cout<<"\nFk:"<<ptr->getKey()<<" Fd:"<<ptr->getData();
     */
    return 0;
}

