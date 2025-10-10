#pragma once
#include <cstddef>

template <typename T>
class List {
public:
	virtual size_t length() const = 0; //pure (= 0)
	virtual void push_front(const T& element) = 0;
	virtual void push_back(const T& element) = 0;
	virtual T pop_back() = 0;
	virtual T pop_front() = 0;
	virtual void insert(const size_t index, const T& element) = 0;
	virtual T remove(const size_t index) = 0;
	virtual bool is_empty() const = 0;
	virtual const T& get(const size_t index) const = 0;
	virtual T& get_mut(const size_t index) const = 0;
	virtual const T& get_first() const = 0;
	virtual const T& get_last() const = 0;
	virtual ~List() = default;
	//virtual bool is_sorted() const = 0;
	//sort ??
};
