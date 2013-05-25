/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 25 May, 2013, 8:14 PM
 */

#include <cstdlib>
# include <string>
# include <ctype.h>
# include <stdio.h>

using namespace std;

/*
 * 
 */

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        char c1, c2;
        if(s.length() == 0)
        {
            return true;
        }        
        bool flag = true;
        for(i=0, j=s.length(); i<=j; i++, j--)
        {
            while(!isalnum(s[i]) && i<=j)
            {
                i++;
            }
            if(i>j)
            {
                return true;
            }
            while(!isalnum(s[j]) && i<=j)
            {
                j--;
            }
            if(i>j)
            {
                return true;
            }
            if(isalpha(s[i]) && isalpha(s[j]))
            {
                c1 = tolower(s[i]);
                c2 = tolower(s[j]);
                if(c1 != c2)
                {
                    return false;
                }
            }
            else if(isdigit(s[i]) && isdigit(s[j]))
            {
                if(s[i] != s[j])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, char** argv) {
    string s = ". ";//"race a car";//"A man, a plan, a canal: Panama";
    Solution sol;
    bool r = sol.isPalindrome(s);
    printf("rr->%d\n", r);
    return 0;
}

