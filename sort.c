#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define ARR_NUM 99
int gen_sort_arr[ARR_NUM], need_sort_arr[ARR_NUM];

void static swap (int *nums, int a, int b){
	int tmp = nums[a];
	nums[a] = nums[b];
	nums[b] = tmp;	
}

void gen_sort_arr_rand ()
{
    int i = 0;
    srand (time(NULL));
    for (i = 0; i < ARR_NUM; i++)
        gen_sort_arr[i] = rand() % ARR_NUM;
}

void selectSort (int *list, int num)
{
    int index, i, j;
    int currentElement;
    for (i = 0; i < num; i++)
    {
        index = i;
        currentElement = list[i];
        for (j = i + 1; j < num; j++)
        {
            if (list[j] < currentElement)
            {
                currentElement = list[j];
                index = j;
            }
        }
        if (index != i)
        {
            list[index] = list[i];
            list[i] = currentElement;
        }
    }
}

int partition (int *nums, int start, int end)
{
    if (start >= end) return start;
	
	int pivotIndex = (start + end) / 2;
	int pivot = nums[start];
	int l = start, r = end;
	swap (nums, pivotIndex, end);
	while (l < r)
	{
		while (nums[l] <= pivot && (l < r))
			l++;
		nums[r] = nums[l];
		
		while (nums[r] >= pivot && (l < r))
			r--;	
		nums[l] = nums[r];
	}
	nums[l] = pivot;
	return l; 
}
int * quickSort(int *list, int first, int last)
{
    if (first < last)
    {
        int pivotIndex = partition (list, first, last);
        quickSort(list, first, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, last);
    }
    return list;
}

void print_array (int *list, int num)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (i % 16 == 0)
            printf ("%04d-%04d:%04d%s", i, i + 16, list[i], (i+1)%16 == 0 ? "\n":" ");
        else
            printf ("%04d%s", list[i], (i+1)%16 == 0? "\n":" ");
    }
}

int check_sort_ok(int *list, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        if (list[i] > list[i+1])
            return 0;
    }
    return 1;
}
int testSort ()
{
    gen_sort_arr_rand ();

    memcpy ((void *)need_sort_arr, (void *)gen_sort_arr, ARR_NUM * sizeof (int));
    print_array (need_sort_arr, ARR_NUM);
    quickSort (need_sort_arr, 0, ARR_NUM);
    printf ("\nafter select sort %s\n", check_sort_ok(need_sort_arr, ARR_NUM) ? "ok":"not OK");
    print_array (need_sort_arr, ARR_NUM);

    return !check_sort_ok(need_sort_arr, ARR_NUM);
}
