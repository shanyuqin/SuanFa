#include<deque>
struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};

bool isDuiChen(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2) {
    if (pRoot1 == NULL && pRoot2 == NULL)
        return true;
    if (pRoot1 == NULL || pRoot2 == NULL)
        return false;
    if (pRoot1->m_value != pRoot2->m_value)
        return false;
    return isDuiChen(pRoot1->m_left,pRoot2->m_left) && isDuiChen(pRoot1->m_right,pRoot2->m_right);
}

bool isDuiChen(BinaryTreeNode *pRoot) {
    return isDuiChen(pRoot,pRoot);
}