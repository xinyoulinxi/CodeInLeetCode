#include"headFile.h"
//���ù�ϣ����в�ѯ���Կռ任ʱ��
//˫for��ѯ��ʱΪ�˷�ʽ��ʮ���������
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