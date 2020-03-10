#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};

void printListNodeReversingly(ListNode *pHead) {
     if (pHead == NULL)
    {
        return;
    }
    std::stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->pNext;
    }
    while (!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t",pNode->pValue);
        nodes.pop();
    }
}
