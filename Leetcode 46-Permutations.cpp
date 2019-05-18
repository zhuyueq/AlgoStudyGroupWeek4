/*
faster than 96%
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        vector<int> visited(nums.size(),0);
        count(result,cur,nums,visited,0);
        return result;
    }
    
    void count(vector<vector<int>>& result,vector<int> cur,vector<int>& nums,vector<int>& visited,int dep)
    {
        if (dep==nums.size()) 
        {
            result.push_back(cur);
            return;
        }
        
        for (int i=0;i<nums.size();i++)
        {
            if (visited[i]!=1)
            {
                visited[i]=1;
                cur.push_back(nums[i]);
                count(result,cur,nums,visited,dep+1);
                cur.pop_back();
                visited[i]=0;
            }
        }
    }
};