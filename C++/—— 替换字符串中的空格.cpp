// 将字符串中 "We are happy" 的空格替换成%20
// 思路：从后边开始 时间复杂度为O(n)
#include<string>

// length 为数组string的长度
void ReplaceBlank(char string[],int length) {
    if (string == NULL || length == 0)
        return;

    int originalLength = 0; //字符串
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        originalLength++;
        if (string[i] == ' ')
            numberOfBlank++;
        i++;
    }

    int newLength = originalLength + 2*numberOfBlank;
    if (newLength > length)
        return; // 替换之后的数组长度超出了数组的长度    
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }else {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        indexOfOriginal--;
    }
}