#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int isMatch (char *s, char *p)
{
	if (s == NULL || s[0] == 0) return (p == NULL || p[0] == 0);
	
	if (p == NULL || p[0] == 0) return 0;
	
	int sLen = strlen (s), pLen = strlen (p);
//printf ("sLen = %d pLen=%d\n", sLen, pLen);
	int *dp = malloc ((sLen + 1)* (pLen + 1) * 4);
    int is_match = 0, i, j;
    memset (dp, 0, sizeof ((sLen + 1) * (pLen + 1)));
    dp[(sLen)* (pLen + 1) + pLen] = 1;
    
    for (i = sLen; i >= 0; i--)
    {
        for (j = pLen - 1; j >= 0; j--)
        {
            int first_match = (i < sLen) && (p[j] == s[i]) || (p[j] == '.');
            if (pLen - j >= 2 && p[j+1] == '*')
            {
                dp[i*(pLen + 1) + j] = dp[i*(pLen + 1) + j + 2]
                                      || first_match && dp[(i+1)*(pLen + 1) + j];
            }
            else
            {
                dp[i*(pLen + 1) + j] = first_match && dp[(i+1)*(pLen + 1) + j+1];
            }
            //printf ("dp[%d][%d] = %d\n", i, j, dp[i*(pLen + 1) + j]);
        }        
    }
    is_match =  dp[0];
    free (dp);
    return is_match;
}
int test_10_isMatch ()
{
	printf ("isMatch =%d\n", isMatch ("aaa", "aa"));
	return 0;
}

