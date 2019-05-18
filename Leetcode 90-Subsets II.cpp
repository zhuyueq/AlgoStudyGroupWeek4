/*
faster than 98%, same as Leetcode 78 Subsets
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        count(result,cur,nums,0);
        return result;
    }
    
    void count(vector<vector<int>>& result,vector<int> cur,vector<int> nums,int j)
    {
        result.push_back(cur);
        
        for (int i=j;i<nums.size();i++)
        {
            if (i==j || nums[i]!=nums[i-1]) {
                cur.push_back(nums[i]);
                count(result,cur,nums,i+1);
                cur.pop_back();
            }
        }
    }
};