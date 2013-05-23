/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 19 May, 2013, 4:10 PM
 */

#include <cstdlib>
# include <vector>
# include <string>
# include <iostream>
# include <stdio.h>
using namespace std;

/*
 * 
 */

class Solution {
public:
    vector< vector<string> > palindromes;
    
    void partition_palin(char *str, int strlen, vector<string> &palindrome)
    {
        printf("(%x %d)\n", str, strlen);
        fflush(stdout);
        int i, j, k, length;        
        bool flag;        
        if(strlen == 0)
        {
            palindromes.push_back(palindrome);            
            return;
        }
        
//        for(i=0;str[i]; )
//        {
            i=0;
            for(length = 1; length<=strlen;)
            {
                flag = true;
                for(j=i, k=i+length - 1; j<=k; j++,k--)
                {
                    if(str[j] != str[k])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) 
                {
                    palindrome.push_back(string(str + i, length));
                    partition_palin(str + length, strlen - length, palindrome);
                    palindrome.pop_back();
                }
                length ++;
            }
            
//            if(j<=k)
//            {
//                palindrome.push_back(string(str[i], str[i + length - 1]));
//                i = i + length - 1;
//            }
//            else
//            {
//                palindrome.push_back(string(str[i], str[i + length]));
//                i ++;
//            }
            
            i = i + length;            
//        }
    }
    
    vector< vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = 1, j,k;
        int strln = s.length();
        char *str = (char*)s.c_str();
        vector<string> palindrome;
        palindromes.clear();
        palindrome.clear();        
        partition_palin(str, strln, palindrome);
        return palindromes;
        
//        vector<string> palindrome;
//        
//        for(length = 1; length<strln; length++)
//        {
//            palindrome.clear();
//            for(int i= length - 1; i < strln - length + 1; )
//            {
//                if(length %2 == 1)
//                {
//                    for(j=i, k=i+length-1; j<=k; j++,k--)
//                    {
//                        if(str[j] != str[k])
//                            break;
//                    }
//                    if(j<=k)
//                    {
//                        palindrome.push_back(string(str[i], str[i + length - 1]));
//                        i = i + length - 1;
//                    }
//                    else
//                    {
//                        palindrome.push_back(string(str[i], str[i + 1]));
//                        i ++;
//                    }
//                }
//            }
//        }
        
    }
};




int main(int argc, char** argv) {
    Solution s;
    string ss = "gggggg";
    vector<vector<string> > vv = s.partition(ss);
    
    for(vector<vector<string> >::iterator iter = vv.begin(); iter != vv.end();
            iter++)
    {
        cout<<"{";
        for(vector<string>::iterator itr = iter->begin(); itr!= iter->end();
                itr ++)
        {
            cout<<*itr<<", ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}

