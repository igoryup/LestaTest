static constexpr size_t SIZE = 100;
/*
Можно реализовать как C-style массив или как любой STL контейнер по аналогии
*/
namespace stdqueue {
    class Queue {
    public:
        Queue(int size = SIZE);
        ~Queue();

        int Pop();
        void Push(int x);
        int Front();
        int Back();
        bool IsEmpty();
        bool IsFull();
        int Size();

    private:
        int* data_;
        int front_ = 0;
        int back_ = 0;
        int capacity_ = 0;
        int size_ = 0;
    };

    Queue::Queue(int size) {
        data_ = new int[size];
        capacity_ = size;
        front_ = 0;
        back_ = 0;
        size_ = 0;
    }

    Queue::~Queue() {
        delete[] data_;
    }

    int Queue::Pop() {
        if (IsEmpty()) {
            throw;
        }
        int result = data_[front_];
        front_ = (front_ + 1) % capacity_;
        size_--;
        return result;
    }

    void Queue::Push(int item) {
        if (IsFull()) {
            throw;
        }
        data_[back_] = item;
        back_ = (back_ + 1) % capacity_;
        size_++;
    }

    int Queue::Front() {
        if (IsEmpty()) {
            throw;
        }
        return data_[front_];
    }

    int Queue::Back() {
        if (IsEmpty()) {
            throw;
        }
        // т.к. back_ указывает на место куда вставлять
        auto pos = (back_ == 0) ? (capacity_ - 1) : (back_ - 1);
        return data_[pos];
    }

    int Queue::Size() {
        return size_;
    }

    bool Queue::IsEmpty() {
        return (size_ == 0);
    }

    bool Queue::IsFull() {
        return (size_ == capacity_);
    }
} // end namespace stdqueue


/*
Или на основе одно/дву-связного списка
*/
namespace linkedlist {
    class Node {
    public:
        int data_;
        Node* next_;
        Node(int data) : data_(data), next_(nullptr) {}
    };

    class Queue {
    public:
        Queue(int size = SIZE);
        ~Queue();
        int Pop();
        void Push(int x);
        int Front();
        int Back();
        bool IsEmpty();
        bool IsFull();
        int Size();
    private:
        int capacity_;
        int size_;
        Node* front_;
        Node* back_;
    };

    Queue::Queue(int size) {
        capacity_ = size;
        front_ = nullptr;
        back_ = nullptr;
        size_ = 0;
    }

    Queue::~Queue() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    int Queue::Pop() {
        if (IsEmpty()) {
            throw;
        }
        int result = front_->data_;
        if (size_ == 1) {
            delete front_;
            front_ = nullptr;
            back_ = nullptr;
        }
        else {
            // swap and delete
            Node* buf = front_;
            front_ = front_->next_;
            delete buf;
        }
        size_--;
        return result;
    }

    void Queue::Push(int item) {
        if (IsFull()) {
            throw;
        }
        Node* new_node = new Node(item);
        if (IsEmpty()) {
            back_ = new_node;
            front_ = new_node;
        }
        else {
            back_->next_ = new_node;
            back_ = new_node;
        }
        size_++;
    }

    int Queue::Front() {
        if (IsEmpty()) {
            throw;
        }
        return front_->data_;
    }

    int Queue::Back() {
        if (IsEmpty()) {
            throw;
        }
        back_->data_;
    }

    int Queue::Size() {
        return size_;
    }

    bool Queue::IsEmpty() {
        return (size_ == 0);
    }

    bool Queue::IsFull() {
        return (size_ == capacity_);
    }
} // end namespace linkedlist

// Везде вставки за О(1)

// Если нет необходимости в доступе по индексу, то разницы особой нет
// Если есть, то у массив-версии нужно будет выделить много последовательной памяти,
// но индексация такая же быстрая
// В это время листовая версия не требует таких ограничений по памяти, но вставка за O(N)

// Ну или конечно же пользоваться STL "адаптерами" queue или ее priority версией (если нужна сортировка) выбрав там для хранения что угодно - вектор, дэк, тот же лист и др.