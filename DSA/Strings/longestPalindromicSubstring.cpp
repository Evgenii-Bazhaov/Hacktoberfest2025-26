#include <iostream>
#include <string>
using namespace std;

// Expand around center
string expandAroundCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindromicSubstring(const string &s) {
    if (s.empty()) return "";
    string maxPal = "";
    for (int i = 0; i < s.size(); i++) {
        string odd = expandAroundCenter(s, i, i);       // Odd length
        string even = expandAroundCenter(s, i, i + 1);  // Even length
        if (odd.size() > maxPal.size()) maxPal = odd;
        if (even.size() > maxPal.size()) maxPal = even;
    }
    return maxPal;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Longest Palindromic Substring: " << longestPalindromicSubstring(s) << endl;
    return 0;
}
