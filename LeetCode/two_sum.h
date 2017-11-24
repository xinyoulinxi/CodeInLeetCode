#include"headFile.h"
//运用哈希表进行查询，以空间换时间
//双for查询耗时为此方式的十倍差距以上
class Solution {
public:
	static vector<int> twoSum(vector<int>& nums, int target) {
		auto length = nums.size();
		unordered_map<int, int> hash;
		for (int i = 0; length != i; ++i) {
			int numberTofind = target - nums[i];
			if (hash.find(numberTofind) != hash.end()) {
				return vector<int>({ hash[numberTofind],i });
			}
			hash[nums[i]] = i;
		}
	}
};

void test() {
	Solution::twoSum(vector<int>({ 2,7,11,5 }), 9);
}