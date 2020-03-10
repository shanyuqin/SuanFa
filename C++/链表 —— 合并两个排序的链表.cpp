#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};

ListNode * MergeList (ListNode *p1,ListNode *p2){
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;
    
    ListNode *pMergeListHead = NULL;
    if (p1->pValue > p2->pValue)    
    {
        pMergeListHead = p2;
        pMergeListHead->pNext = MergeList(p1,p2->pNext);
    }
    else 
    {
         pMergeListHead = p1;
        pMergeListHead->pNext = MergeList(p1->pNext,p2);
    }
    return pMergeListHead;
}