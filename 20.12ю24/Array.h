#include <iostream>

template <typename T>
class Array {
private:
    T* data;
    size_t size;
    size_t capacity;

    void Resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Array(size_t initialCapacity = 10)
        : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    size_t GetSize() const {
        return size;
    }

    size_t GetCapacity() const {
        return capacity;
    }

    void Append(const T& value) {
        if (size >= capacity) {
            Resize(capacity * 2);
        }
        data[size++] = value;
    }

    void Erase(size_t index) {
        if (index >= size) {
            exit(1);
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void Clear() {
        size = 0;
    }

    void Reserve(size_t additionalCapacity) {
        if (capacity < size + additionalCapacity) {
            Resize(size + additionalCapacity);
        }
    }

    void Shrink() {
        Resize(size);
    }
};

int main() {
    Array<int> arr(5);
    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    std::cout << "Array size: " << arr.GetSize() << ", capacity: " << arr.GetCapacity() << std::endl;

    arr.Reserve(10);
    std::cout << "After reserve, capacity: " << arr.GetCapacity() << std::endl;

    arr.Shrink();
    std::cout << "After shrink, capacity: " << arr.GetCapacity() << std::endl;

    arr.Clear();
    std::cout << "After clear, size: " << arr.GetSize() << std::endl;

    return 0;
}
