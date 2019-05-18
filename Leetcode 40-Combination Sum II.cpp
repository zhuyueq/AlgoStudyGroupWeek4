class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        DFS(candidates, 0, target, res, cur);
        return res;
    }
    void DFS(vector<int>& candidates, int j, int sum, vector<vector<int>>& res, vector<int>& cur){
        for(int i=j;i<candidates.size();i++)
        {
            if (i==j || candidates[i]!=candidates[i-1]){//can not contain duplicate subsets
            cur.push_back(candidates[i]);
            if (sum==candidates[i]) res.push_back(cur);
            else if (candidates[i]<=sum) DFS(candidates, i+1, sum-candidates[i], res, cur);//cannot use one number twice, truncating
                cur.pop_back(); 
            }
        }
    }
};
//1 1 2 5 6 7 10