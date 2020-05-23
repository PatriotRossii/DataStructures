#include "DoubleLinkedList.h"

#include <iostream>

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this->root = nullptr;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    Node<T>* iterator = root;
    while(iterator != nullptr) {
        Node<T>* next_element = iterator->next;
        delete iterator;
        iterator = next_element;
    }
}

template<typename T>
Node<T>* DoubleLinkedList<T>::front() {
    return root;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::back() {
    Node<T>* iterator = root;
    while(iterator != nullptr && iterator->next != nullptr) {
        iterator = iterator->next;
    }
    return iterator;
}

template<typename T>
void DoubleLinkedList<T>::insert(T value, Node<T>* previous, Node<T>* next) {
    Node<T>* new_element = new Node<T>{value, previous, next};
    previous->next = new_element;
}

template<typename T>
void DoubleLinkedList<T>::push_back(T value) {
    if(root == nullptr) {
        this->root = new Node<T>{value, nullptr, nullptr};   
    } else {
        this->insert(value, this->back(), nullptr);
    }
}

template<typename T>
void DoubleLinkedList<T>::pop_back() {
    Node<T>* back = this->back();
    if(back->previous) {
        back->previous->next = nullptr;
    }
    if(back->next) {
        back->next->previous = nullptr;
    }
    if(back == root) {
        root = nullptr;
    }
    delete back;
}

int main() {
    DoubleLinkedList<int> list;

    list.push_back(5);
    list.push_back(0);

    std::cout << list.front()->value << '\n';
    std::cout << list.back()->value << '\n';

    list.pop_back();
    std::cout << list.front()->value << " " << list.back()->value << '\n';

    list.pop_back();
    std::cout << (list.front() == nullptr) << ' ' << (list.back() == nullptr) << '\n'; 
}
