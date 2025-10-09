#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class ISortStrategy {
public:
    virtual void sort(std::vector<int>& data, bool ascending) const = 0;
    virtual ~ISortStrategy() = default;
};

class BubbleSort : public ISortStrategy {
public:
    void sort(std::vector<int>& data, bool ascending) const override {
        for (size_t i = 0; i < data.size(); ++i)
            for (size_t j = 0; j < data.size() - i - 1; ++j)
                if ((ascending && data[j] > data[j+1]) || (!ascending && data[j] < data[j+1]))
                    std::swap(data[j], data[j+1]);
    }
};

class QuickSort : public ISortStrategy {
public:
    void sort(std::vector<int>& data, bool ascending) const override {
        std::sort(data.begin(), data.end(),
            [ascending](int a, int b) { return ascending ? a < b : a > b; });
    }
};

// Контекст
class Sorter {
private:
    std::unique_ptr<ISortStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<ISortStrategy> s) { strategy = std::move(s); }

    void sort(std::vector<int>& data, bool ascending = true) const {
        if (strategy)
            strategy->sort(data, ascending);
        else
            std::cerr << "Sorting strategy not set!\n";
    }
};

// Використання
int main() {
    std::vector<int> v = {5, 3, 8, 1, 2};
    Sorter sorter;

    sorter.setStrategy(std::make_unique<BubbleSort>());
    sorter.sort(v, true);

    sorter.setStrategy(std::make_unique<QuickSort>());
    sorter.sort(v, false);

    for (auto i : v) std::cout << i << " ";
}
