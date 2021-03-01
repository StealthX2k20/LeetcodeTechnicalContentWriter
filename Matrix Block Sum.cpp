//problem link : https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int k = K;
        int n = mat.size();
        int m = mat[0].size();
        
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = mat[0][0];
        
        for(int i = 1; i < m; i++) dp[1][i + 1] = dp[1][i] + mat[0][i];
        for(int i = 1; i < n; i++) dp[i + 1][1] = dp[i][1] + mat[i][0];
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
               dp[i + 1][j + 1] = mat[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
            }
        }
        
        vector<vector<int>> res;
        int r1, c1, r2, c2, s1, s2, s3, s4;
        vector<int> cur;
        for(int i = 1; i <= n; i++)
        {cur.clear();
            for(int j = 1; j <= m; j++)
            {
              r1 = max(0, i - k);
              c1 = max(0, j - k);
              r2 = min(n, i + k);
              c2 = min(m, j + k);
              
              s1 = dp[r2][c2];
              s2 = (r1 - 1 >=0 and c1 - 1 >= 0) ? dp[r1 - 1][c1 - 1] : 0;
              s3 = r1 - 1 >= 0 ? dp[r1 - 1][c2] : 0;
              s4 = c1 - 1 >= 0 ? dp[r2][c1 - 1] : 0;
                
              cur.push_back(s1 + s2 - s3 - s4);
            }
         res.push_back(cur);
        }
        return res;
    }
};
