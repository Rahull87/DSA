class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majorityElement;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count = 1;
                majorityElement = nums[i];
            } else if (majorityElement == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        int countMajority = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == majorityElement) {
                countMajority++;
            }
        }

        if (countMajority > (n / 2)) {
            return majorityElement;
        }
        return -1;
    }
};
