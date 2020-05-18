#include <iostream>

using namespace std;



void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void BubbleSort(int arr[], int n)
{
    int temp;
    bool swapped=false;
    for(int i = 0; i < n-1; i++)
    {
        swapped = false;
        for(int j = 0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }

        }
        if(!swapped)
        {
            break;
        }
        cout<<"iteration: "<<i<<" :\t";
        display(arr,n);
    }

}



void selectionSort(int a[], int n)
{
    int  minn, temp;
    for (int i = 0; i < n - 1; i++)
    {
        minn = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minn])
                minn = j;
        temp = a[i];
        a[i] = a[minn];
        a[minn] = temp;
    }
    display(a,5);
}
quickSortMidpivot(int arr[], int left, int right)   // at first would be called
{
    // with left =0 & right = size-1
    //pivot will be in mid
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSortMidpivot(arr, left, j);
    if (i < right)
        quickSortMidpivot(arr, i, right);
}




void insertionSort(int arr[], int n)
{
    int  key,j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    display(arr,5);
}


int Partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = Partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}


void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}




int main()
{
    int arr[]= {22,11,30,14,5};
    int arr2[]= {5,2,15,1,4};
    //BubbleSort(arr,5);
    //selectionSort(arr,5);
    //insertionSort(arr,5);
    //shellSort( arr,5);
    /*
    quickSort(arr, 0,4);
    display(arr,5);
    quickSort(arr2, 0,4);
    display(arr2,5);
    int i =0, j=0;
    while(i<5 && j<5)
    {
        if(arr[i]==arr2[j])
        {
            cout<<arr[i]<<"\t";
            i++;
            j++;
        }
        else if(  arr[i]<arr2[j]  )
            i++;
        else if(  arr[i]>arr2[j]  )
            j++;

    }
    */
    MergeSort(arr, 0, 4/*n-1*/);
    display(arr,5);


    return 0;
}
