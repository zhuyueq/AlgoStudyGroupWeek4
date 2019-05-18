/*faster than 98% */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        DFS(candidates, 0, target, res, cur);
        return res;
    }
    void DFS(vector<int>& candidates, int j, int sum, vector<vector<int>>& res, vector<int>& cur){   
        for(int i=j;i<candidates.size();i++)
        {
            cur.push_back(candidates[i]);
            if (sum==candidates[i]) res.push_back(cur);
            else if (candidates[i]<=sum){//truncating...
                DFS(candidates, i, sum-candidates[i], res, cur);//can use one number unlimitedly...
            }
            cur.pop_back();     
        }
    }
};