/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 23 May, 2013, 7:02 PM
 */

#include <cstdlib>
#include <vector>
#include <string>
# include <iostream>

using namespace std;

/*
 * 
 */

class Solution {
    vector<string> ips;
    char *str; 
    int len;
    void find_address(int index, vector<string> &ip)
    {
        int val,i;
        if(index == len)
        {
            vector<string>::iterator itr = ip.begin();
            string ip_add = "" + *itr;
            itr ++;
            for(;itr != ip.end(); itr++)
            {
                ip_add = "." + ip_add + *itr;
            }
            ips.push_back(ip_add);
        }
        else
        {
            for(i=index, val=0; i<len; i++)
            {
                val = val * 10;
                val = val + str[i] - '0';
                if(val < 256)
                {
                    ip.push_back(string(str[index], str[i]));
                    find_address(i+1, ip);
                    ip.pop_back();
                }
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vv;
        ips.clear();
        str = (char*) s.c_str();
        len = s.length();
        find_address(0, vv);
        return ips;
    }
};


int main(int argc, char** argv) {
    Solution s;
    vector<string> vv;
    vv = s.restoreIpAddresses("25525511135");
    
    cout<<"{";
    for(vector<string>::iterator itr = vv.begin(); itr!= vv.end();
            itr ++)
    {
        cout<<*itr<<", ";
    }
    cout<<"}"<<endl;

    return 0;
}

