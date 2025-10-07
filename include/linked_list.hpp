
#pragma once
#include <cstddef>
#include <print>
#include <stdexcept>
#include <cstring>

#include "list.hpp"


template <typename T>
class Node {
private:
	Node* m_prev;
	Node* m_next;
	T m_data;
};

template <typename T>
class LinkedList : public List<T> {
public:

size_t length() const {
    return this->m_size;
}

// void push_front(const T& element) {
    
// }

// void push_back(const T& element) {
   
// }

// T pop_back() {
    
// }

// T pop_front() {
    
// } 

// void insert(const size_t index, const T& element) {
    
// }

// T remove(const size_t index) {
    
// }

bool is_empty() const {
    if (this->m_size == 0) {
        if (this->m_head == nullptr && this->m_tail == nullptr) {
            return true;
        }
        return true;
    }

    return false;
}

const T& get(const size_t index) const {
    if (index >= this->m_size) {
        throw std::out_of_range("index is out of bounds");
    }

    Node<T>* current = this->m_head;
    for (size_t i = 0; i < index; ++i) {
        current = current->m_next;
    }

    return current->m_data;
}

const T& get_first() const {
    if (this->m_size == 0 || this->m_head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    return this->m_head->m_data;
}

const T& get_last() const {
    if (this->m_size == 0 || this->m_tail == nullptr) {
        throw std::out_of_range("List is empty");
    }
    return this->m_tail->m_data;
}

private:
	Node<T>* m_head;
	Node<T>* m_tail;
	size_t m_size;
};