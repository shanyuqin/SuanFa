//给定一个二叉树，和其中一个结点，找到中序遍历的下一个结点
//结点 除了有指向左右子节点的指针外 还有一个指向父节点的指针

#include<deque>
struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
    BinaryTreeNode *m_parent;
};
BinaryTreeNode * GetNext(BinaryTreeNode *pNode) {
    if (pNode == NULL)
        return NULL;
    BinaryTreeNode *pNext = NULL;
    if (pNode->m_right != NULL)
    {
        BinaryTreeNode *pRight = pNode->m_right;
        while (pRight->m_left != NULL)
        {
            pRight = pRight->m_left;
        }
        pNext = pRight;   
    }
    else if (pNode->m_parent !=NULL)
    {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->m_parent;
        while (pParent != NULL && pCurrent == pParent->m_right)
        {
            pCurrent = pParent;
            pParent = pParent->m_parent;
        }
        pNext = pParent;
        
    }

    return pNext;
    
}

