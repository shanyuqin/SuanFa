// 二叉搜索树的所有节点的左子树的节点的值都小于这个节点的值，所有右子树节点的值都大于这个节点的值
// 思路 二叉搜索树的中序遍历 是有序的，所以中序遍历一次就可以了
// 注意第K大  和  第K节点的区别


#include<stack>
using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};

class Solution
{
private:
    
public:
    BinaryTreeNode * resultNode;
    int count;
    // 第K个
    void kthNodeCore(BinaryTreeNode * pNode,int k) {
        if (pNode == NULL) 
            return;
        
        // 如果是第K个就先左子树，如果是第K大个 就先右子树
        if (pNode->m_left)
            kthNodeCore(pNode->m_left,k);
        count++;
        if (count == k) 
            resultNode = pNode;
        if (pNode->m_right)
            kthNodeCore(pNode->m_right,k);
        
    }
    BinaryTreeNode * kthNode(BinaryTreeNode * pRoot,int k) {
        resultNode = NULL;
        count = 0;
        kthNodeCore(pRoot,k);
        return resultNode;
    }
  
};