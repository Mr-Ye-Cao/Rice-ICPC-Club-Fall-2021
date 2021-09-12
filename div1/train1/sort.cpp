#include <bits/stdc++.h>

int main(){
   // often time one wants to break a tie
   // it is very useful to construct a pair & sort

   std::vector<pair<int,int> > vec_pair;

   vec_pair.push_back(std::make_pair(1,2));
   vec_pair.push_back(std::make_pair(1,1));

   std::sort(vec_pair.begin(),vec_pair.end());

   cout<<vec_pair[0].first<<" "<<vec_pair[0].second<<endl;
   cout<<vec_pair[1].first<<" "<<vec_pair[1].second<<endl;

   return 0;
}