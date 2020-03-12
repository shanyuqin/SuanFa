// 给定一个头结点， 和一个要删除的节点，并且这个要删除的节点确实在头结点的链表中
// 思路： 把要删除的节点的值 赋值为它下一个节点pNext的值，然后把要删除的节点的pNext 赋值为它的next的pNext，实际上就是把
//       要删除的节点的值修改，指针修改，实际删除的指针是它的next
#include<stack>
struct ListNode
{
    int pValue;
    ListNode * pNext;
};

void DeleteNode(ListNode **pHead,ListNode *pToBeDelete) {
    if (!pHead || !pToBeDelete)
        return;
    
    if (pToBeDelete->pNext != NULL){
        ListNode *pNext = pToBeDelete->pNext;
        pToBeDelete->pValue = pNext->pValue;
        pToBeDelete->pNext = pNext->pNext;

        delete pNext;
        pNext = NULL;
    }else if(*pHead == pToBeDelete) {  //如果链表中只有一个节点，并且是头结点，那么就直接删除
        delete pToBeDelete;
        pToBeDelete = NULL;
        *pHead = NULL;
    }else { //链表中有多个节点，要删除的是尾节点  那么就只能遍历了。
        ListNode *pNode = *pHead;
        while (pNode->pNext != pToBeDelete)
            pNode = pNode->pNext;
        
        pNode->pNext = NULL;
        delete pToBeDelete;
        pToBeDelete = NULL;
    }
}