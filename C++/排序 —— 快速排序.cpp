void QuickSort(int arr[],int left,int right){
    if (left >= right)
        return;
    int baseval = arr[left];
    int pLeft = left;
    int pRight = right;
    while (pLeft != pRight)
    {
        while (pLeft<pRight && arr[pRight] > baseval)
            pRight--;
        if (pLeft < pRight)
        {
            arr[pLeft] = arr[pRight];
            pLeft++;
        }
        while (pLeft<pRight && arr[pLeft] < baseval)
            pLeft++;
        if (pLeft < pRight)
        {
            arr[pRight] = arr[pLeft];
            pRight--;
        }
    }
    arr[pLeft] = baseval;
    QuickSort(arr,pLeft,pLeft-1);
    QuickSort(arr,pLeft+1,pRight);
}