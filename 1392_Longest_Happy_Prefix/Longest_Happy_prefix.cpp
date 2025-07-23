// This is the solution to the leetcode hard problem "Longest Happy Prefix"
// Problem link: https://leetcode.com/problems/longest-happy-prefix/

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0); // using a simple array to store lengths (we’ll avoid full KMP logic)

        int len = 0;  // length of the current longest prefix-suffix
        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];  // backtrack
            }
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
            }
        }

        return s.substr(0, lps[n - 1]);  // longest prefix which is also a suffix
    }
};