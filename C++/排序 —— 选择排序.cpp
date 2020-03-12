void SelectionSort(int arr[],int length) {
    for (int i = 0; i < length; i++)
    {
        int index = i;
        for (int j = i+1; j < length; j++)
        {
            if (arr[j] < arr[index])    
                index = j;
        }
        if (index == i)
            continue;
        else {
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
}