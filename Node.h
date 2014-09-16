/* 
 * File:   Node.h
 * Author: damin
 *
 * Created on September 15, 2014, 8:47 PM
 */

#ifndef NODE_H
#define	NODE_H
template<class KEYTYPE,class DATATYPE> class Tree;

template<class KEYTYPE,class DATATYPE>
class Node{
    friend class Tree<KEYTYPE, DATATYPE>;
private:
    KEYTYPE key;
    DATATYPE data;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node(const KEYTYPE &my_key, const DATATYPE &my_data); 
    KEYTYPE getKey();
    DATATYPE getData();
    
};

template <class KEYTYPE, class DATATYPE>
Node<KEYTYPE, DATATYPE>::Node(const KEYTYPE &my_key, const DATATYPE &my_data){
    key = my_key;
    data = my_data;
    left = 0;
    right = 0;
    parent = 0;
};

template <class KEYTYPE, class DATATYPE>
KEYTYPE Node<KEYTYPE, DATATYPE>::getKey(){
    return key;
}

template <class KEYTYPE, class DATATYPE>
DATATYPE Node<KEYTYPE, DATATYPE>::getData(){
    return data;
}
#endif	/* NODE_H */

