void swap(int arr[],int a,int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
//调整大顶堆
void adjustHeap(int arr[],int i,int length) {
    int temp = arr[i];
    for(int k = i*2 +1;k<length;k=k*2+1){    //从i节点的左子节点开始就是2i+1
        if(k+1<length && arr[k]<arr[k+1]) {   //如果左子节点小于右子节点，k指向右子节点
            k++;
        }
        if(arr[k] > temp) { //如果子节点大于父节点，将子节点赋值给父节点（不用交换）
            arr[i] = arr[k];    
            i = k;
        }else {
            break;
        }
    }
    arr[i] = temp;
}


void heapSort(int arr[],int length) {
    //1.构建大顶堆
    for(int i = length/2-1; i>0; i--){
        //从第一个非叶子节点从下至上，从右向左调整结构
        adjustHeap(arr,i,length);
    }
    //2.调整堆结构 交换堆顶元素与末尾元素
    for(int j=length-1;j>0;j--) {
        swap(arr,0,j);
        //重新对堆进行调整，因为除了0是因为交换后改变了，其他的排序没有改变，所以需要从堆顶的那个值调整
        adjustHeap(arr,0,j);
    }
}