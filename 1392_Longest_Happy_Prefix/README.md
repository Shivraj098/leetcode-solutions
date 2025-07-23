# 1392. Longest Happy Prefix

🔗 [Problem Link](https://leetcode.com/problems/longest-happy-prefix/)  
📂 Category: String  
💪 Difficulty: Hard

---

## 🧠 Problem Statement

You are given a string `s`. Return the **longest prefix** of `s` which is also a **suffix** (excluding the entire string itself).

The returned string must be a proper prefix and suffix — it cannot be the whole string.

---

## 🚀 Approach (KMP-style LPS Array)

To efficiently find the longest prefix which is also a suffix, we use a technique inspired by the **KMP algorithm**.

### Key Idea:
- Build an `LPS` (Longest Prefix Suffix) array similar to KMP's preprocessing step.
- For each index `i`, `lps[i]` will store the length of the longest proper prefix which is also a suffix for the substring `s[0…i]`.
- At the end, `lps[n-1]` gives the answer.

> We **avoid full KMP matching**, only using the prefix array logic here.

---

## 🧾 Code Explanation (C++)

```cpp
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0); // LPS array
        int len = 0;

        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len])
                len = lps[len - 1]; // backtrack
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
            }
        }

        return s.substr(0, lps[n - 1]); // result
    }
};
