#ifndef STABLE_MATCHING_H
#define STABLE_MATCHING_H

#include <vector>
#include <string>

class StableMatching{
public:
  StableMatching(int n);
  void setPreferences(const std::vector<std::vector<int>> &men, const std::vector<std::vector<int>> &women);
  void setNames(const std::vector<std::string> &menNames, const std::vector<std::string> &womenNames);
  bool wPrefersM1OverM(const int w, const int m, const int m1);
  void findStableMatch();
  void printMatches() const;

private:
  int n;
  std::vector<std::vector<int>> menPreferences;
  std::vector<std::vector<int>> womenPreferences;
  std::vector<int> womenPartners;
  std::vector<bool> engagedMen;
  std::vector<std::string> menNames;
  std::vector<std::string> womenNames;
};

#endif
