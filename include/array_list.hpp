
#pragma once

#include <print>
#include <stdexcept>
#include <cstring>
#include <cstddef>

#include "list.hpp"

template <typename T>
class ArrayList : public List<T> {
public:
	size_t length() const {
		return this->m_size;
	}

	size_t capacity() const {
		return this->m_capacity;
	}

	void push_back(const T& element) {
		if (this->m_size >= this->m_capacity) {
			this->reallocate();
		}

		this->m_data[this->m_size] = element;
		this->m_size += 1;
	}

	void push_front(const T& element) {
		if (this->m_size >= this->m_capacity) {
			this->reallocate();
		}

		std::memmove(this->m_data + 1, this->m_data, this->m_size * sizeof(T));
		this->m_data[0] = element;
		this->m_size += 1;
	}

	const T& get(const size_t index) const {
		if (index >= this->length()) {
			throw std::out_of_range("index is out of bounds");
		}
		return this->m_data[index];
	}

	const T& get_first() const {
		if (this->is_empty()) {
			throw std::out_of_range("List is empty");
		}
		return this->get(0);
	}

	const T& get_last() const {
		if (this->is_empty()) {
			throw std::out_of_range("List is empty");
		}
		return this->get(this->length() - 1);
	}

	T pop_front() {
		if (this->is_empty()) {
			throw std::out_of_range("List is empty");
		}
		T first = this->get_first();
		std::memmove(this->m_data, this->m_data + 1, this->length() * sizeof(T));
		this->m_size -= 1;
		return first;
	}

	T pop_back() {
		if (this->is_empty()) {
			throw std::out_of_range("List is empty");
		}
		T last = this->get_last();
		this->m_size -= 1;
		return last;
	}

	void insert(const size_t index, const T& element) {
		if (index >= this->length()) {
			this->push_back(element);
		}

		std::memmove(this->m_data + index + 1, this->m_data + index,
				(this->length() - index) * sizeof(T));
		this->m_data[index] = element;
	}

	T remove(const size_t index) {
		if (index >= this->length()) {
			throw std::out_of_range("index is out of bounds");
		}
		auto tmp = this->get(index);
		std::memmove(this->m_data + index, this->m_data + index + 1,
				(this->length() - index - 1) * sizeof(T));
		return tmp;
	}

	bool is_empty() const {
		if (this->length() == 0) {
			return true;
		}
		return false;
	}

	ArrayList() {
		std::println("constructor");
		this->m_data = new T[4];
		this->m_size = 0;
		this->m_capacity = 4;
	}

	ArrayList(const size_t capacity) {
		std::println("constructor with capacity");
		this->m_data = new T[capacity];
		this->m_size = 0;
		this->m_capacity = capacity;
	}

	~ArrayList() {
		delete[] this->m_data;
		this->m_data = nullptr;
		this->m_capacity = 0;
		this->m_size = 0;
		std::println("destructor");
	}

private:
	void reallocate() {
		size_t new_capacity = this->m_capacity * 2;
		if (new_capacity == 0) {
			new_capacity = 4;
		}
		auto new_data = new T[new_capacity];

		//std::memcpy
		for (size_t i = 0; i < this->m_size; i++) {
			new_data[i] = this->m_data[i];
		}

		delete[] this->m_data;
		this->m_data = new_data;
		this->m_capacity = new_capacity;
	}

private:
	T* m_data;
	size_t m_size;
	size_t m_capacity;
};

// template <typename T>
// size_t ArrayList<T>::length() const {
// 	return this->m_length;
// }

// template <typename T>
// size_t ArrayList<T>::capacity() const {
// 	return this->m_capacity;
// }

// template <typename T>
// void ArrayList<T>::push_back(const T& element) {
// 	if (this->m_length >= this->m_capacity) {
// 		this->reallocate();
// 	}

// 	this->m_data[this->m_length] = element;
// 	this->m_length += 1;
// }

// template <typename T>
// void ArrayList<T>::push_front(const T& element) {
// 	if (this->m_length >= this->m_capacity) {
// 		this->reallocate();
// 	}

// 	std::memmove(this->m_data + 1, this->m_data, this->m_length * sizeof(T));
// 	this->m_data[0] = element;
// 	this->m_length += 1;
// }

// template <typename T>
// const T& ArrayList<T>::get(const size_t index) const {
// 	if (index >= this->length()) {
// 		throw std::out_of_range("index is out of bounds");
// 	}
// 	return this->m_data[index];
// }

// template <typename T>
// const T& ArrayList<T>::get_first() const {
// 	if (this->is_empty()) {
// 		throw std::out_of_range("List is empty");
// 	}
// 	return this->get(0);
// }

// template <typename T>
// const T& ArrayList<T>::get_last() const {
// 	if (this->is_empty()) {
// 		throw std::out_of_range("List is empty");
// 	}
// 	return this->get(this->length() - 1);
// }

// template <typename T>
// T ArrayList<T>::pop_front() {
// 	if (this->is_empty()) {
// 		throw std::out_of_range("List is empty");
// 	}
// 	auto first = this->get_first();
// 	std::memmove(this->m_data, this->m_data + 1, this->length() * sizeof(T));
// 	this->m_length -= 1;
// 	return first;
// }

// template <typename T>
// T ArrayList<T>::pop_back() {
// 	if (this->is_empty()) {
// 		throw std::out_of_range("List is empty");
// 	}
// 	auto last = this->get_last();
// 	this->m_length -= 1;
// 	return last;
// }

// template <typename T>
// void ArrayList<T>::insert(const size_t index, const T& element) {
// 	if (index >= this->length()) {
// 		this->push_back(element);
// 	}

// 	std::memmove(
// 			this->m_data + index + 1, this->m_data + index, (this->length() - index) * sizeof(T));
// 	this->m_data[index] = element;
// }

// template <typename T>
// T ArrayList<T>::remove(const size_t index) {
// 	if (index >= this->length()) {
// 		throw std::out_of_range("index is out of bounds");
// 	}
// 	auto tmp = this->get(index);
// 	std::memmove(this->m_data + index, this->m_data + index + 1,
// 			(this->length() - index - 1) * sizeof(T));
// 	return tmp;
// }

// template <typename T>
// bool ArrayList<T>::is_empty() const {
// 	if (this->length() == 0) {
// 		return true;
// 	}
// 	return false;
// }

// template <typename T>
// ArrayList<T>::ArrayList() {
// 	std::println("constructor");
// 	this->m_data = new T[4];
// 	this->m_length = 0;
// 	this->m_capacity = 4;
// }

// template <typename T>
// ArrayList<T>::ArrayList(const size_t capacity) {
// 	std::println("constructor with capacity");
// 	this->m_data = new T[capacity];
// 	this->m_length = 0;
// 	this->m_capacity = capacity;
// }

// template <typename T>
// ArrayList<T>::~ArrayList() {
// 	delete[] this->m_data;
// 	this->m_data = nullptr;
// 	this->m_capacity = 0;
// 	this->m_length = 0;
// 	std::println("destructor");
// }

// template <typename T>
// void ArrayList<T>::reallocate() {
// 	size_t new_capacity = this->m_capacity * 2;
// 	if (new_capacity == 0) {
// 		new_capacity = 4;
// 	}
// 	auto new_data = new T[new_capacity];

// 	//std::memcpy
// 	for (size_t i = 0; i < this->m_length; i++) {
// 		new_data[i] = this->m_data[i];
// 	}

// 	delete[] this->m_data;
// 	this->m_data = new_data;
// 	this->m_capacity = new_capacity;
// }
