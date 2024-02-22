//https://leetcode.com/problems/bitwise-and-of-numbers-range

#include<iostream>

class Solution {
public:
	int rangeBitwiseAnd(int left, int right) {
		if (right >= ((long)left * 2)) {
			return 0;
		}

		while (right > left) {
			right &= (right - 1);
		}

		return right;
	}
};

int main()
{
	Solution s = Solution();

	int left = 5;
	int right = 7;
	std::cout << "Output: " << s.rangeBitwiseAnd(left, right) << "\tExpected: 4" << std::endl;

	left = 0;
	right = 0;
	std::cout << "Output: " << s.rangeBitwiseAnd(left, right) << "\tExpected: 0" << std::endl;

	left = 1;
	right = 2147483647;
	std::cout << "Output: " << s.rangeBitwiseAnd(left, right) << "\tExpected: 0" << std::endl;

	left = 7;
	right = 15;
	std::cout << "Output: " << s.rangeBitwiseAnd(left, right) << "\tExpected: 0" << std::endl;

	left = 16;
	right = 31;
	std::cout << "Output: " << s.rangeBitwiseAnd(left, right) << "\tExpected: 16" << std::endl;
}