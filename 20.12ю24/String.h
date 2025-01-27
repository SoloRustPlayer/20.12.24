#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t size;
    size_t capacity;

    void Resize(size_t newCapacity) {
        char* newData = new char[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = '\0';
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    String(size_t initialCapacity = 10)
        : size(0), capacity(initialCapacity) {
        data = new char[capacity];
        data[0] = '\0';
    }

    ~String() {
        delete[] data;
    }

    size_t GetSize() const {
        return size;
    }

    size_t GetCapacity() const {
        return capacity;
    }

    void Append(char c) {
        if (size + 1 >= capacity) {
            Resize(capacity * 2);
        }
        data[size++] = c;
        data[size] = '\0';
    }

    void Append(const String& str) {
        size_t newSize = size + str.size;
        if (newSize >= capacity) {
            Resize(newSize * 2);
        }
        for (size_t i = 0; i < str.size; ++i) {
            data[size++] = str.data[i];
        }
        data[size] = '\0';
    }

    void Clear() {
        size = 0;
        data[0] = '\0';
    }

    void Reserve(size_t additionalCapacity) {
        if (capacity < size + additionalCapacity) {
            Resize(size + additionalCapacity);
        }
    }

    void Shrink() {
        Resize(size + 1);
    }

    void Print() const {
        std::cout << data << std::endl;
    }
};

int main() {
    String str(5);
    str.Append('H');
    str.Append('e');
    str.Append('l');
    str.Append('l');
    str.Append('o');
    str.Print();

    String world(5);
    world.Append(' ');
    world.Append('W');
    world.Append('o');
    world.Append('r');
    world.Append('l');
    world.Append('d');
    str.Append(world);
    str.Print();

    str.Reserve(10);
    std::cout << "After reserve, capacity: " << str.GetCapacity() << std::endl;

    str.Shrink();
    std::cout << "After shrink, capacity: " << str.GetCapacity() << std::endl;

    str.Clear();
    str.Print();
    std::cout << "After clear, size: " << str.GetSize() << std::endl;

    return 0;
}
