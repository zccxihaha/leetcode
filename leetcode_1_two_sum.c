#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

int* twoSumO2(int* nums, int numSize, int target) {
    int *ret_int = malloc (2 * sizeof (int));
    ret_int[0] = -1;
    ret_int[1] = -1;
    int i, j;
    for (i = 0; i < numSize; i++)
    {
        for (j = 0; j < numSize; j++)
        {
            if (i != j && (nums[i] + nums[j]) == target)
            {
                ret_int[0] = i;
                ret_int[1] = j;
                return ret_int;
            }
        }
    }
    return ret_int;
}

struct number_hash {
	int value;
	int index;
	UT_hash_handle hh;
};

void destory_table (struct number_hash **table){
	struct number_hash *curr;
	struct number_hash *tmp;
	HASH_ITER (hh, *table, curr, tmp){
		HASH_DEL (*table, curr);
		free (curr);
	}
} 

int* twoSumHash(int* nums, int numSize, int target){
	struct number_hash *table = NULL;
	struct number_hash *element;
	int *ret = (int *)malloc (2 * sizeof (int));
	int remaining;
	//int i = 0;
	for (int i = 0; i < numSize; i++){
		remaining = target - nums[i];
		
		// Find if there has already been an element such that the sum is target
		HASH_FIND_INT (table, &remaining, element);
		if (element){
			ret[0] = element->index;
			ret[1] = i;
			break;
		}
		HASH_FIND_INT (table, &nums[i], element);
		if (!element){
			element = (struct number_hash *)malloc (sizeof (*element));
			element->value = nums[i];
			element->index = i;
			HASH_ADD_INT (table, value, element);
		}
		
	}
	
	destory_table (&table);
	return ret;
}

#define ARRAY_NUM 1000
int test_1_two_sum ()
{
    int num_arr[ARRAY_NUM] = { 0 };
    int *ret, ret_int = 0;
    int target = ARRAY_NUM * 1.5;
    for (int i = 0; i < ARRAY_NUM; i++){
    	num_arr[i] = i;
	}
    
    ret = twoSumHash (num_arr, sizeof (num_arr)/sizeof (int), target);
    if (ret == NULL || ret[0] < 0 || ret[1] < 0){
    	ret_int += 1;
	}
	else{
		ret_int += ((num_arr[ret[0]] + num_arr[ret[1]]) == target);
		printf ("ret[0]=%d ret[1]=%d\n", ret[0], ret[1]);
    	free (ret);
	}

    return ret_int;
}
