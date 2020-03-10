//给定一个压栈序列A，判断另一个给定的序列B是否为A的出栈序列
// 比如 12345 那么 45321是可能的出栈顺序，但是43512一定不是

//思路，
// 1.如果下一个出栈的数字是栈顶数字，直接弹出
// 2.不在，则继续压栈，直到栈顶数字为出栈的数字。如果全部压入也没找到，那么就不是。 如果最终占空，序列也判断完毕，则是
#include<stack>
bool IsPopOrder(const int* pPush,const int* pPop,int len) {
    bool possible = false;
    if (pPush != NULL && pPop  != NULL && len > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        std::stack<int> stackData;
        while (pNextPop - pPop < len)   
        {
            while (stackData.empty() || stackData.top() != *pNextPop) 
            {
                if (pNextPush - pPush == len)
                    break;
                stackData.push(*pNextPush);
                pNextPush++;
            }
            if (stackData.top() != *pNextPop)
                break;
            stackData.pop();
            pNextPush++;
        }
        
        if (stackData.empty() && pNextPop-pPop == len)
            possible = true;
    }
    
    return possible;

}

