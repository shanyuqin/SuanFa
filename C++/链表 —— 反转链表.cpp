#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};

ListNode *reverseList(ListNode *pHead) {
    if (pHead == NULL)
    {
        return NULL;
    }
    
    ListNode *pNode = pHead;
    ListNode *pReverseHead = NULL;
    ListNode *pPre = NULL;

    while (pNode->pNext != NULL)    
    {
        ListNode *pNext = pNode->pNext;
        if (pNext->pNext == NULL)
        {
            pReverseHead = pNext;
        }
        pNode->pNext = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return pReverseHead;
}