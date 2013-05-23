/* 
 * File:   main.cpp
 * Author: gaurav
 *
 * Created on 23 May, 2013, 7:02 PM
 */

# include <cstdlib>
# include <vector>
# include <string>
# include <iostream>
# include <set>
# include <sstream>
# include <stdio.h>

using namespace std;

/*
 * 
 */

class Solution {
    set<string> ips;
    char *str; 
    int len;
    void find_address(int index, vector<int> &ip)
    {
        int val,i;
        if(index == len && ip.size() == 4)
        {
            vector<int>::iterator itr = ip.begin();
            std::stringstream sstream;
            sstream << *itr;
            itr ++;
            for(;itr != ip.end(); itr++)
            {
                sstream << "." << *itr;
            }
            ips.insert(sstream.str());
        }
        else if(ip.size() >=4)
        {
            return;
        }
        else
        {
            for(i=index, val=0; i<len; i++)
            {
                val = val * 10;
                val = val + str[i] - '0';
                if(val < 256 && ip.size() < 4)
                {
                    string stemp = string(str + index , i-index + 1);
                    ip.push_back(val);
                    find_address(i+1, ip);
                    ip.pop_back();
                }
                else
                {
                    break;
                }
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vv;
        ips.clear();
        str = (char*) s.c_str();
        len = s.length();
        find_address(0, vv);
        //cout<< "size->" <<ips.size();
        fflush(stdout);
        vector<string> output(ips.begin(), ips.end());
        //std::copy(ips.begin(), ips.end(), output.begin());
        return output;
    }
};


int main(int argc, char** argv) {
    Solution s;
    vector<string> vv;
    vv = s.restoreIpAddresses("00000100");
    
    cout<<"{";
    for(vector<string>::iterator itr = vv.begin(); itr!= vv.end();
            itr ++)
    {
        cout<<*itr<<", ";
    }
    cout<<"}"<<endl;

    return 0;
}

