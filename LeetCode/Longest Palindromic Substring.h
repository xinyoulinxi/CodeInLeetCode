#pragma once
#include"headFile.h"
//dp解法
class Solution {
public:
	static string longestPalindrome(string s) {
		string resultString;
		int maxLength = 1;
		int maxStartIndex = 0;
		const int length = s.size();
		if (length == 0)return NULL;
		if (length == 1)return s;
		bool dp[1001][1001] = { false };
		for (int i = 0; i < length; ++i) {
			dp[i][i] = true;
			if (i<length - 1 && s.at(i) == s.at(i + 1)) {//长度为2的回文
				dp[i][i + 1] = true;
				maxStartIndex = i;
				maxLength = 2;
			}
		}
		for (int len = 3; len <= length; len++) {
			for (int i = 0; i <= length - len; i++) {
				int j = len + i - 1;//子串结束位置
				if (dp[i + 1][j - 1] && s.at(i) == s.at(j)) {
					dp[i][j] = true;
					maxLength = len;
					maxStartIndex = i;
				}
			}
		}
		return s.substr(maxStartIndex, maxLength);
	}

};
//中心扩展，分成奇偶两种回文子串进行解决
class Solution {
public:
	string findLongestPalindrome(string &s)
	{
		const int length = s.size();
		if (length == 1)return s;
		if (length == 0)return NULL;

		int maxlength = 0;
		int start;

		for (int i = 0; i < length; i++)//长度为奇数
		{
			int j = i - 1, k = i + 1;
			while (j >= 0 && k < length&&s.at(j) == s.at(k))
			{
				if (k - j + 1 > maxlength)
				{
					maxlength = k - j + 1;
					start = j;
				}
				j--;
				k++;
			}
		}

		for (int i = 0; i < length; i++)//长度为偶数
		{
			int j = i, k = i + 1;
			while (j >= 0 && k < length&&s.at(j) == s.at(k))
			{
				if (k - j + 1 > maxlength)
				{
					maxlength = k - j + 1;
					start = j;
				}
				j--;
				k++;
			}
		}
		if (maxlength > 0)
			return s.substr(start, maxlength);
		return NULL;
	}
};