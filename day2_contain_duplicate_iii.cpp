/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
 

Constraints:

0 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 104
0 <= t <= 231 - 1

*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n=nums.size();
        set<long long> st;
        
        for(int i=0;i<n;i++){
            if(i>k)
                st.erase(nums[i-k-1]);
            
            auto pos=st.lower_bound((long long)nums[i]-t);
            
            if(pos!=st.end() and abs(*pos-nums[i])<=t)
                return true;
            
            st.insert(nums[i]);
        }
        return false;
        
        
    }
};