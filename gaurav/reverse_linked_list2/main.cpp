/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 23 May, 2013, 10:47 PM
 */

# include <cstdlib>
# include <stdio.h>

using namespace std;

/*
 * 
 */

/**
 * Definition for singly-linked list.
 */

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr, *prev, *prev2, *cur, *next;
  //      printf("%x %d %d\n", head, m, n);
    //    fflush(stdout);
        
        ptr = head;
        int i;
        prev = NULL;
        for(i=0; i<m-1; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        
        prev2 = NULL;
        cur = ptr;
        
        while(cur != NULL && i<=n-1)
        {
            next = cur -> next;
            cur -> next = prev2;
            prev2 = cur;
            cur = next;
            i++;
        }
        
        ptr -> next = cur;
        if(prev)
        {
            prev -> next = prev2;
        }
        else
        {
            head = prev2;
        }
        
//        for(i=0; i<m-1; i++)
//        {
//            prev2 = ptr;
//            ptr = ptr->next;
//        }
        
        return head;
    }
};

void display(ListNode *head)
{
    ListNode *ptr = head;
    
    while (ptr != NULL)
    {
        printf("->%d", ptr->val);
        ptr = ptr->next;
    }
    printf ("\n");
}

int main(int argc, char** argv) {
    ListNode *ptr, *head = NULL;
    int i;
    for(i=0; i<5; i++)
    {
        ptr = new ListNode(i*10);
        ptr -> next = head;
        head = ptr;
    }
    
    display(head);
    
    Solution sol;
    head = sol.reverseBetween(head, 1,6);
    
    display(head);
    return 0;
}

