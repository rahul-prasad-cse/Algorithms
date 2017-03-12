#include <iostream>

using namespace std;

int main(){
	int count;
	cout<<"Enter the number of elements you want to enter:\n";
	cin>>count;
	int input[count];
	for(int i=0;i<count;i++){
		int temp;
		cin>>temp;
		if(i==0){
			input[0]=temp;
			continue;
		}
		input[i]=temp;
		int j=i;
		while(input[(j-1)/2]<input[j] && (j-1)/2>=0){
			int swapper=input[(j-1)/2];
			input[(j-1)/2]=input[j];
			input[j]=swapper;
			j=(j-1)/2;
		}
	}
	int swapper=input[0];
	input[0]=input[count-1];
	input[count-1]=swapper;
	for(int i=0;i<count-3;i++){
		int j=0;
		while(((input[j]<input[2*j+1] || input[j]<input[2*j+2])) && 2*j+2<=count-i-2){
			if(2*j+2>count-1){
				continue;
			}
			if(input[2*j+1]>input[2*j+2]){
				int swapper=input[2*j+1];
				input[2*j+1]=input[j];
				input[j]=swapper;
				j=2*j+1;
			}
			else if(input[2*j+2]>input[2*j+1]){
				int swapper=input[2*j+2];
				input[2*j+2]=input[j];
				input[j]=swapper;
				j=2*j+2;
			}
		}
		int swapper=input[0];
		input[0]=input[count-i-2];
		input[count-i-2]=swapper;
	}
	swapper=input[0];
	input[0]=input[1];
	input[1]=swapper;
	for(int i=0;i<count;i++){
		if(i==count-1)
			cout<<input[i]<<"\n";
		else
			cout<<input[i]<<" < ";
	}
	return 0;
}