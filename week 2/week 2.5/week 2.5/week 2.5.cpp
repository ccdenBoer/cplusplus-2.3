// week 2.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

std::vector<int> findLargestBlock(const std::vector<std::vector<int>>& m) {
    int n = m.size();
    int max_size = 0;
    int max_i = -1;
    int max_j = -1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }

                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_i = i - max_size + 1;
                    max_j = j - max_size + 1;
                }
            }
        }
    }

    std::vector<int> result;
    result.push_back(max_i);
    result.push_back(max_j);
    result.push_back(max_size);
    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of rows for the matrix: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    std::cout << "Enter the matrix row by row:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> result = findLargestBlock(matrix);
    std::cout << "The maximum square submatrix is at (" << result[0] << ", " << result[1] << ") with size " << result[2] << std::endl;

    return 0;
}
