//实现对列的两个函数appendTail  和 deleteHead 删除和添加
#include<stack>
#include<exception>
template <typename T> class CQueue {
public:
    CQueue();
    ~CQueue();;
    void appendTail(const T& node);
    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;

};

template <typename T> void CQueue<T>::appendTail(const T& element) {
    stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead() {
    if (stack2.size()<=0)
    {
        while (stack1.size()>0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
        
    }
    if (stack2.size() == 0)
    {
        //当前对列 为空
    }
    T head = stack2.top();
    return head;
    
}