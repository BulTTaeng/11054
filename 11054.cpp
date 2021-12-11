#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;
vector<int> up;
vector<int> down;
vector<int> up_score;
vector<int> down_score;

void binary_search_up(int num);
void binary_search_down(int num);

int main(){
  int N , input;
  cin >> N;

  for(int i =0; i<N; i++){
    cin >> input;
    list.push_back(input);
  }

  up.push_back(list[0]);
  up_score.push_back(1);

  for(int i =1; i<N; i++){
    if(list[i] > up.back()){
      up.push_back(list[i]);
      
    }
    else{
      binary_search_up(list[i]);
    }

    up_score.push_back(up.size());
  }

  reverse(list.begin(), list.end());
  
  down.push_back(list[0]);
  down_score.push_back(1);

  for(int i =1; i<N; i++){
    if(list[i] > down.back()){
      down.push_back(list[i]);
      
    }
    else{
      binary_search_down(list[i]);
    }

    down_score.push_back(down.size());
  }

  int ans = 0;

  if(up_score[N-1] > down_score[N-1]){
    ans = up_score[N-1];
  }
  else{
    ans = down_score[N-1];
  }

  for(int i =0; i<N; i++){
    if(ans < up_score[i] + down_score[N-i-1]){
      ans = up_score[i] + down_score[N-i-1];
    }
  }

  cout << ans-1;
  return 0;

}

void binary_search_up(int num){
  int start = 0; 
  int end = up.size()-1;
  int mid , loc=1001;
  while(start <= end){
    mid = (start+end)/2;

    if(up[mid] >= num){
      end = mid-1;
      if(loc > mid){
        loc = mid;
      }
    }
    else{
      start = mid +1;
    }
  }

  up[loc] = num;
  
}

void binary_search_down(int num){
  int start = 0; 
  int end = down.size()-1;
  int mid , loc=1001;
  while(start <= end){
    mid = (start+end)/2;

    if(down[mid] >= num){
      end = mid-1;
      if(loc > mid){
        loc = mid;
      }
    }
    else{
      start = mid +1;
    }
  }

  down[loc] = num;
  
}
