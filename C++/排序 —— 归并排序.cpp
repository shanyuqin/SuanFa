void Merge(int arr[],int start,int mid,int end,int *temp) {
    int i = start;//左边序列最前边的指针
    int j = mid+1;//右边序列的最前边的指针
    int t = 0;//临时数组指针
    while (i <= mid && j<=end)
    {
        if (arr[i]<=arr[j])
            temp[t++] = arr[i++];
        else 
            temp[t++] = arr[j++];
    }
    while (i<=mid)
        temp[t++] = arr[i++];
    while (j<=end)
        temp[t++] = arr[j++];
    t = 0;
    while (start <= end)
        arr[start++] = temp[t++];
}

// temp 是一个与原数组等长的临时数组
void Sort(int arr[],int start,int end ,int *temp) {
    if (start >= end)
        return;
    int mid = (start + end)/2;
    Sort(arr,start,mid,temp);
    Sort(arr,mid+1,end,temp);
    Merge(arr,start,mid,end,temp);
    
}