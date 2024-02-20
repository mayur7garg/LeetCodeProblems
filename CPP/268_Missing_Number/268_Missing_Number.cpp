//https://leetcode.com/problems/missing-number

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int expectedSum = (n * (n + 1)) / 2;
		int actualSum = std::accumulate(nums.begin(), nums.end(), 0);
		return expectedSum - actualSum;
	}
};

int main()
{
	Solution s = Solution();

	std::vector<int> nums = { 3, 0, 1 };
	std::cout << "Output: " << s.missingNumber(nums) << "\tExpected: 2" << std::endl;

	nums = { 0, 1 };
	std::cout << "Output: " << s.missingNumber(nums) << "\tExpected: 2" << std::endl;

	nums = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	std::cout << "Output: " << s.missingNumber(nums) << "\tExpected: 8" << std::endl;
}