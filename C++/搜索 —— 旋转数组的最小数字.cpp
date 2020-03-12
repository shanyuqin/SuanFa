// {3,4,5,1,2} 是 {1,2,3,4,5}的一个旋转数组，注意原数组得是排好序的。
//  特殊情况，旋转了0个元素。 需要直接返回第一个元素
//  数组中有重复数字比如原数组为{0,1,1,1,1}  ，那么{1,0,1,1,1},{1,1,1,0,1}都是它的旋转后的数组。

// 思路：正常的思路就是使用类似二分查找的方式，如果length/2的下标的值 大于后边的那么 ，这个中间位置的值就在前边的递增序列中。

#include<iostream>
#include<exception>

int MinInorder(int *numbers ,int index1,int index2) {
    int result = numbers[index1];
    for (int i = index1 + 1; i < index2; i++)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}

int Min(int * numbers,int length) {
    if (numbers == NULL || length == 0)
        return -1;
    int index1 = 0;
    int index2 = length - 1;
    int midIndex = index1; //如果旋转0个元素，那么index1 = 0 就是最小元素，不进入循环
    while (numbers[index1] >= numbers[index2])
    {
        if (index2 - index1 == 1)
        {
            midIndex = index2;
            break;
        }
        midIndex = (index1 + index2)/2;
        
        // -----------------如果index1，index2，midIndex指向的三个数字相等。，就只能顺序查找了。-----------
        if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[midIndex])
        {
            return MinInorder(numbers,index1,index2);
        }
        // ----------------------------------------------------------------------------------------
        
        if (numbers[midIndex] >= numbers[index1])
            index1 = midIndex;
        else if (numbers[midIndex] <= numbers[index2])
            index2 = midIndex;
    }
    
    return numbers[midIndex];
}
