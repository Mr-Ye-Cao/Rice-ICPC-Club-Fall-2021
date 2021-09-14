/***
 *  Solution Credit to Charlie Liu
 *  from Rice ICPC club
 *  comments added by Peter
 * **/

#include<bits/stdc++.h>

using namespace std;

int n,d,l;
vector<pair<double,double>> L;
vector<pair<double,double>> R;

double find_vol(double h){
    // since we divided the points into two sections
    double Larea=0,Rarea=0;
    // calculate the trapezoid of left sections
    for(int i=0;i<L.size();i++){
        if(h<L[i+1].second){
            double dh=h-L[i].second;
            double r=dh/(L[i+1].second-L[i].second);
            Larea+=0.5*dh*((2-r)*L[i].first+r*L[i+1].first);
            break;
        }else{
            Larea+=0.5*(L[i].first+L[i+1].first)*(L[i+1].second-L[i].second);
        }
    }
    // calculate the trapezoid of right sections
    for(int i=0;i<R.size();i++){
        if(h<R[i+1].second){
            double dh=h-R[i].second;
            double r=dh/(R[i+1].second-R[i].second);
            Rarea+=0.5*dh*((2-r)*R[i].first+r*R[i+1].first);
            break;
        }else{
            Rarea+=0.5*(R[i].first+R[i+1].first)*(R[i+1].second-R[i].second);
        }
    }
    // the area is the difference of the trapezoid
    return (Rarea-Larea)*d;
}

int main()
{   
    // use a list for constant time insertion and deletion at front and back
    list<pair<int,int>> vtx;
    cin>>n>>d>>l;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        // read input points into list
        vtx.push_back(make_pair(x,y));
    }
    while(true){
        // since the input points are given in counterclockwise order
        // this loop terminates when front and back of list
        // are points (x1,0) and (x2,0)
        if(vtx.front().second==0&&vtx.back().second==0){
            break;
        }else{
            vtx.push_back(vtx.front());
            vtx.pop_front();
        }
    }

    for(int i=0;i<n;i++){
        pair<int,int> temp=vtx.front();
        vtx.pop_front();
        // keep pushing points into the Right section
        R.push_back(temp);
        // the point of break between section1 and section2 happens
        // when (x3,y1) (x4,y1)
        if(vtx.front().second==temp.second)
            break;
    }
    // the rest of the points belong to the Left section
    while(!vtx.empty()){
        L.push_back(vtx.back());
        vtx.pop_back();
    }
    
    // next we shift all of the points rightwards 1001 units
    // this way we are able to calculate the trapezoid area
    for(int i=0;i<L.size();i++)
        L[i].first+=1001;
    for(int i=0;i<R.size();i++)
        R[i].first+=1001;

    // start a binary search with active region (0,height of the aquarium tank)
    double lo=0;
    double hi=R.back().second;
    // given the constraints at most 50 updates (very possibly less) are needed
    // to find the exact point of height
    for(int i=0;i<50;i++){
        double mid=(lo+hi)/2;
        if(find_vol(mid)>l*1000) hi=mid;
        else lo=mid;
    }
    // print out the height with 2 decimal places
    printf("%.2f", (lo+hi)/2);
    return 0;
}