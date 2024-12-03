#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

bool isAscending(const std::vector<int>& vec){
    for (int i = 1; i < vec.size(); ++i){
        if (vec[i] <= vec[i - 1]){
            return false;
        }
    }
    return true;
}

bool isDescending(const std::vector<int>& vec){
    for (int i = 1; i < vec.size(); ++i){
        if (vec[i] >= vec[i - 1]){
            return false;
        }
    }
    return true;
}

bool isDifferenceWithinLimit(const std::vector<int>& vec, int limit){
    for (int i = 1; i < vec.size(); ++i){
        if (std::abs(vec[i] - vec[i - 1]) > limit){
            return false;
        }
    }
    return true;
}

int main(int, char**){

    std::string path = "../../input.txt";

    std::ifstream inputFile(path);

    if (!inputFile.is_open()){
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int lineCount = 0;
    std::string line;

    while (std::getline(inputFile, line)){
        lineCount++;
    }
    inputFile.close();

    inputFile.open(path);
    if (!inputFile.is_open()){
        std::cerr << "Error reopening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> data;

    data.reserve(lineCount);

     while (std::getline(inputFile, line)){
        std::vector<int> row;
        std::stringstream ss(line);
        int number;

        while (ss >> number){
            row.push_back(number);
        }

        data.push_back(row);
    }

    inputFile.close();


    int safeCount = 0;

    for (const auto& row : data){

        if (isDifferenceWithinLimit(row, 3) && (isAscending(row) || isDescending(row))){
            safeCount++;
        }
    }
    std::cout<<safeCount<<std::endl;

    return 0;
}
