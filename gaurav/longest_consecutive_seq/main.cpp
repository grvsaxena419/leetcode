/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 25 May, 2013, 3:01 PM
 */

#include <cstdlib>
#include <vector>
# include <limits.h>
# include <stdio.h>
# include <map>
using namespace std;

/*
 * 
 */

class Solution {
    
public:    
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int,bool> hash;
        map<int, int> count;
        int min, max, max_len, cont_len, i;
        min = INT_MAX;
        max = INT_MIN;
        for(vector<int>::iterator itr = num.begin();
                itr != num.end(); itr++)
        {
            if(*itr<min)
            {
                min = *itr;
            }
            if(*itr>max)
            {
                max = *itr;
            }
            hash[*itr] = true;
        }
        max_len = 0;        
        cont_len = 0;
        
        for(map<int, bool>::iterator itr = hash.begin();
                itr != hash.end(); itr++)
        {
            i = itr->first;
            if(count.find(i) != count.end())
            {
                continue;
            }
            if(count.find(i+1)!= count.end())
            {
                count[i] = count[i+1] + 1;
                cont_len = count[i];
            }
            else
            {
                while(hash[i])
                {
                    cont_len ++;
                    count[i] = cont_len;
                    i++;
                }
            }
            if(cont_len > max_len)
            {
                max_len = cont_len;                
            }
            cont_len = 0;
        }
        
//        for(i=min; i<=max; i++)
//        {
//            if(hash[i])
//            {
//                cont_len ++;
//                if(cont_len > max_len)
//                {
//                    max_len = cont_len;
//                }
//            }
//            else
//            {
//                cont_len = 0;
//            }
//        }
        return max_len;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int max;
    int array[] = {7, 15, 9, 14, 6, 8, 10};//{2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
    int size = 7;
    vector<int> tt(array, array+size);
    max = s.longestConsecutive(tt);
    printf ("%d\n", max);
    return 0;
}

