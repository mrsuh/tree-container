/* 
 * File:   multiTree.h
 * Author: damin
 *
 * Created on September 17, 2014, 9:52 PM
 */

#ifndef MULTITREE_H
#define	MULTITREE_H

#include <iostream>
#include "Node.h"

        
template <class KEYTYPE, class DATATYPE>
class multiTree : public order<KEYTYPE, DATATYPE>{
    private:
        
        void inorder(Node<KEYTYPE, DATATYPE>* n);
        Node<KEYTYPE, DATATYPE>* root;
        unsigned int capacity;
        unsigned int count;
    public:
        multiTree();
        int insert_elem(const KEYTYPE &my_key, const DATATYPE &my_data);
        int remove_elem(const KEYTYPE &my_key);
        Node<KEYTYPE, DATATYPE>* min_elem();
        Node<KEYTYPE, DATATYPE>* max_elem();
        Node<KEYTYPE, DATATYPE>* find_elem(const KEYTYPE &my_key);
        void setPostorder();
        order<KEYTYPE, DATATYPE> getValue(const unsigned int &count);
        unsigned int getSize();
        
    private: order<KEYTYPE, DATATYPE> *dat;
};

template <class KEYTYPE, class DATATYPE>
multiTree<KEYTYPE, DATATYPE>::multiTree(){
    root = NULL;
    count = 0;
    capacity = 0;
}


template <class KEYTYPE, class DATATYPE>
int multiTree<KEYTYPE, DATATYPE>::insert_elem(const KEYTYPE &my_key,const DATATYPE &my_data){
    Node<KEYTYPE, DATATYPE>* ptr;
    Node<KEYTYPE, DATATYPE>* ptr2;
    Node<KEYTYPE, DATATYPE>* node = new Node<KEYTYPE, DATATYPE>(my_key, my_data);//создали узел

    capacity++;//увеличим счетчик на еденицу

    ptr = root;//начнем искать с корня
    ptr2 = 0;
    
    while(ptr!=0){
        ptr2 = ptr;
    if (my_key <= ptr->getKey())
        ptr = ptr->left;
    else if (my_key > ptr->getKey())
        ptr = ptr->right;
    }
    node->parent = ptr2;
    
    if(ptr2 == 0)
         root = node;
    else if(my_key <= ptr2->getKey())
        ptr2->left = node;
    else if(my_key > ptr2->getKey())
        ptr2->right = node;

        
  return 0;    
};

template <class KEYTYPE, class DATATYPE>
int multiTree<KEYTYPE, DATATYPE>::remove_elem(const KEYTYPE &my_key){
    if (root == 0)//нет дерева
        return 1;
    
    Node<KEYTYPE, DATATYPE>* ptr;
    Node<KEYTYPE, DATATYPE>* ptr2;

    ptr = 0;
    ptr2 = 0;
   
    ptr = find_elem(my_key);//найдем узел, который необходимо удалить
    if(ptr == NULL)
        return 1;

    capacity--; //уменьшим счетчик на еденицу
    if((ptr->left == 0) && (ptr->right == 0)){//в узле нет детей
       if((ptr->parent)->left== ptr )//удалим на него ссылку из родителя
            (ptr->parent)->left = 0;
        else 
            (ptr->parent)->right = 0;
        delete ptr;
        return 0;
    }
    
    
    
     
    if(ptr->left == 0){//в узле нет только левого ребенка
        (ptr->right)->parent = ptr->parent;
        
        if((ptr->parent)->right == ptr)
            (ptr->parent)->right = ptr->right;
        else
            (ptr->parent)->left = ptr->right;
    delete ptr;
    return 0;
    }
    
    if(ptr->right == 0){//в узле нет только правого ребенка
        (ptr->left)->parent = ptr->parent;
        
        if((ptr->parent)->right == ptr)
            (ptr->parent)->right = ptr->left;
        else
            (ptr->parent)->left = ptr->left;
    delete ptr;
    return 0;
    }
    
    
    
   
    if ((ptr->right)->left == 0){//если у правого узла нет левого ребенка
        (ptr->right)->parent = ptr->parent;
        (ptr->right)->left = ptr->left;
        delete ptr;
        return 0;
    }
    
    else{
        ptr2 = ptr->right;
        while(ptr2->left!=0){//найдем самого левого ребенка правого узла
            ptr2 = ptr2->left;
        }
        DATATYPE d_temp = ptr2->getData();
        KEYTYPE k_temp = ptr2->getKey();
        remove_elem(k_temp);//рекурсивно удалим ненужноый элемент
        ptr->key = k_temp;
        ptr->data = d_temp;
        return 0;
}
}

template<class KEYTYPE, class DATATYPE>
Node<KEYTYPE, DATATYPE>* multiTree<KEYTYPE, DATATYPE>::find_elem(const KEYTYPE& my_key){// находим элемент по ключу
    Node<KEYTYPE, DATATYPE>* ptr;
    
    if(root == 0)//если нет корня
        return NULL;
    
    else{
    ptr = root;
    
    while(my_key != ptr->getKey()){
        
        if(my_key < ptr->getKey())
            ptr = ptr->left;
        else
            ptr = ptr->right;
        
        if(ptr == 0)//если нет такого значения
            return NULL;
        }
    }
    return ptr;
}

template<class KEYTYPE,class DATATYPE>
Node<KEYTYPE, DATATYPE>* multiTree<KEYTYPE, DATATYPE>::max_elem(){//самый правый узел - максимальный
   Node<KEYTYPE, DATATYPE>* ptr;
   if(root == 0){//если нет корня
       return NULL;
    }
   else{
    ptr = root;
    while(ptr->right!=0)
        ptr = ptr->right;
   }
    return ptr;
}

template<class KEYTYPE,class DATATYPE>
Node<KEYTYPE, DATATYPE>* multiTree<KEYTYPE, DATATYPE>::min_elem(){//самый левый узел - минимальный
   Node<KEYTYPE, DATATYPE>* ptr;
   if(root == 0)//если нет корня
            return NULL;
   else{
    ptr = root;
    while(ptr->left!=0)
        ptr = ptr->left;
   }
    return ptr;
}

template<class KEYTYPE,class DATATYPE>
unsigned int multiTree<KEYTYPE, DATATYPE>::getSize(){//узнаем количество узлов в дереве
    return capacity;
}

template <class KEYTYPE, class DATATYPE>
void multiTree<KEYTYPE, DATATYPE>::inorder(Node<KEYTYPE, DATATYPE>* n){
    if(n->left != NULL)
        inorder(n->left);
    {
    dat[count].data = n->data;
    dat[count].key = n->key;
    count++;
    }
    if(n->right != NULL)
        inorder(n->right); 
 }


template<class KEYTYPE, class DATATYPE>
void multiTree<KEYTYPE, DATATYPE>::setPostorder(){
    dat = new order<KEYTYPE, DATATYPE>[capacity];
    count = 0;
    if(root->left != NULL){

    inorder(root->left);
    }
    
    dat[count].data = root->data;
    dat[count].key = root->key;
    count++;
    if (root->right != NULL){
    inorder(root->right);
    }
}

template<class KEYTYPE, class DATATYPE>
order<KEYTYPE, DATATYPE> multiTree<KEYTYPE, DATATYPE>::getValue(const unsigned int &count){
    if(count <= capacity)
    return dat[count];
}

#endif	/* MULTITREE_H */

