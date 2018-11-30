#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//5. Longest Palindromic substring
inline int isPalindrome (char *s, int start, int end)
{
    while (start < end && s[start] == s[end])
    {
        start++;
        if (start < end)
            end--;
    }
    if (start == end) return 1;

    return 0;
}
char* longestPalindrome(char* s) {
    if (s == NULL) return "";

    int i = 0, j = 0, len, maxPlen = 0, pos = 0;
    len = strlen (s);
    if (len > 0)
    {
        maxPlen = 1;
        pos = 0;
    }
    for (i = 0; (len - i) > maxPlen && i < len; i++)
    {
        for (j = len - 1; (j - i + 1) > maxPlen && j > i; j--)
        {
//printf ("i = %d j = %d maxPlen=%d\n", i, j, maxPlen);
            if (isPalindrome (s, i, j))
            {
                maxPlen = j - i + 1;
                pos = i;
//printf ("Find palindrome maxPlen = %d pos=%d s=%s\n", maxPlen, pos, s+pos);
                break;
            }
        }
//printf ("i = %d maxPlen=%d\n", i, maxPlen);
    }
    char *r = "";
    if (maxPlen)
    {
        r = malloc (maxPlen + 1);
        memcpy (r, s + pos, maxPlen);
        r[maxPlen] = '\0';
        //printf ("longest pa is %s\n", r);
    }
    return r;
}

int expandAroundCenter (char *s, int len, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < len && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}
char* longestPalindromeGood (char* s) {
    if (s == NULL || strlen (s) < 1) return "";

    int i = 0, start = 0, end = 0;
    int sLen = strlen (s);
    for (i = 0; i < sLen; i++)
    {
        int len1 = expandAroundCenter(s, sLen, i, i);
        int len2 = expandAroundCenter(s, sLen, i, i + 1);
        int len = len1 > len2 ? len1:len2;
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    char *r = "";
    if (end - start + 1)
    {
        r = malloc (end - start + 2);
        memcpy (r, s + start, end - start + 1);
        r[end - start + 1] = '\0';
    }
    return r;
}

// 10. Regular Exoression Matching

void testLongestPalindrome (){
	
}
