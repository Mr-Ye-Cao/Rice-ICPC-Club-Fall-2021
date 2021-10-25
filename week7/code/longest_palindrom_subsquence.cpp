#include <bits/stdc++.h>
using namespace std;

void compute(string str){
	int n = str.length();
	int dp[n][n]; //[i,j] inclusive notation
					  // i, j denote the beginning and ending index
					  // where dp[i][j] gives up the length of the longest palindrom
	         		  // starting at i ending at j i.e.     0<=i<n    0<=j<n
	for(int i=0;i<n;i++)
		dp[i][i] = 1;

	for(int le=2;le<=n;le++){
		for(int i=0;i+le-1<n;i++){
			int j=i+le-1;
			if(j-i==1){
				// there is no words in between
				dp[i][j]=str[i]==str[j]?2:1;
			}else if(str[i]==str[j]){
				// could form a new palindrom
				dp[i][j]=dp[i+1][j-1]+2;
			}else{
				// could not form a new palindrom since str[i]!=str[j]
				// remember the dp order is the length of the [i,j]
				// thus here we resort the shorter length ([i][j-1], [i+1][j])
				// is guaranteed to be precomputed already
				dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
			}
		}
	}

	cout<<dp[0][n-1]<<endl; 
}
int main(){
	string str;
	cin>>str;
	compute(str);
	return 0;
}
