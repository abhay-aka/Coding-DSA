class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(), pivot);
        int left = 0, right = nums.size() - 1;
        int i = 0, j = nums.size() - 1;
        while (i < nums.size() && j >= 0) {
            if (nums[i] < pivot) {
                ans[left] = nums[i];
                left++;
            }
            if (nums[j] > pivot) {
                ans[right] = nums[j];
                right--;
            }
            i++;
            j--;
        }
        return ans;
    }
};