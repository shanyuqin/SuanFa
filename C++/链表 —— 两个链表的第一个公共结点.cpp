#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};

int GetListLength(ListNode *phead) {
    unsigned int length = 0;
    ListNode *pNode = phead;
    while (pNode != NULL)
    {
        length++;
        pNode = pNode->pNext;
    }
    return length;
    
}

ListNode * FindFirstCommonNode(ListNode *phead1,ListNode *phead2) {
    int phead1Len = GetListLength(phead1);
    int phead2Len = GetListLength(phead2);
    
    int pLengthDiff = phead1Len - phead2Len;
    ListNode *pLongHead = phead1;
    ListNode *pShortHead = phead2;
    if (phead1Len < phead2Len)
    {
        pLongHead = phead2;
        pShortHead = phead1;
        pLengthDiff = phead2Len - phead1Len;
    }

    for (int i = 0; i < pLengthDiff; i++)
        pLongHead = pLongHead->pNext;
    
    while ((pLongHead != NULL) && (pShortHead != NULL) && (pLongHead != pShortHead))
    {
        pLongHead = pLongHead->pNext;
        pShortHead = pShortHead->pNext;
    }
    
    return pLongHead;
    
    
    
}
