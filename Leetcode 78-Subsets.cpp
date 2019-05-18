/*
faster than 99%
*/


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
                cur.push_back(nums[i]);
                count(result,cur,nums,i+1);
                cur.pop_back();
        }
    }
    
};