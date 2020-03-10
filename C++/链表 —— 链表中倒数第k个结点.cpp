#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};

ListNode * findKthToTail(ListNode *pHead,unsigned int k) {
    if (pHead == NULL || k == 0)
    {
        return NULL;
    }
    
    ListNode *p1 = pHead;
    ListNode *p2 = pHead;
    for (int i = 0; i < k; i++)
    {
        if (p1->pNext != NULL)
        {
            p1 = p1->pNext;
        }else
        {
             return NULL;
        }
        
    }
    while (p1->pNext != NULL)   
    {
        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    return p2;
}