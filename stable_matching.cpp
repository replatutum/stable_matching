#include "stable_matching.h"
#include <iostream>

StableMatching::StableMatching(int n){
  this->n = n;

  womenPartners.resize(n, -1);
  engagedMen.resize(n, false);
}

void StableMatching::setPreferences(const std::vector<std::vector<int>> &men, const std::vector<std::vector<int>> &women){
  this->menPreferences = men;
  this->womenPreferences = women;
}

void StableMatching::setNames(const std::vector<std::string>& menNames, const std::vector<std::string>& womenNames){
  this->menNames = menNames;
  this->womenNames = womenNames;
}

bool StableMatching::wPrefersM1OverM(const int w, const int m, const int m1){
  // m1 is current engagement
  // m is proposing man
  for (int i = 0; i < this->n; i++){
    if (this->womenPreferences[w][i] == m1){    // w prefers m1
      return true;
    }
    if (this->womenPreferences[w][i] == m){     // w prefers m
      return false;
    }
  }

  std::cout << "Error in wPrefersM1OverM function" << std::endl;
  return false;
}

void StableMatching::findStableMatch() {
  int freeCount = this->n;

  while (freeCount > 0){
    // Pick first free man
    int man = 0;
    for (; man < this->n; man++){
      if (!engagedMen[man]){
        break;
      }
    }
    
    // loop runs for all the women in the current man's preferences
    // until man is engaged
    for (int i = 0; i < this->n && !engagedMen[man]; i++){
      int woman = this->menPreferences[man][i];

      if (this->womenPartners[woman] == -1){    // woman is free
        this->womenPartners[woman] = man;
        this->engagedMen[man] = true;

        freeCount--;
      }
      else{                                     // woman isn't free
        // find the woman's current fiancee
        int m1 = this->womenPartners[woman];
        
        if (!wPrefersM1OverM(woman, man, m1)){  // new proposal is better for woman
          this->womenPartners[woman] = man;
          this->engagedMen[m1] = false;  // ditched man becomes free
          this->engagedMen[man] = true;
        }
        
        // if the new proposal isn't better, the man is rejected and looks for the next woman
      }
    }
    
  }
  
}

void StableMatching::printMatches() const{
  for (int i = 0; i < n; i++){
    std::cout << womenNames[i] << " ---<3--- " << menNames[womenPartners[i]] << std::endl;
  }
  
}