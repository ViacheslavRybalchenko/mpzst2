#include <vector>
#include <iostream>

#ifdef _WIN32
#include <windows.h> 
#endif

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

void printVector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int write = m + n - 1;

    while (p2 >= 0) {
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[write] = nums1[p1];
            p1--;
        }
        else {
            nums1[write] = nums2[p2];
            p2--;
        }
        write--;
    }
}

int main() {
    setupConsole();

    std::cout << "--- Çàâäàííÿ 5 ---" << std::endl;
    std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    int m = 3;
    std::vector<int> nums2 = { 2, 5, 6 };
    int n = 3;

    std::cout << "Âõ³ä (nums1): ";
    printVector(nums1);
    std::cout << "Âõ³ä (nums2): ";
    printVector(nums2);

    merge(nums1, m, nums2, n);

    std::cout << "Âèâ³ä: ";
    printVector(nums1);

    return 0;
}