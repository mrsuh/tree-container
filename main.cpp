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
    char *tmp;
    
    ifstream file("/home/damin/1.txt");
    ofstream file2("/home/damin/2.txt");
 
    while(file.getline(line, size)){//пока не конец строки
        tmp = std::strtok(line,delim);//разделяет по словам 
    while(tmp!=NULL){
    tree.insert_elem(tmp,1);//добавим элемент в узел
    tmp = strtok(NULL,delim);
        }
    }
     /*
    tree.insert_elem(50,1);
    for(int i=0; i<100; i++)
    tree.insert_elem(i,1);
    */
    tree.setPostorder();
     
    std::cout<<"\nVALUE:";
    for (int i = 0; i < tree.getSize(); i++)
    file2<<"\n--|"<<tree.getValue(i).key<<" : "<<tree.getValue(i).data;
    
   
    
    return 0;
}

