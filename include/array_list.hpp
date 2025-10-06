
#pragma once
#include <cstddef>

#include "list.hpp"

template <typename T>
class ArrayList : public List<T> {
public:
	ArrayList();
	ArrayList(const size_t capacity);
	~ArrayList();
	size_t length() const;
	size_t capacity() const;
	void push_front(const T& element);
	void push_back(const T& element);
	T pop_back();
	T pop_front();
	void insert(const size_t index, const T& element);
	T remove(const size_t index);
	const T& get(const size_t index) const;
	const T& get_first() const;
	const T& get_last() const;
	bool is_empty() const;

private:
	void reallocate();

private:
	T* m_data;
	size_t m_length;
	size_t m_capacity;
};