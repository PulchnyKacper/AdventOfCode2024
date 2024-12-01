#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map> 

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

    std::unordered_map<int, int> frequencyFirst;
    std::unordered_map<int, int> frequencySecond;

    for (int num : firstColumn){
        frequencyFirst[num]++;
    }
    for (int num : secondColumn){
        frequencySecond[num]++;
    }
    
    int sum = 0;
    for (const auto& pair : frequencyFirst){

        if (frequencySecond.find(pair.first) != frequencySecond.end()){
            sum += pair.first * pair.second * frequencySecond[pair.first];
        }
    }
    std::cout<<sum<<std::endl;
    return 0;
}