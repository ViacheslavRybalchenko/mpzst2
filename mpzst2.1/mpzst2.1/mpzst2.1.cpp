#include <vector>
#include <algorithm> 
#include <iostream>  

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int maxCount = 0;
    int currentCount = 0;

    for (int num : nums) {
        if (num == 1) {
            currentCount++;
        }
        else {
            maxCount = std::max(maxCount, currentCount);
            currentCount = 0;
        }
    }
    return std::max(maxCount, currentCount);
}


int main() {

    std::vector<int> myNums = { 1, 1, 0, 1, 1, 1 };


    int result = findMaxConsecutiveOnes(myNums);

    std::cout << "Input: [1, 1, 0, 1, 1, 1]" << std::endl;
    std::cout << "Output: " << result << std::endl; 

    return 0; 
}