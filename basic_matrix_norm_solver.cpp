//only 2 used . 1 and infinity

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

// Function to read a matrix from a file
std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<int>> matrix;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return matrix;
    }

    std::string line;
    size_t numColumns = 0;
    bool validMatrix = true;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream ss(line);
        int num;

        while (ss >> num) {
            row.push_back(num);
        }

        if (numColumns == 0) {
            numColumns = row.size();
        } else if (row.size() != numColumns) {
            validMatrix = false;
            break;
        }

        matrix.push_back(row);
    }

    if (!validMatrix) {
        std::cerr << "Invalid matrix format: Rows have different number of elements." << std::endl;
        matrix.clear();
    }

    file.close();
    return matrix;
}


long double norm1(const std::vector<std::vector<int>>& matrix) {
    size_t numRows = matrix.size();
    size_t numColumns = matrix[0].size(); // Assuming all rows have the same number of columns

    long double largestSum = 0; // Initialize with a small value, assuming no negative sums

    for (size_t col = 0; col < numColumns; ++col) {
        long double columnSum = 0;
        for (size_t row = 0; row < numRows; ++row) {
            columnSum += matrix[row][col];
        }
        largestSum = std::max(largestSum, columnSum);
    }

    return largestSum;
}

// Function to calculate the sum of each row and find the largest sum
int norm_infinity(const std::vector<std::vector<int>>& matrix) {
    size_t numRows = matrix.size();
    size_t numColumns = matrix[0].size(); // Assuming all rows have the same number of columns

    long double largestSum = 0; // Initialize with a small value, assuming no negative sums

    for (size_t row = 0; row < numRows; ++row) {
        long double rowSum = 0;
        for (size_t col = 0; col < numColumns; ++col) {
            rowSum += matrix[row][col];
        }
        largestSum = std::max(largestSum, rowSum);
    }

    return largestSum;
}


int main() {
    std::string filename = "data.txt"; // Replace with the actual file path

    std::vector<std::vector<int>> matrix = readMatrixFromFile(filename);

        std::cout << "norm1 : " << norm1(matrix) << "\n";
        std::cout << "norm infinity : " << norm_infinity(matrix);

    return 0;
}
