/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 25 May, 2013, 1:42 PM
 */

#include <cstdlib>
# include <stdio.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
    int find_length(ListNode *head)
    {
        int length = 0;
        while(head)
        {
            head = head ->next;
            length ++;
        }
        return length;
    }
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr, *save;
        int i, len;
        if(head == NULL)
        {
            return head;
        }
        
        len = find_length(head);
        k = k % len;
        if(k == 0)
        {
            return head;
        }
        
        save = head;
        for(i=0; i<k&&save; i++)
        {
            save = save->next;
        }
        if(!save)
        {
            return head;
        }
        ptr = head;
        while(save->next != NULL)
        {
            save = save->next;
            ptr = ptr->next;
        }
        if(save)
        {
            save->next = head;
            head = ptr->next;
        }
        ptr->next = NULL;
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

/*
 * 
 */
int main(int argc, char** argv) {
    Solution s;
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    display(head);
    
    head = s.rotateRight(head,2);
    display(head);
    return 0;
}

