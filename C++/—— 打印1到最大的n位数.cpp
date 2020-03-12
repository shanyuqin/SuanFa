// 这里要注意 大数问题  的陷阱，如果n很大，使用int 或者long会溢出
#include<string>
// 用来判断每次number+1 后是否超出了位数，第一位为9 并且产生了进位就应该停止循环了

bool Increment(char * numbers){
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(numbers);

    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum = numbers[i] - '0' + nTakeOver;
        if (i == nLength - 1)   
            nSum++;
        if (nSum >= 10)
        {
            if (i == 0)
            {
                isOverflow = true;
            }else {
                nSum  -= 10;
                nTakeOver = 1;
                numbers[i] = '0' + nSum;
            }
        }else {
            numbers[i] = '0' + nSum;
            break;
        }
        
    }
    return isOverflow;
}
// 打印的时候要注意前边的为0的地方不要打印出来
void PrintNumber(char * number) {
    bool isBeginning0 = true;
    int nLength = strlen(number);
    for (int i = 0; i < nLength; i++)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if (!isBeginning0)
            printf("%c",number[i]);
    }
    
}

void Print1ToMaxOfN (int n) {
    if (n<=0) return;

    char *numbers = new char[n+1];
    memset(numbers,'0',n);// 负责把0-n 所有位置都写入0
    numbers[n] = '\0';

    while (!Increment(numbers))
        PrintNumber(numbers);
    
    delete [] numbers;
}
