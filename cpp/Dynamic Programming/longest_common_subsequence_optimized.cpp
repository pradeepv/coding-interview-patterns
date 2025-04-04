#include <vector>
#include <string>
#include <algorithm>

int longestCommonSubsequenceOptimized(std::string& s1, std::string& s2) {
    // Initialize 'prevRow' as the DP values of the last row.
    std::vector<int> prevRow(s2.length() + 1, 0);
    for (int i = s1.length() - 1; i >= 0; i--) {
        // Set the last cell of 'currRow' to 0 to set the base case for 
        // this row. This is done by initializing the entire row to 0.
        std::vector<int> currRow(s2.length() + 1, 0);
        for (int j = s2.length() - 1; j >= 0; j--) {
            // If the characters match, the length of the LCS at
            // 'currRow[j]' is 1 + the LCS length of the remaining
            // substrings ('prevRow[j + 1]').
            if (s1[i] == s2[j]) {
                currRow[j] = 1 + prevRow[j + 1];
            }
            // If the characters don't match, the LCS length at
            // 'currRow[j]' can be found by either:
            // 1. Excluding the current character of s1 ('prevRow[j]').
            // 2. Excluding the current character of s2 
            // ('currRow[j + 1]').
            else {
                currRow[j] = std::max(prevRow[j], currRow[j + 1]);
            }
        }
        // Update 'prevRow' with 'currRow' values for the next 
        // iteration.
        prevRow = currRow;
    }
    return prevRow[0];
}