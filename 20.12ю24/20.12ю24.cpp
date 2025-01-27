#include <iostream>
#include "Array.h" 
#include "String.h" 

int main() {
    // === Тестирование класса Array ===
    std::cout << "=== Тестирование класса Array ===" << std::endl;

    Array<int> arr(5);
    arr.Append(10);
    arr.Append(20);
    arr.Append(30);

    std::cout << "Initial Array: ";
    for (size_t i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nSize: " << arr.GetSize() << ", Capacity: " << arr.GetCapacity() << std::endl;

    arr.Reserve(10);
    std::cout << "After Reserve(10): Capacity: " << arr.GetCapacity() << std::endl;

    arr.Shrink();
    std::cout << "After Shrink(): Capacity: " << arr.GetCapacity() << std::endl;

    arr.Erase(1);
    std::cout << "After Erase(1): ";
    for (size_t i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nSize: " << arr.GetSize() << ", Capacity: " << arr.GetCapacity() << std::endl;

    arr.Clear();
    std::cout << "After Clear(): Size: " << arr.GetSize() << ", Capacity: " << arr.GetCapacity() << std::endl;

    // === Тестирование класса String ===
//    std::cout << "\n=== Тестирование класса String ===" << std::endl;
//
//    String str(5);
//    str.Append('H');
//    str.Append('e');
//    str.Append('l');
//    str.Append('l');
//    str.Append('o');
//    std::cout << "String after Append(char): ";
//    str.Print();
//
//    String world(5);
//    world.Append(' ');
//    world.Append('W');
//    world.Append('o');
//    world.Append('r');
//    world.Append('l');
//    world.Append('d');
//    str.Append(world);
//    std::cout << "String after Append(String): ";
//    str.Print();
//
//    str.Reserve(10);
//    std::cout << "After Reserve(10): Capacity: " << str.GetCapacity() << std::endl;
//
//    str.Shrink();
//    std::cout << "After Shrink(): Capacity: " << str.GetCapacity() << std::endl;
//
//    str.Clear();
//    std::cout << "After Clear(): ";
//    str.Print();
//    std::cout << "Size: " << str.GetSize() << ", Capacity: " << str.GetCapacity() << std::endl;
//
//    return 0;
//}

