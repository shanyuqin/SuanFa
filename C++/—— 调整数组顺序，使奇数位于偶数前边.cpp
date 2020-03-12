// 思路： 两个指针，一个在前 一个在后，在前查找奇数，找到后，  在后查偶数，找到后 对两个数的位置进行交换。
// 因为并没有要求排序

#include<iostream>

bool isEven(int n){
    return n%2 == 0;
}

void ReorderNumbersWithFun(int *numbers, int length,bool (*func)(int)){
    if (numbers == NULL || length == 0)
        return;
    int left = 0;
    int right = length - 1;
    while (left < right)
    {
        while (left < right && func(numbers[left])) 
            left++;
        while (left < right && !func(numbers[right])) 
            right--;
        if (left < right)
        {
            int temp = numbers[left];
            numbers[left] = numbers[right];
            numbers[right] = temp;
        }
    }
}

void ReorderNumbers(int *numbers, int length) {
    ReorderNumbersWithFun(numbers,length,isEven);
}