/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
*/

class Solution {
public:
    void inorder(TreeNode *root,vector<int> &ans){
        if(!root)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2,res;
        inorder(root1,v1);
        inorder(root2,v2);
        int i=0,j=0;
        
        int n=v1.size();
        int m=v2.size();
        
        while(i<n and j<m){
            if(v1[i]<=v2[j]){
                res.push_back(v1[i]);
                i++;
            }else{
                res.push_back(v2[j]);
                j++;
            }
        }
        while(i<n){
            res.push_back(v1[i]);
            i++;
        }
            
        
        while(j<m){
            res.push_back(v2[j]);
            j++;
        }
            
        
        return res;
        
    }
};