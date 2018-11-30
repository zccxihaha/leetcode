#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#include "leetcode.h"
#define TEST_FUNC_NAME_LEN     32

void test_func (int f(), char *f_name){
	struct timeval tv_start, tv_end; 
	int ret;
	gettimeofday (&tv_start, NULL);
	ret = f ();
	gettimeofday (&tv_end, NULL);
	printf ("test %32s %s use %.03fms\n", f_name, ret == 0 ? "Success":"Failed", 
			(tv_end.tv_sec - tv_start.tv_sec) * 1000.0 + (tv_end.tv_usec - tv_start.tv_usec) / 1000.0);
}

int main (int argc, char *argv[]){
	//test_func (test_1_two_sum, "test_1_two_sum");
	//test_func (testSort, "testSort");
	test_func (test_13_3sum, "test_13_3sum");
	return 0;
}

