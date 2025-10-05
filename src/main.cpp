#include <cstddef>
#include <print>
#include <optional>

template <typename T>
class List {
public:
	virtual size_t length() const = 0; //pure (= 0)
	virtual void push_front(const T &element) = 0;
	virtual void push_back(const T &element) = 0;
	virtual std::optional<T> pop_back() = 0;
	virtual std::optional<T> pop_front() = 0;
	virtual void insert(const size_t index, const T &element) = 0;
	virtual std::optional<T> remove(const size_t index) = 0;
	virtual bool is_empty() const = 0;
	virtual std::optional<const T &> get(const size_t index) const = 0;
	virtual std::optional<const T &> get_first() const = 0;
	virtual std::optional<const T &> get_last() const = 0;
	//virtual bool is_sorted() const = 0;
	//sort ??
};

template <typename T>
class ArrayList : public List<T> {
public:
	size_t length() const;
	size_t capacity() const;
	void push_front(const T &element);
	void push_back(const T &element);
	std::optional<T> pop_front();
	std::optional<T> pop_back();
	void insert(const size_t index, const T &element);
	std::optional<T> remove(const size_t index);
	std::optional<const T &> get(const size_t index) const;
	std::optional<const T &> get_first() const;
	std::optional<const T &> get_last() const;
	bool is_empty() const;

	ArrayList();
	ArrayList(const size_t capacity);
	~ArrayList();

private:
	T *m_data;
	size_t m_length;
	size_t m_capacity;
};

template <typename T>
size_t ArrayList<T>::length() const {
	return this->m_length;
}

template <typename T>
size_t ArrayList<T>::capacity() const {
	return this->m_capacity;
}

template <typename T>
void ArrayList<T>::push_back(const T &element) {
	if (this->m_length < this->m_capacity) {
		this->m_data[this->m_length] = element;
		this->m_length += 1;
		return;
	}

	size_t new_capacity = this->m_capacity * 2;
	if (new_capacity == 0) {
		new_capacity = 4;
	}
	auto new_data = new T[new_capacity * sizeof(element)];

	//std::memcpy
	for (size_t i = 0; i < this->m_length; i++) {
		new_data[i] = this->m_data[i];
	}

	delete[] this->m_data;
	this->m_data = new_data;
	this->m_capacity = new_capacity;

	this->m_data[this->m_length] = element;
	this->m_length += 1;
}

template <typename T>
void ArrayList<T>::push_front(const T &element) {
	if (this->m_length < this->m_capacity) {
		// this->m_data[this->m_length] = element;

		this->m_length += 1;
		return;
	}
}

template <typename T>
std::optional<const T> ArrayList<T>::get(const size_t index) const {
	if (index > this->length()){
		return std::nullopt;
	}
}

template <typename T>
bool ArrayList<T>::is_empty() const {
	if (this->length() == 0) {
		return true;
	}
	return false;
}

template <typename T>
ArrayList<T>::ArrayList() {
	std::println("constructor");
	this->m_data = new T[4];
	this->m_length = 0;
	this->m_capacity = 4;
}

template <typename T>
ArrayList<T>::ArrayList(const size_t capacity) {
	std::println("constructor with capacity");
	this->m_data = new T[capacity];
	this->m_length = 0;
	this->m_capacity = capacity;
}

template <typename T>
ArrayList<T>::~ArrayList() {
	delete[] this->m_data;
	this->m_data = nullptr;
	this->m_capacity = 0;
	this->m_length = 0;
	std::println("destructor");
}

int main(int argc, char **argv) {
	auto a = ArrayList<int>();

	std::println("arg count: {}", argc);
	for (size_t i = 0; i < static_cast<size_t>(argc); i++) {
		std::println("args: {}", argv[i]);
	}
	return 0;
}
