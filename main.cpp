#include <iostream>
#include "stable_matching.h"
#include "utils.h"

int main(){
  std::vector<std::vector<std::string>> data = readNames("names.csv");

  if (data.size() < 2){
    std::cerr << "Invalid CSV format!" << std::endl;
    return EXIT_FAILURE;
  }

  int n = data[0].size(); // Number of men and women
  StableMatching sm(n);

  sm.setNames(data[0], data[1]);

  std::vector<std::vector<int>> menPreferences = readPreferences("preferences_m.csv", n);
  std::vector<std::vector<int>> womenPreferences = readPreferences("preferences_w.csv", n);
  sm.setPreferences(menPreferences, womenPreferences);

  sm.findStableMatch();
  sm.printMatches();

  return EXIT_SUCCESS;
}
