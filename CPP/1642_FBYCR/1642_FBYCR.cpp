//https://leetcode.com/problems/furthest-building-you-can-reach

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		priority_queue<int, vector<int>, greater<int>> ladderHeights;
		int lenHeights = heights.size();

		for (int i = 1; i < lenHeights; ++i)
		{
			if (heights[i] > heights[i - 1])
			{
				int heightDiff = heights[i] - heights[i - 1];

				if (ladders > 0)
				{
					ladderHeights.push(heightDiff);
					ladders--;
				}
				else {
					if (ladderHeights.size() > 0)
					{
						int shortestLadder = ladderHeights.top();
						if ((shortestLadder < heightDiff) && (shortestLadder <= bricks))
						{
							bricks -= shortestLadder;
							ladderHeights.pop();
							ladderHeights.push(heightDiff);
						}
						else if (bricks >= heightDiff)
						{
							bricks -= heightDiff;
						}
						else {
							return i - 1;
						}
					}
					else if (bricks >= heightDiff)
					{
						bricks -= heightDiff;
					}
					else {
						return i - 1;
					}
				}

			}
		}
		return lenHeights - 1;
	}
};

int main()
{
	Solution s = Solution();

	std::vector<int> heights = { 4, 2, 7, 6, 9, 14, 12 };
	int bricks = 5;
	int ladders = 1;
	std::cout << "Output: " << s.furthestBuilding(heights, bricks, ladders) << "\tExpected: 4" << std::endl;

	heights = { 4, 12, 2, 7, 3, 18, 20, 3, 19 };
	bricks = 10;
	ladders = 2;
	std::cout << "Output: " << s.furthestBuilding(heights, bricks, ladders) << "\tExpected: 7" << std::endl;

	heights = { 14, 3, 19, 3 };
	bricks = 17;
	ladders = 0;
	std::cout << "Output: " << s.furthestBuilding(heights, bricks, ladders) << "\tExpected: 3" << std::endl;
}