
/*=====================Operating System=========================*/

#include <LRU_Replacement.hpp>

vector<int> LRU_Replacement::lruList (128);

LRU_Replacement::LRU_Replacement(){
  
  //vector<int> lruList (128);
  
  /*
  for (i=0; i < 128; i++){  //initial lruList with frame nums
    lruList.push_back(i);
  }
  */

}

int LRU_Replacement::findVictim(){
  int ret = lruList.front();
  lruList.erase(lruList.begin());
  return ret;
}

void LRU_Replacement::updateUsage(int frameNum){
  bool inList = false;
  for(int i =0; i < 128; i++){
    if(frameNum == lruList[i]){
      lruList.erase(lruList.begin() + i);
      lruList.push_back(frameNum);
      inList = true;
    }
  }
  if (inList == false){
    lruList.push_back(frameNum);
  }
}

