//两个二叉树A和B，判断B是不是A的子结构
#include<stack>
#include<exception>

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};

bool DoesTree1HaveTree2(BinaryTreeNode  *p1 ,BinaryTreeNode *p2){
    if (p2 == NULL)
        return true;
    if (p1 == NULL)
        return false;
    if (p1->m_value != p2->m_value)
        return false;
    
    return DoesTree1HaveTree2(p1->m_left,p2->m_left) && DoesTree1HaveTree2(p1->m_right,p2->m_right);
    
}

bool HasSubTree(BinaryTreeNode  *p1 ,BinaryTreeNode *p2) {
    bool result = false;
    if (p1 != NULL && p2 != NULL)
    {
        if (p1->m_value == p2->m_value) 
            result = DoesTree1HaveTree2(p1,p2);
        if (!result)
            result = HasSubTree(p1->m_left,p2);
        if (!result)
            result = HasSubTree(p1->m_right,p2);

    }
    return result;    
}
