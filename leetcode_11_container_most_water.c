/*

11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a,b) ((a)>(b)?(b):(a))

/*
 第一种方式： 使用O2 方式，暴力计算
 int maxArea = 0;
 for (i = 0; i < heightSize - 1l i++)
 	for (j = i + 1; j < heightSize; j++)
	  if ((j -i) * MIN (height[i], height[j]) > maxArea)
	  	maxArea =  (j -i) * MIN (height[i], height[j])
	  	
 第二种方式： O(n), int  i = 0, j = heightSize - 1;
 	考虑 (j -i) * MIN (height[i], height[j]) 
 		if (height[i] < height[j])
		 {
		 	Every j--:
		 		Area < (j -i) * MIN (height[i], height[j]) 
		 	So:
		 		i++
		 } 
		 else
		 {
		 	Every i++:
			  Area < (j -i) * MIN (height[i], height[j]) 
			So：
				j--; 
		 }
*/
int maxArea(int* height, int heightSize) {
    if (height == NULL || heightSize <= 1) return 0;
    
    int i = 0, j = heightSize - 1, maxArea = 0;
    while (i < j){
    	if ((j -i) * MIN (height[i], height[j]) > maxArea)
    		maxArea = (j - i) * MIN (height[i], height[j]);
    		
    	if (height[i] <= height[j])
    		i++;
		else
			j++;
	}
	return maxArea;
}
