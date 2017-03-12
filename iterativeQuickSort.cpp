#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int partition(vector<int> &input,int low,int high);

int main(){
	srand(time(NULL));
	int count=rand()%30;
	int high=count-1;
	int low=0;
	vector<int> input;
	stack<int> index;
	for(int i=0;i<count;i++){
		input.push_back(rand()%1000);
	}
	index.push(high);
	index.push(low);
	//for(int i=0;i<count-1;i++){
	//	cout<<input[i]<<" < ";
	//}
	while(!index.empty()){
		low=index.top();
		index.pop();
		high=index.top();
		index.pop();
		int pivot=partition(input,low,high);
		//cout<<"pivot "<<pivot<<"\n";
		if(pivot-1>low){
			index.push(pivot-1);
			index.push(low);
		}
		if(pivot+1<high){
			index.push(high);
			index.push(pivot+1);
		}
		//for(int i=0;i<count-1;i++){
		//	cout<<input[i]<<" < ";
		//}
		//cout<<input[count-1]<<"\n";
	}
	for(int i=0;i<count-1;i++){
		cout<<input[i]<<" < ";
	}
	cout<<input[count-1]<<"\n";
}

int partition(vector<int> &input,int low,int high){
	int pivot=low;
	int backpointer=high;
	for(int i=low+1;i<=high;i++){
		if(input[i]>input[pivot]){
			int temp=input[high];
			input[high]=input[i];
			input[i]=temp;
			high--;
			i--;
		}
	}
	int temp=input[pivot];
	input[pivot]=input[high];
	input[high]=temp;
	pivot=high;
	return pivot;
}