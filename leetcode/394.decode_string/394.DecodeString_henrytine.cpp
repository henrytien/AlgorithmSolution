// Source : https://leetcode.com/problems/decode-string/
// Author : henrytine
// Date   : 2020-08-06

/***************************************************************************************************** 
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is 
 * being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces, square brackets are 
 * well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any digits and that digits are 
 * only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 ******************************************************************************************************/

class Solution {
public:
    string decodeString(string s) {
       int i = 0;
       return decodeString(s, i);
    }
private:
    string decodeString(string &s, int &i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i++];
            } else {
                int n  = 0;
                
                while (i < s.length() && isdigit(s[i]))
                 n = n*10 + s[i++] - '0';
                
                i++;
                string temp = decodeString(s, i);
                i++;
                
                while (n-- > 0) {
                    res += temp;
                }
            }
        } 
        return res;
    }
};