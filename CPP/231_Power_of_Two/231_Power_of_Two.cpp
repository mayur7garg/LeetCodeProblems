//https://leetcode.com/problems/power-of-two

#include<iostream>

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n > 0) && (n == (-n & n));
	}
};

int main()
{
	Solution s = Solution();

	int n = 1;
	std::cout << "Output: " << s.isPowerOfTwo(n) << "\tExpected: 1" << std::endl;

	n = 16;
	std::cout << "Output: " << s.isPowerOfTwo(n) << "\tExpected: 1" << std::endl;

	n = 3;
	std::cout << "Output: " << s.isPowerOfTwo(n) << "\tExpected: 0" << std::endl;

	n = 15;
	std::cout << "Output: " << s.isPowerOfTwo(n) << "\tExpected: 0" << std::endl;

	n = -16;
	std::cout << "Output: " << s.isPowerOfTwo(n) << "\tExpected: 0" << std::endl;
}