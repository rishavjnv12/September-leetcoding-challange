/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9
*/


#include <bits/stdc++.h>

using namespace std;

bool has(map<int,int> &mp,int k){

    if(mp[k]){
        mp[k]--;
        return true;
    }
    return false;
}

string helper(map<int,int> mp,int k){
    string ans="";
    ans+=to_string(k);
    mp[k]--;
    bool found=false;

    int max_second_digit_of_hour;
    if(k==2)
        max_second_digit_of_hour=3;
    else
        max_second_digit_of_hour=9;
    
    

    for(int i=max_second_digit_of_hour;i>=0;i--){
        if(has(mp,i)){
            found=true;
            ans+=to_string(i);
            break;
        }
    }
    if(!found)
        return "";

    ans+=':';
    found=false;
    //for minute
    for(int i=5;i>=0;i--){
        if(has(mp,i)){
            ans+=to_string(i);
            found=true;
            break;
        }
    }
    if(!found){
        return "";
    }

    for(int i=9;i>=0;i--){
        if(has(mp,i)){
            ans+=to_string(i);
            break;
        }
    }

    return ans;


}

string largestTimeFromDigits(vector<int>& A) {
    map<int,int> mp;

    for(auto i:A) 
        mp[i]++; 
    
    string ans="";
    for(int i=2;i>=0;i--){
        if(mp[i]>=1){
            ans=helper(mp,i);
            if(ans.size()==5)
                return ans;
        }
    }

    return "";

    
}


int main(){
    vector<int> v={2,0,6,6};
    cout<<largestTimeFromDigits(v)<<endl;
    return 0;
}