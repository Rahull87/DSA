class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; ++i) {
            while (nums[i] == 2 && i < p2) {
                swap(nums[i], nums[p2--]);
            }
            while (nums[i] == 0 && i > p0) {
                swap(nums[i], nums[p0++]);
            }
        }
    }
};
