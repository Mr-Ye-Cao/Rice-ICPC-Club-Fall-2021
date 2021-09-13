/***
 * Sorry I have not finished programming this problem.
 * Please check again this git later 
**/

#include <bits/stdc++.h>
using namespace std;

bool comparePairs(const pair<int,int>& lhs, const pair<int,int>& rhs){
  return lhs.second < rhs.second;
}

void solve(int N,int D,int L,vector<pair<int,int> >& coords,int H){
	vector<pair<int,int> > basvert(4),sec1,sec2;
		
	bool isFirZero=true,isFirH=true;
	for(int i=0;i<N;i++)
		if(coords[i].first==0){
			if(isFirZero){
				basvert[0]=coords[i];
				isFirZero=false;
			}else
				basvert[1]=coords[i];
		}else if(coords[i].second==H){
			if(isFirH){
				basvert[2]=coords[i];
				isFirH=false;
			}else
				basvert[3]=coords[i];
		}
			
	double x1=((double)basvert[0].first+(double)basvert[1].first)/2;
	double y1=(double)0;
	double x2=((double)basvert[2].first+(double)basvert[3].first)/2;
	double y2=(double)H;

	double slope,intrcpt,seperline;
	if(x1!=x2){
		slope=(y1-y2)/(x1-x2);
		intrcpt=y1-slope*x1;
		for(int i=0;i<N;i++)
			if(slope*coords[i].first+intrcpt<coords[i].second)
				sec2.push_back(coords[i]);
			else
				sec1.push_back(coords[i]);
	}else{
		seperline=x1;
		for(int i=0;i<N;i++)
			if(coords[i].first>seperline)
				sec2.push_back(coords[i]);
			else
				sec1.push_back(coords[i]);
	}

	std::sort(sec1.begin(),sec1.end(),comparePairs);
	std::sort(sec2.begin(),sec2.end(),comparePairs);

	int a=0,b=H;
	while(a<=b){
		int mid=(a+b)/2;
		vector<pair<int,int> >::iterator it1=lower_bound(sec1.begin(),sec1.end(),mid);
		vector<pair<int,int> >::iterator it2=lower_bound(sec2.begin(),sec2.end(),mid);
		computeVolume();
	}
}


int main(){
	int N,D,L,H=-1;
	vector<pair<int,int> > coords(N);

	cin>>N>>D>>L;
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		H=max(H,y);
		coords[i] = make_pair(x,y);
	}

	solve(N,D,L,coords,H);

	return 0;
}