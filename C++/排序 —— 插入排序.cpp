void InsertSort(int arr[], int length) {
    for (int i = 1; i < length; i++)
    {
        int j;
        if (arr[i] < arr[i-1])
        {
            int temp = arr[i];
            for ( j = i-1; j>=0 && temp<arr[i]; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
            
        }
        
    }
    
}
