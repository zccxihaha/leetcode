#include <stdio.h>
#include <stdlib.h>
/*
15, 3Sum -- medium
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 /*
 	1, O3, for (i = 0; i < numsSize - 2; i++)
 				for (j = i+1; j < numsSize - 1; j++)
 					for (z = j+1; z < numsSize; z++)
	2, O(nlogn) Qsort + n * O(logn) 
		int i = 0, l, r;
		for (i = 0; i < numsSize - 2; i++)
		{
			l = i + 1;
			r = numsSize - 1;
			//binarySearch
			while (l < r)
			{
			}
		}
 */
void static swap (int *nums, int a, int b){
	int tmp = nums[a];
	nums[a] = nums[b];
	nums[b] = tmp;	
}
int static partition (int *nums, int start, int end){
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

void static QuickSort (int *nums, int left, int right){
	if (left < right){
		int pivotIndex = partition (nums, left, right);
		QuickSort (nums, left, pivotIndex - 1);	
		QuickSort (nums, pivotIndex + 1, right);	
	}	
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
	int **ret = malloc (sizeof (int *));
	ret[0] = NULL;
	*returnSize = 0; 
	
  	QuickSort (nums, 0, numsSize - 1);  
//printf ("sort ok\n");
  	int i = 0,l, r;
  	
  	for (i = 0; i < numsSize - 2; i++){
  		if (i > 0 && nums[i] == nums[i - 1]) continue;
  		
  		l = i + 1;
  		r = numsSize - 1;
  		while (l < r){
  			
  			if (nums[i] + nums[l] + nums[r] < 0){
  				l = l + 1;
			}
			else if (nums[i] + nums[l] + nums[r] > 0){
				r = r - 1;
			}
			else{
				//Find One, if not duplicate, add it
				//printf ("i = %d l = %d r = %d value:%d:%d:%d\n",
				//i,l,r, nums[i], nums[l], nums[r]);
				if ((*returnSize)== 0 ||  !(ret[*returnSize - 1][0] == nums[i]
								            && ret[*returnSize - 1][1] == nums[l])){
					if (*returnSize)
						ret = realloc (ret, sizeof (int *) * (*returnSize + 1));
					ret[*returnSize] = malloc (sizeof (int) * 3);
					ret[*returnSize][0] = nums[i];
					ret[*returnSize][1] = nums[l];
					ret[*returnSize][2] = nums[r];
					(*returnSize)++;
				}
				l++;
				r--;
			}
		}
	}
	return ret;
}

#define ARRAY_NUM 100
int test_13_3sum (){
	int nums[100] = { 0 };
	for (int i= 0; i < ARRAY_NUM; i++){
		nums[i] = -ARRAY_NUM/2 + i;
	}
	int **ret = NULL; 
	int ret_num = 0;
	ret = threeSum (nums, ARRAY_NUM, &ret_num);
	printf ("ret_num=%d\n", ret_num);
	for (int i = 0; i < ret_num; i++){
		if (ret[i][0] + ret[i][1] + ret[i][2] != 0)
			return 1;
	}
	return 0;
}
