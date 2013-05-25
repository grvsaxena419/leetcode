/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 25 May, 2013, 2:12 PM
 */

#include <cstdlib>
# include <limits.h>

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
    int find_depth(TreeNode *root)
    {
        if(root)
        {
            if(!root->left && !root->right)
            {
                return 1;
            }
            else
            {
                int val_l, val_r;
                val_l = find_depth(root->left);
                val_r = find_depth(root->right);
                return (val_l<val_r?val_l:val_r) + 1;
            }
        }
        else
        {
            return INT_MAX;
        }
    }
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
        {
            return 0;
        }
        return find_depth(root);
    }
};

int main(int argc, char** argv) {
    Solution s;
    //s.minDepth()
    return 0;
}

