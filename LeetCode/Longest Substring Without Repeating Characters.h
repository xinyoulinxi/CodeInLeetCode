#pragma once
#include"headFile.h"

//用桶的方式解决不重复字符串问题
class Solution {
public:
	static int lengthOfLongestSubstring(string s) {
		size_t max = 0;
		short count[128] = { 0 };
		int l = 0, r = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (++count[s[i]] != 2) {
				++r;
				if (r - l > max) {
					max = r - l;
				}
			}
			else {
				while (count[s[l]] != 2) {
					--count[s[l]];
					l++;
				}
				l++;
				count[s[i]]--;
				r++;
			}
		}
		return max;
	}
};

void test() {
		cout << Solution::lengthOfLongestSubstring("abcabcbb") << endl;
}