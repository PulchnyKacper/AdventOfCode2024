#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm> 

int main(int, char**){

    std::string path = "../../input.txt";

    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    int lineCount = 0;
    std::string line;

    while (std::getline(inputFile, line)) {
        lineCount++;
    }
    inputFile.close();

    inputFile.open(path);
    if (!inputFile.is_open()) {
        std::cerr << "Error reopening file!" << std::endl;
        return 1;
    }

    std::vector<int> firstColumn;
    std::vector<int> secondColumn;

    firstColumn.reserve(lineCount);
    secondColumn.reserve(lineCount);

    while (std::getline(inputFile, line)){
        std::stringstream ss(line);
        int firstValue, secondValue;

        if (ss >> firstValue >> secondValue){
            firstColumn.emplace_back(firstValue);
            secondColumn.emplace_back(secondValue);
        }
    }
    inputFile.close();

    std::sort(firstColumn.begin(), firstColumn.end());
    std::sort(secondColumn.begin(), secondColumn.end());

    int sum = 0;
    for (int i = 0; i < firstColumn.size(); ++i){

        sum += abs(firstColumn[i] - secondColumn[i]);
    }

    std::cout<<sum<<std::endl;

    return 0;
}
