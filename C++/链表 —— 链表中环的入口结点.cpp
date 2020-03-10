#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};


ListNode *MeetingNode(ListNode *phead) {

    if (phead == NULL)
        return NULL;

    ListNode *pSlow = phead->pNext;
    if (pSlow == NULL)
        return NULL;
    ListNode *pFast = pSlow->pNext;

    while (pFast != NULL && pSlow != NULL)
    {
        if (pSlow == pFast)
            return pFast;
        
        pSlow = pSlow->pNext;

        pFast = pFast->pNext;
        if (pFast != NULL)
            pFast = pFast->pNext;
    }
    return NULL;
}

ListNode *EntryOfNodes (ListNode *phead) {
    ListNode *meetingNode = MeetingNode(phead);
     if (meetingNode == NULL)
        return NULL;

    int numberOfNodesInLoop = 1;
    ListNode *pNode1 = meetingNode;
    while (pNode1->pNext != meetingNode)
    {
        pNode1 = pNode1->pNext;
        numberOfNodesInLoop++;
    }
    pNode1 = phead;
    for (int i = 0; i < numberOfNodesInLoop; i++)
        pNode1 = pNode1->pNext;
    
    ListNode *pNode2 = phead;
    while (pNode1 != pNode2)
    {
        pNode1 = pNode1->pNext;
        pNode2 = pNode2->pNext;
    }
    return pNode1;
}