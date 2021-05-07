#include <vector>
#include<algorithm>
using namespace std;
int solution(vector<int> nums)
{
    int answer = 1, size_v=nums.size()/2;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++) {
        if(nums[i]<nums[i+1]){
            answer++;
        }
    }
    if(size_v<answer){
        answer=size_v;
    }
    return answer;
}
