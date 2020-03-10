#include<stack>
using namespace std;
struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};
//从上往下打印
void PrintFromTopToBottom(BinaryTreeNode *pRoot) {
    if (pRoot == NULL)
        return;
    std::deque<BinaryTreeNode *> nodes;
    nodes.push_back(pRoot);
    while (nodes.size())
    {
        BinaryTreeNode *pNode = nodes.front();
        nodes.pop_front();

        printf("%d",pNode->m_value);
        if (pNode->m_left)
            nodes.push_back(pNode->m_left);
        if (pNode->m_right)
            nodes.push_back(pNode->m_right);
        
    }
}
// 从上到下分行打印 不同度 在不同行
void PrintFromTopToBottomLines(BinaryTreeNode *pRoot) {
    if (pRoot == NULL)
        return;
    std::deque<BinaryTreeNode *> nodes;
    nodes.push_back(pRoot);
    int nextLevel = 0;
    int toBePrint = 1;
    while (!nodes.empty())
    {
        BinaryTreeNode *pNode = nodes.front();
        nodes.pop_front();

        printf("%d",pNode->m_value);
        if (pNode->m_left)
        {
             nodes.push_back(pNode->m_left);
            nextLevel++;
        }
        if (pNode->m_right)
        {
            nodes.push_back(pNode->m_right);
            nextLevel++;
        }
        nodes.pop_front();
        toBePrint--;
        if (toBePrint == 0)
        {
            printf("\n");
            toBePrint = nextLevel;
            nextLevel = 0;
        }
    }
}
//按照之字形打印
//思路  借用两个栈当前层用一个栈  下一层用一个栈   逻辑上用奇偶层 来判断
void PrintFromTopToBottomForZhi(BinaryTreeNode *pRoot) {
    if (pRoot == NULL)
        return;
    stack<BinaryTreeNode*> levels[2];
    int current = 0;
    int next = 1;
    levels[current].push(pRoot);
    while (!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode *pNode = levels[current].top();
        levels[current].pop();
        printf("%d",pNode->m_value);
        if (current == 0)
        {
            if (pNode->m_left != NULL)
                levels[next].push(pNode->m_left);
            if (pNode->m_right != NULL)
                levels[next].push(pNode->m_right);
        }
        else {
            if (pNode->m_right != NULL)
                levels[next].push(pNode->m_right);
            if (pNode->m_left != NULL)
                levels[next].push(pNode->m_left);
        }
        if (levels[current].empty())
        {
            printf("\n");
            current = 1-current;
            next = 1-next;
        }
        
        
    }
    
}
