// priority_queue_example.hpp
#ifndef PRIORITY_QUEUE_EXAMPLE_HPP
#define PRIORITY_QUEUE_EXAMPLE_HPP

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class PriorityQueue {
private:
    vector<T> heap;
    size_t hSize;
    size_t hCap;
    function<bool(const T&, const T&)> comp; // true if a has higher priority than b

    // 声明：将在类外定义
    static size_t parent(size_t i) noexcept;
    static size_t leftChild(size_t i) noexcept;
    static size_t rightChild(size_t i) noexcept;

    void heapifyUp(size_t index);
    void heapifyDown(size_t index);

public:
    // 构造（在类外实现）
    PriorityQueue(size_t capacity, function<bool(const T&, const T&)> comparator = {});

    // 基本接口（在类外实现）
    size_t size() const noexcept;
    bool empty() const noexcept;

    void enqueue(const T& val);          // 插入
    optional<T> peek() const;            // 查看堆顶（不删除）
    optional<T> dequeue();               // 弹出并返回堆顶
    void display() const;                // 打印数组顺序（仅用于调试）
};

#endif // PRIORITY_QUEUE_EXAMPLE_HPP

// priority_queue_example_impl.hpp
// 假设上面的头文件已包含或直接把下面代码追加到同一文件中

// ----------------- 静态辅助函数 -----------------
template<typename T>
size_t PriorityQueue<T>::parent(size_t i) noexcept {
    return (i - 1) / 2;
}

template<typename T>
size_t PriorityQueue<T>::leftChild(size_t i) noexcept {
    return 2 * i + 1;
}

template<typename T>
size_t PriorityQueue<T>::rightChild(size_t i) noexcept {
    return 2 * i + 2;
}

// ----------------- 构造函数 -----------------
template<typename T>
PriorityQueue<T>::PriorityQueue(size_t capacity, std::function<bool(const T&, const T&)> comparator)
    : heap(), hSize(0), hCap(capacity),
      comp(comparator ? comparator
                     : std::function<bool(const T&, const T&)>([](const T& a, const T& b){ return b < a; }))
{
    heap.reserve(hCap);
}


// ----------------- 基本查询 -----------------
template<typename T>
size_t PriorityQueue<T>::size() const noexcept {
    return hSize;
}

template<typename T>
bool PriorityQueue<T>::empty() const noexcept {
    return hSize == 0;
}

// ----------------- heapifyUp -----------------
template<typename T>
void PriorityQueue<T>::heapifyUp(size_t index) {
    while (index > 0) {
        size_t p = parent(index);
        if (comp(heap[index], heap[p])) {
            swap(heap[index], heap[p]);
            index = p;
        } else break;
    }
}

// ----------------- heapifyDown -----------------
template<typename T>
void PriorityQueue<T>::heapifyDown(size_t index) {
    size_t n = hSize;
    while (true) {
        size_t l = leftChild(index);
        size_t r = rightChild(index);
        size_t best = index;
        if (l < n && comp(heap[l], heap[best])) best = l;
        if (r < n && comp(heap[r], heap[best])) best = r;
        if (best != index) {
            swap(heap[index], heap[best]);
            index = best;
        } else break;
    }
}

// ----------------- enqueue -----------------
template<typename T>
void PriorityQueue<T>::enqueue(const T& val) {
    if (hSize == hCap) {
        throw overflow_error("Priority Queue is full");
    }
    heap.push_back(val);    // 安全放到末尾
    heapifyUp(hSize);
    ++hSize;
}

// ----------------- peek -----------------
template<typename T>
optional<T> PriorityQueue<T>::peek() const {
    if (empty()) return nullopt;
    return heap[0];
}

// ----------------- dequeue (pop max/min) -----------------
template<typename T>
optional<T> PriorityQueue<T>::dequeue() {
    if (empty()) return nullopt;
    T top = heap[0];
    heap[0] = heap[hSize - 1];
    heap.pop_back();
    --hSize;
    if (!empty()) heapifyDown(0);
    return top;
}

// ----------------- display -----------------
template<typename T>
void PriorityQueue<T>::display() const {
    cout << "heap (array order): ";
    for (size_t i = 0; i < hSize; ++i) cout << heap[i] << ' ';
    cout << '\n';
}

struct Student {
    int roll;
    int rank;
    Student(int r = 0, int rk = 0) : roll(r), rank(rk) {}
    // Java 的 compareTo 用的是 roll：this.roll - o.roll
    bool operator<(const Student& other) const {
        return this->roll < other.roll;
    }
    // 输出友元
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "(" << s.roll << "," << s.rank << ")";
        return os;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // pq1: 默认最小堆（升序移除）
    PriorityQueue<int> pq1(7); // capacity 7 (ascending)
    pq1.enqueue(8);
    pq1.enqueue(5);
    pq1.enqueue(85);
    pq1.enqueue(20);
    pq1.enqueue(15);
    pq1.enqueue(95);
    pq1.enqueue(4);
    pq1.display();
    cout << "\nAscending order removal\n";
    for (int i = 0; i < 7; ++i) {
        auto v = pq1.dequeue();
        if (v) cout << "removed element= " << *v << "\n";
        else cout << "removed element= null\n";
    }

    cout << "------------------------------------\n\n";

    // object in PQ (Student)，默认比较 roll（最小 roll 先出）
    cout << "Object in PQ\n";
    PriorityQueue<Student> pq2(4);
    pq2.enqueue(Student(1, 1000));
    pq2.enqueue(Student(2, 2000));
    pq2.enqueue(Student(3, 3000));
    pq2.enqueue(Student(4, 4000));
    pq2.display();
    cout << "\n";
    auto removedStudent = pq2.dequeue();
    if (removedStudent) cout << "removed element= " << *removedStudent << "\n";
    auto peeked = pq2.peek();
    if (peeked) cout << "peek element= " << *peeked << "\n";

    cout << "------------------------------------\n\n";

    // pq3: 使用自定义 comparator，使得移除得到降序（即最大堆）
    // Java 中 IntegerSorting.compare(o1,o2) = o2 - o1  (so bigger values are "smaller" by comparator),
    // 我们在这里直接传入比较函数：a has higher priority than b when a > b => max-heap
    PriorityQueue<int> pq3(7, [](const int& a, const int& b) {
        return a > b; // 更大值优先 -> 相当于 Java 的 descending order
    });
    pq3.enqueue(8);
    pq3.enqueue(5);
    pq3.enqueue(85);
    pq3.enqueue(20);
    pq3.enqueue(15);
    pq3.enqueue(95);
    pq3.enqueue(4);
    pq3.display();
    cout << "\nDescending order removal\n";
    for (int i = 0; i < 7; ++i) {
        auto v = pq3.dequeue();
        if (v) cout << "removed element= " << *v << "\n";
        else cout << "removed element= null\n";
    }

    return 0;
}