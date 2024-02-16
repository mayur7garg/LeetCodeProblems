//https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

#include <iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

class Solution {
public:
	int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
		std::unordered_map<int, int> freq_map;

		for (int& i : arr) {
			++freq_map[i];
		}

		std::vector <int> freqs;

		for (auto i = freq_map.begin(); i != freq_map.end(); ++i) {
			freqs.push_back(i->second);
		}

		std::sort(freqs.begin(), freqs.end());
		int s = freqs.size();

		for (int i = 0; i < s; ++i) {
			if (freqs[i] <= k) {
				k -= freqs[i];
			}
			else {
				return s - i;
			}

		}

		return 0;
	}
};

int main()
{
	Solution s = Solution();

	std::vector<int> v = { 5, 5, 4 };
	int k = 1;
	std::cout << "Output: " << s.findLeastNumOfUniqueInts(v, k) << "\tExpected: 1" << std::endl;

	v = { 4, 3, 1, 1, 3, 3, 2 };
	k = 3;
	std::cout << "Output: " << s.findLeastNumOfUniqueInts(v, k) << "\tExpected: 2" << std::endl;

	v = { 1 };
	k = 1;
	std::cout << "Output: " << s.findLeastNumOfUniqueInts(v, k) << "\tExpected: 0" << std::endl;
}