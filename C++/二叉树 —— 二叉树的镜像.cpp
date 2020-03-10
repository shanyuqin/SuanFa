#include<stack>

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};

void Mirror(BinaryTreeNode *pRoot) {
    if (pRoot == NULL || (pRoot->m_left == NULL && pRoot->m_right == NULL))
        return;
    BinaryTreeNode *pTmp = pRoot->m_left;
    pRoot->m_left = pRoot->m_right;
    pRoot->m_right = pTmp;

    if (pRoot->m_left)
        Mirror(pRoot->m_left);
    if (pRoot->m_right)
        Mirror(pRoot->m_right);
    
}
