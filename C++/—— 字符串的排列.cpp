//  一个 字符串 abc  打印出 abc acb bac bca cab cba
#include<iostream>
void Print(char* str,char* begin) {
    if (*begin == '\0') 
        printf("%s\n",str);
    else {
        for (char* pCh = begin; pCh != '\0'; pCh++)
        {
            char temp = *pCh;
            *pCh = *begin;
            *begin = temp;

            Print(str,begin+1);
            temp = *pCh;
            *pCh = *begin;
            *begin = temp;
        }
        
    }
    
}
void Print(char* str) {
    if (str == NULL)
        return;
    Print(str,str);
}