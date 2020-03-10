#include<stack>
struct ComplexListNode
{
    int pValue;
    ComplexListNode * pNext;
    ComplexListNode * pOther;
};

void CloneNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    while (pNode != NULL)
    {
       ComplexListNode *pClone = new ComplexListNode();
       pClone->pValue = pNode->pValue; 
       pClone->pNext = pNode->pNext;
       pClone->pOther = NULL;

       pNode->pNext = pClone;
       pNode = pClone->pNext;
    }
}

void ConnectOtherNodes(ComplexListNode *pHead){
    ComplexListNode *pNode = pHead;
    while (pNode != NULL)
    {
        ComplexListNode *pClone = pNode->pNext;
        if (pNode->pOther != NULL)
        {
            pClone->pOther = pNode->pOther->pNext;
        }
        pNode = pClone->pNext;
    }
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    ComplexListNode *pCloneHead = NULL;
    ComplexListNode *pCloneNode = NULL;

    if (pNode != NULL)
    {
       pCloneHead = pCloneNode = pNode->pNext;
       pNode->pNext = pCloneNode->pNext;
       pNode = pNode->pNext; 
    }

    while (pNode != NULL)
    {
        pCloneNode->pNext = pNode->pNext;
        pCloneNode = pCloneNode->pNext;
        pNode->pNext = pCloneNode->pNext;
        pNode = pNode->pNext;
    }
    return pCloneHead;
}

ComplexListNode *Clone(ComplexListNode *pHead) {    
    CloneNodes(pHead);
    ConnectOtherNodes(pHead);
    return ReconnectNodes(pHead);
}
