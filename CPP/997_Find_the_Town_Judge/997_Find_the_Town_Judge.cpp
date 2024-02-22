//https://leetcode.com/problems/find-the-town-judge/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> netTrustCount(n);

		for (int i = 0; i < n; ++i) {
			netTrustCount[i] = 0;
		}

		for (auto& it : trust) {
			--netTrustCount[it[0] - 1];
			++netTrustCount[it[1] - 1];
		}

		for (int i = 0; i < n; ++i) {
			if (netTrustCount[i] == n - 1) {
				return i + 1;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s = Solution();

	int n = 2;
	std::vector<vector<int>> trust = { {1, 2} };
	std::cout << "Output: " << s.findJudge(n, trust) << "\tExpected: 2" << std::endl;

	n = 3;
	trust = { {1, 3}, {2, 3} };
	std::cout << "Output: " << s.findJudge(n, trust) << "\tExpected: 3" << std::endl;

	n = 3;
	trust = { {1, 3}, {2, 3}, {3, 1 } };
	std::cout << "Output: " << s.findJudge(n, trust) << "\tExpected: -1" << std::endl;

	n = 4;
	trust = { {1, 3}, {1, 4}, {2, 3 }, {4, 3 } };
	std::cout << "Output: " << s.findJudge(n, trust) << "\tExpected: 3" << std::endl;
}