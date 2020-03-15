#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size)
{
	printf("Array is: {%d", arr[0]);
	for(int i=1; i<size; i++)
	{
		printf(", %d", arr[i]);
	}
	printf("}\n");
}

void merge_arr(int arr1[], int arr2[], int i, int j)
{
	i--;
	j--;

	for(int k = i+j+1; k>=0; k--)
	{
		if(i<0)
		{
			arr1[k] = arr1[j];
			j--;
		}
		else if(j<0)
		{
			arr1[k] = arr1[i];
			i--;
		}
		else if(arr1[i] > arr2[j])
		{
			arr1[k] = arr1[i];
			i--;
		}
		else if(arr1[i] < arr2[j])
		{
			arr1[k] = arr2[j];
			j--;
		}
	}
}

int main()
{
	int size, num1, num2;
	FILE* fp = fopen("input.txt", "r");
	
	fscanf(fp, "%d%d%d", &size, &num1, &num2);
	if(num1+num2 != size)
	{
		printf("Sum of individual array size is not equal to size of overall array\n");
		exit(1);
	}

	int arr1[size], arr2[num2];
	for(int i=0; i<num1; i++)
	{
		fscanf(fp, "%d", &arr1[i]);
	}
	for(int i=0; i<num2; i++)
	{
		fscanf(fp, "%d", &arr2[i]);
	}
	
	print_array(arr1, num1);
	print_array(arr2, num2);

	merge_arr(arr1, arr2, num1, num2);
	print_array(arr1, size);

	return 0;
}
