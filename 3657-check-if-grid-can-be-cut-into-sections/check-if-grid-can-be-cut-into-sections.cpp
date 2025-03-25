class Solution {
public:
    int merge(vector<pair<int, int>> x) {
        vector<pair<int, int>> merged;
        for (auto it: x) {
            if (merged.size() == 0 || merged[merged.size() - 1].second <= it.first) {
                merged.push_back(it);
            } else {
                merged[merged.size() - 1].second = max(merged[merged.size() - 1].second, it.second);
            }
        }
        return merged.size();
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x, y;
        for (auto it: rectangles) {
            int start_x = it[0], end_x = it[2];
            int start_y = it[1], end_y = it[3];
            x.push_back({start_x, end_x});
            y.push_back({start_y, end_y});
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int ansx = merge(x);
        int ansy = merge(y);
        if (ansx > 2 || ansy > 2) return true;
        return false;

    }
};