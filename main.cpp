#include <cstdlib>
#include <cstring>
#include "Tree.h"
#include "multiTree.h"
#include "fstream"

using namespace std;


int main() {
    unsigned int size = 512;//размер массива для getline
    char line[size];//массив для getline
    char *tmp;//указатель для передачи в strtok()
    const char delim[] = "-., ;:?!";//разделители
    Tree<string, int> tree;//создадим объект Tree
    multiTree<int, string> multitree;//создадим объект multiTree
    
    
    ifstream file("/home/damin/1.txt");//файл откуда мы считываем
    ofstream outAlphabet("/home/damin/2.txt");//файл куда мы записываем слова в виде: слово | кол-во вхождений
    ofstream outNumbers("/home/damin/3.txt");//файл куда мы записываем слова в виде:  кол-во вхождений слова
 
    while(file.getline(line, size)){//пока не конец строки
        tmp = std::strtok(line,delim);//разделяет по словам 
    while(tmp!=NULL){
    tree.insert_elem(tmp,1);//добавим элемент в узел
    tmp = strtok(NULL,delim);
        }
    }
    
    tree.setPostorder();//функция класса Tree для обхода дерева от младшего элемента к старшему
     
    cout<<"\nVALUE: ABC";
    for (int i = 0; i < tree.getSize(); i++){
    outAlphabet<<"\n--|"<<tree.getValue(i).key<<" : "<<tree.getValue(i).data;
    multitree.insert_elem(tree.getValue(i).data, tree.getValue(i).key);//заносим готовые данные в класс multiTree
    }
    
    multitree.setPostorder();
    
    cout<<"\nVALUE: 123";
    for (int i = multitree.getSize()-1; i >=0 ; i--){
    outNumbers<<"\n--|"<<multitree.getValue(i).key<<" : "<<multitree.getValue(i).data;
    }
    
    
    return 0;
}

