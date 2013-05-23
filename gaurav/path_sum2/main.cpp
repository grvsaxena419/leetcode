/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 23 May, 2013, 6:41 PM
 */

#include <cstdlib>
#include <vector>
# include <iostream>

using namespace std;

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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
public:
    int reqd;
    vector<vector<int> > paths;
    
    void find_sum(TreeNode *root, long long int sum, vector<int> &path)
    {
        bool l_v, r_v;
        if(root)
        {
            sum += root->val;
            path.push_back(root->val);
            // leaf
            if(!root->left && !root->right)
            {
                if(sum == reqd)
                {
                    vector<int> cpy(path);
                    paths.push_back(cpy);
                }
            }
            if(root->left)
            {
                find_sum(root->left, sum, path);                
            }
            if(root->right)
            {
                find_sum(root->right, sum, path);
            }
            path.pop_back();
        }    
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> path;
        paths.clear();
        
        reqd = sum;
        if(root)
        {
            find_sum(root, 0, path);            
        }
        return paths;
    }
};


int main(int argc, char** argv) {
    TreeNode *t1, *t2, *t3, *root;
    
    root = new TreeNode(0);
    t2 = new TreeNode(1);
    t3 = new TreeNode(1);
    
    root->left = t2;
    root->right = t3;
    Solution s;
    vector<vector<int> > vv = s.pathSum(root, 1);
    
    for(vector<vector<int> >::iterator iter = vv.begin(); iter != vv.end();
            iter++)
    {
        cout<<"{";
        for(vector<int>::iterator itr = iter->begin(); itr!= iter->end();
                itr ++)
        {
            cout<<*itr<<", ";
        }
        cout<<"}"<<endl;
    }
    
    return 0;
}

