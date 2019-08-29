
/*=====================Operating System=========================*/

#pragma once

#include <Configuration.hpp>
#include <PageReplacementAlgorithm.hpp>
#include <vector>

using namespace std;

class LRU_Replacement : public PageReplacementAlgorithm{
public:
  LRU_Replacement();
  int findVictim();
  void updateUsage(int frameNum);

private:
  static vector<int> lruList;

};