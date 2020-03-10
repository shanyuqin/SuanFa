#include<deque>
struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};

int TreeDeep(BinaryTreeNode *pRoot){
    if (pRoot == NULL)
        return 0;
    int left = TreeDeep(pRoot->m_left);
    int right = TreeDeep(pRoot->m_right);
    
    return left>right ? (left + 1): (right +1);
}