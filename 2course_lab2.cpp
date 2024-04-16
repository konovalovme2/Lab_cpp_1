#include "stdafx.h"
#include "Array.h"

int main()
{
    Array arr1 = Array(); // 0
    std::cout << "Check for constructor 1: " << arr1 << std::endl;

    Array arr2 = Array(5); // 0 0 0 0 0
    std::cout << "Check for constructor 2: " << arr2 << std::endl;

    Array arr3 = Array(6, 1); // 1 1 1 1 1 1
    std::cout << "Check for constructor 3: " << arr3 << std::endl;

    Array arr4 = Array(arr2); // 0 0 0 0 0
    std::cout << "Check for constructor 4: " << arr4 << std::endl;

    Array&& ar = Array(7,2);
    Array arr5 = Array(ar); // 2 2 2 2 2 2 2
    std::cout << "Check for constructor 5: " << arr5 << std::endl;

    Array arr6 = Array(8, 3, 5); // 3 3 3 3 3 3 3 3
    std::cout << "Check for constructor 6: " << arr6 << std::endl;

    std::cout << "Sizes: " << arr1.getSize() << " " 
        << arr2.getSize() << " " 
        << arr3.getSize() << " " 
        << arr4.getSize() << " " 
        << arr5.getSize() << " "
        << arr6.getSize() << " "
        << std::endl;

    arr3[3] = 9;
    std::cout << "Check for [] in arr3: " << arr2 << std::endl;
    try {
        arr3[10] = 9;
    }
    catch (OutOfBoundsException& e) {
        std::cout << "[OK] Exception for [] is working" << std::endl;
    }

    arr3.resize(6);
    std::cout << "Check for resize(6) in arr3: " << arr3 << std::endl; //rewrite
    arr3.resize(10);
    std::cout << "Check for resize(10) in arr3: " << arr3 << std::endl;
    arr3.resize(4);
    std::cout << "Check for resize(4) in arr3: " << arr3 << std::endl;

    arr1 = arr2;
    std::cout << "Check for =: " << arr1 << std::endl;
    arr1 = ar;
    std::cout << "Check for = with moving: " << arr1 << std::endl;

    if (arr2 == arr4) {
        std::cout << "[OK] == is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] == is not working" << std::endl;
    }
    if (arr1 == arr4) {
        std::cout << "[FAIL] == is not working" << std::endl;
    }
    else {
        std::cout << "[OK] == is working" << std::endl;
    }
    if (arr1 != arr4) {
        std::cout << "[OK] != is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] != is not working" << std::endl;
    }
    if (arr2 != arr4) {
        std::cout << "[FAIL] != is not working" << std::endl;
    }
    else {
        std::cout << "[OK] != is working" << std::endl;
    }
    if (arr2 <= arr4) {
        std::cout << "[OK] <= is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] <= is not working" << std::endl;
    }
    if (arr2 >= arr4) {
        std::cout << "[OK] >= is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] >= is not working" << std::endl;
    }
    if (arr2 > arr4) {
        std::cout << "[FAIL] > is not working" << std::endl;
    }
    else {
        std::cout << "[OK] > is working" << std::endl;
    }
    if (arr2 < arr4) {
        std::cout << "[FAIL] < is not working" << std::endl;
    }
    else {
        std::cout << "[OK] < is working" << std::endl;
    }


    arr2[3] = 5;
    if (arr2 > arr4) {
        std::cout << "[OK] > is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] > is not working" << std::endl;
    }
    if (arr2 >= arr4) {
        std::cout << "[OK] >= is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] >= is not working" << std::endl;
    }
    if (arr4 < arr2) {
        std::cout << "[OK] < is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] < is not working" << std::endl;
    }
    if (arr4 <= arr2) {
        std::cout << "[OK] <= is working" << std::endl;
    }
    else {
        std::cout << "[FAIL] <= is not working" << std::endl;
    }

    Array arr7 = arr2 + arr6;
    std::cout << arr7 << std::endl;

    std::cout << "Buf: " << arr6.capacity() << std::endl;

    arr6.push_back(10);
    std::cout << "Check for push_back: " << arr6 << std::endl;
    arr6.pop_back();
    std::cout << "Check for pop_back: " << arr6 << std::endl;
    
    std::cout << std::endl;

    try {
        arr6.push_back(10);
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.push_back(10);
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.push_back(10);
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.push_back(10);
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.push_back(10);
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.push_back(10);
    }
    catch (OutOfBoundsException& e){
        std::cout << "[OK]: Check for push_back max: " << arr6 << std::endl;
    }

    std::cout << std::endl;

    try {
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
        std::cout << "Buf: " << arr6.capacity() << " Size: " << arr6.getSize() << std::endl;
        arr6.pop_back();
    }
    catch (OutOfBoundsException& e) {
        std::cout << "[OK]: Check for pop_back max: " << arr6 << std::endl;
    }

    std::cin >> arr7;
    std::cout << "Check for >> operator: " << arr7 << std::endl;
    return 0;
}