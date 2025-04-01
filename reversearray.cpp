#include <iostream>
#include <vector>

void reverseArray(std::vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        std::swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    
    reverseArray(arr);
    
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}