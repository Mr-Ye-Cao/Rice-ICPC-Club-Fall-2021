#include <bits/stdc++.h>

int main(){
	/**
	 * binary search version 1
	 * the procession length is the variable that update
	 **/ 

	int ARR_SIZE = 7;
	bool arr[] = {false,false,false,false,true,true,true};

	// The initial jump length proceed has to be large enough, 
	// for example some value for which we know beforehand 
	// that arr[proceed] is true.

	int x=-1;
	for(int proceed=ARR_SIZE-1;proceed>=1;proceed/=2){
		while(!arr[x+proceed]) x+=proceed;
	}
	if(x+1<ARR_SIZE && arr[x+1]){
		// if there exists true in arr
		// the position is at x+1
		int pos = x+1;
		cout<<pos<<endl;
	}else{
		cout<<"there is no satisfactory value in arr"<<endl;
	}

	/**
	 * ----------------------------------------------------------
	 * binary search version 2
	 * the beginning and endpoint / range got updated
	**/

	int arr2[] = {1,2,3,4,5,6,7,8,9}; 
	int ARR2_SIZE = 9; 

	int a = 0, b = ARR2_SIZE-1,target=8;
	while(a <= b){
		int midpoint = (a+b)/2;
		if(arr2[midpoint]==target){
			// x is found in arr
			cout<<midpoint<<endl;
		}
		if(arr2[midpoint]<target)
			a=midpoint+1;
		else
			b=midpoint-1;
	}

	return 0;
		
}