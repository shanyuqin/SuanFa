#include<stack>
#include<vector>

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};
void FindPath(BinaryTreeNode *pNode,int expectedSum,std::vector<int>& path,int currentSum) {
    currentSum += pNode->m_value;
    path.push_back(pNode->m_value);

    bool isLeaf = pNode->m_left == NULL && pNode->m_right == NULL;
    if (currentSum == expectedSum && isLeaf)
    {
        printf("A path is Found :");
        std::vector<int>::iterator iter = path.begin();
        for (; iter != path.end(); iter++)
        {
            printf("%d\t",*iter);
        }
        printf("\n");
    }
    if (pNode->m_left != NULL)
        FindPath(pNode->m_left,expectedSum,path,currentSum);
    if (pNode->m_right != NULL)
        FindPath(pNode->m_right,expectedSum,path,currentSum);
        
    path.pop_back();
}
void FindPath(BinaryTreeNode *pRoot,int expectedSum) {
    if (pRoot == NULL)
        return;
    int currentSum = 0;
    std::vector<int> path;
    FindPath(pRoot,expectedSum,path,currentSum);
}