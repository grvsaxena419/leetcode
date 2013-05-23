/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 21 May, 2013, 11:53 PM
 */

#include <cstdlib>

using namespace std;

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
public:
    int reqd;
    
    bool find_sum(TreeNode *root, long long int sum)
    {
        bool l_v, r_v;
        if(root)
        {
            sum += root->val;
            // leaf
            if(!root->left && !root->right)
            {
                if(sum == reqd)
                    return true;
            }
            if(root->left)
            {
                l_v = find_sum(root->left, sum);
                if(l_v)
                {
                    return true;
                }
            }
            if(root->right)
            {
                r_v = find_sum(root->right, sum);
                if(r_v)
                {
                    return true;
                }
            }
            return false;
        }    
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
        {
            return false;
        }
        reqd = sum;
        return find_sum(root, 0);
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    Solution s;
    s.hasPathSum();
    return 0;
}

