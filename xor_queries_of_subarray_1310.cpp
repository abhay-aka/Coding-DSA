class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xorsum(arr.size() , 0);
        xorsum[0] = arr[0];
        for (int i = 1; i <arr.size(); i++ ) {
            xorsum[i] = xorsum[i-1] ^ arr[i];
        }
        vector<int> ans;
        for(auto it: queries) {
            int i = it[0];
            int j = it[1];
            int xorResult = xorsum[j];
            if (i > 0) xorResult ^= xorsum[i-1];
            ans.push_back(xorResult);
        }
        return ans;
    }
};