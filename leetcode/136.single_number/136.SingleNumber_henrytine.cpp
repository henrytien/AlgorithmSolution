// Source : https://leetcode.com/problems/single-number/
// Author : henrytine
// Date   : 2020-08-11

/***************************************************************************************************** 
 *
 * Given a non-empty array of integers, every element appears twice except for one. Find that single 
 * one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra 
 * memory?
 * 
 * Example 1:
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * Example 2:
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 ******************************************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 0;
        
		for (int i = 0; i < nums.size(); ++i) {
			if (nums.size()-1 == i)
				return nums[i];
			if (nums[i] == nums[i + 1]) {
				++count;
				++i;
			}
			if (count == 0) {
				if (nums[i] != nums[i + 1])
					return nums[i];
				else
					return nums[i];
			}
			if (count == 1)
				count = 0;
		}
        return 0;
    }
};