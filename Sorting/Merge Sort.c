
#include<stdio.h>
#include<conio.h>

void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);

int main()
{
	int i,n;
	//int low,high;

	printf("\n\t----Merge sort----\n");
	printf("\n Enter the size of list:");
	scanf("%d",&n);
	
	int a[n];
	         
	                                                                               
//	printf("\n How many elements are there?");
//	scanf("%d",&n);

	printf("\n Enter the elements:\n");
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
//	low=0;
//	high=n-1;
	mergesort(a,0,n-1);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n", a[i]);
}
	return 0;
}


/* -----------mergesort---------------*/
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
	mid=low+((high-low)/2);
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
}
}

/*-----------merge---------------*/
void merge(int a[],int low,int mid,int high)
{
	int i,j,k;
	int size1=mid-low+1;
	int size2=high-mid;
	
	//create temporary array
	
	int left[size1],right[size2];
	
	// copying the data from a array to temporary array
    for (i = 0; i < size1; i++)
        left[i] = a[low + i];
 
    for (j = 0; j < size2; j++)
        right[j] = a[mid + 1 + j];
        
        
        // merging of the array
    i = 0;	// initial index of first subarray
    j = 0;	// initial index of second subarray
    k = low; // initial index of parent array
    
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }
 
    // copying the elements from Left[], if any
    while (i < size1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
 
    // copying the elements from Right[], if any
    while (j < size2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
 
	
//	while(i<=mid && j<=high)
//	{
//		if(a[i]<=a[j])
//		{
//			temp[k]=a[i];
//			i++;
//			k++;
//		}
//		else
//		{
//			temp[k]=a[j];
//			j++;
//			k++;
//		}
//	}
//
//	if(i>mid)
//	{
//		while(j<=high)
//	{
//		temp[k]=a[j];
//		j++;
//		k++;
//	}
//    }
//    else
//    {
//    	while(i<=mid)
//	{
//		temp[k]==a[i];
//		i++;
//		k++;
//	}	  
//    }
//	//copy the element from temp array to A
//	for(k = low; k<=high; k++)
//	{
//      a[k] = temp[k];
//    }

