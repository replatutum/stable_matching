#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>> readNames(const std::string &filename){
  std::vector<std::vector<std::string>> data;
  std::ifstream file(filename);
  std::string line;

  while (getline(file, line)){
    std::vector<std::string> row;
    std::stringstream ss(line);
    std::string value;

    while (getline(ss, value, ',')){
      row.push_back(value);
    }
    data.push_back(row);
  }

  return data;
}

std::vector<std::vector<int>> readPreferences(const std::string &filename, int n){
  std::ifstream file(filename);
  std::vector<std::vector<int>> preferences(n, std::vector<int>(n)); // 2D vector to store preferences

  if (!file.is_open()){
    std::cerr << "Error opening file: " << filename << std::endl;
    return preferences;
  }

  std::string line;
  int row = 0;

  while (std::getline(file, line) && row < n){
    std::stringstream ss(line);
    std::string person;
    int col = 0;

    while (std::getline(ss, person, ',')){
      preferences[row][col] = std::stoi(person); // Convert the preference to an integer
      col++;
    }
    row++;
  }

  file.close();
  return preferences;
}
