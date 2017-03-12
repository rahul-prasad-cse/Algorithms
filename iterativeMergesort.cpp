#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

void merge(vector<int> &input,int beg,int end,int count,int basesize);

int main(){

	vector<int> input;
	srand(time(NULL));
	//cout<<"Enter the elements(press -1 to stop entering new elements):\n";
	//int temp;
	//cin>>temp;
	//while(temp!=-1){
	//	input.push_back(temp);
	//	cin>>temp;
	//}
	//int count=input.size();
	int count=rand()%20;
	for(int i=0;i<count;i++){
		input.push_back(rand()%1000);
	}
	int basesize=1;
	while(basesize<=count-1){
		int beg=0;
		int flag=0;
		int end=min((beg+basesize*2-1),count-1);
		int iterator=(count)/(basesize*2)+1;
		for(int i=0;i<iterator;i++){
			end=min((beg+basesize*2-1),count-1);
			merge(input,beg,end,count,basesize);
			beg=min(end+1,count-1);
		}
		basesize*=2;
	}
	//int beg=0;
	//int end=1;
	//while(count%end<count){
	//	end=2*end;
	//}
	//merge(input,0,end-2,count,basesize);
	for(int i=0;i<count-1;i++){
		cout<<input[i]<<" < ";
	}
	cout<<input[count-1]<<"\n";
}

void merge(vector<int> &input,int beg,int end,int count,int basesize){
	//for(int i=0;i<count-1;i++){
	//	cout<<input[i]<<" < ";
	//}
	//cout<<input[count-1]<<"\n";
	
	vector<int> left;
	vector<int> right;
	//int mid=floor((beg+end)/2);
	int mid=beg+basesize-1;
	//cout<<"mid "<<mid<<"\n";
	for(int i=beg;i<=mid;i++){
		left.push_back(input[i]);
	}
	for(int i=mid+1;i<=min(end,count-1);i++){
		right.push_back(input[i]);
	}
	//cout<<"Left: ";
	//for(int i=0;i<left.size();i++)
	//	cout<<left[i]<<" ";
	//cout<<"\nRight: ";
	//for(int i=0;i<right.size();i++)
	//	cout<<right[i]<<" ";
	//cout<<"\n";
	int length=end-beg+1;
	int leftpointer=beg;
	int rightpointer=mid+1;
	int inputpointer=beg;
	int leftflag=0,rightflag=0;
	while(leftpointer<=mid && rightpointer<=min(end,count-1)){
		int min;
		if(left[leftpointer-beg]<right[rightpointer-mid-1]){
			input[inputpointer]=left[leftpointer-beg];
			inputpointer++;
			leftpointer++;
			if(leftpointer>mid){
				leftflag=1; //left array completely used
			}
		}
		else {
			input[inputpointer]=right[rightpointer-mid-1];
			rightpointer++;
			inputpointer++;
			if(rightpointer>end || rightpointer > count-1){
				rightflag=1;//right array completely used
			}
		}
	}
	if(leftflag==1){
		while(rightpointer<=end && rightpointer <= count-1){
			input[inputpointer]=right[rightpointer-mid-1];
			rightpointer++;
			inputpointer++;
		}
	}
	if(rightflag==1){
		while(leftpointer<=mid){
			input[inputpointer]=left[leftpointer-beg];
			inputpointer++;
			leftpointer++;
		}
	}
}