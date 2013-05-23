/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 22 May, 2013, 7:24 PM
 */

/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements 
 * initialized in A and B are m and n respectively.
 */

#include <cstdlib>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ctr, i, j;
        ctr = m + n - 1;
        i = m - 1;
        j = n - 1;
        
        while(i>=0 && j>=0)
        {
            if(A[i] > B[j])
            {
                A[ctr] = A[i];
                i --;
                ctr --;
            }
            else
            {
                A[ctr] = B[j];
                j --;
                ctr --;
            }
        }
        
        while(i>=0)
        {
            A[ctr] = A[i];
            i--;
            ctr--;
        }
        
        while(j>=0)
        {
            A[ctr] = B[j];
            j--;
            ctr --;            
        }
    }
};

/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}

