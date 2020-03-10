// 输入前序遍历和中序遍历的结果，重建二叉树
// 如前序遍历 {1，2，4，73，5，6，8} 中序遍历 {4，7，2，1，5，3，8，6}
#include<stack>
#include<exception>
struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};

BinaryTreeNode * ConsturctCore(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder){
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_value = rootValue;
    root->m_left = root->m_right = NULL;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder)
        {
            return root;
        }
        else 
        {
            std::logic_error ex("Invalid input");
            throw std::exception(ex);
        }
    }
    int* rootInorder = startInorder; 
    while (rootInorder<endInorder && *rootInorder == rootValue)
        rootInorder++;
    if (rootInorder == endInorder && *rootInorder != rootValue){
        std::logic_error ex("Invalid input");
        throw std::exception(ex);
    }
    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0)
    {
        root->m_left = ConsturctCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
    }
    if (leftLength<endPreorder-startInorder)
    {
        root->m_left = ConsturctCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
    }
    return root;
}

BinaryTreeNode * Consturct(int *preorder,int *inorder,int length){
    if (preorder == NULL || inorder == NULL ||length <= 0)
    {
        return NULL;
    }

    return ConsturctCore(preorder,preorder+length-1,inorder,inorder+length-1);
}