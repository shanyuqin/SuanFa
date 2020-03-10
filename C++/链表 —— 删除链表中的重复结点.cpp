//1233445  → 125
#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};

//头结点也可能重复
void DeleteDuplication(ListNode **phead) {

    if (phead == NULL || *phead == NULL)
        return;
    
    ListNode *pNode = *phead;
    ListNode *pPreNode = NULL;

    while (pNode != NULL)
    {
        ListNode *pNext = pNode->pNext;
        bool needDelete = false;
        if (pNext != NULL && pNext->pValue == pNode->pValue)
            needDelete = true;
        
        if (!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->pNext;
        }
        else 
        {
            int value = pNode->pValue;
            ListNode *pToBeDel = pNode;
            while (pToBeDel != NULL && pToBeDel->pValue == value)
            {   
                pNext = pToBeDel->pNext;
                delete pToBeDel;
                pToBeDel = NULL;
                pToBeDel = pNext;
            }
            if (pPreNode == NULL)
                *phead = pPreNode;
            else
                pPreNode->pNext = pNext;
            pNode = pNext;   
        }   
    }
}