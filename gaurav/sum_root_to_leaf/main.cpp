/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 25 May, 2013, 12:53 PM
 */

#include <cstdlib>
# include <vector>
using namespace std;

/*
 * 
 */
/**
 * Definition for binary tree
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
    long long int sum_total;
    void sum_numbers(TreeNode *ptr, vector<int> &nums)
    {
        long long int val;
        if(ptr)
        {
            nums.push_back(ptr->val);
            if(!ptr->left && !ptr->right)
            {
                val = 0;
                for(vector<int>::iterator itr = nums.begin();
                        itr!= nums.end(); itr++)
                {
                    val *= 10;
                    val += *itr;
                }
                sum_total += val;
            }
            else
            {
                sum_numbers(ptr->left, nums);
                sum_numbers(ptr->right, nums);
            }
            nums.pop_back();
        }
        
    }
    
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> nums;
        sum_total = 0;
        sum_numbers(root, nums);
        
        return sum_total;
    }
};


int main(int argc, char** argv) {

    return 0;
}

