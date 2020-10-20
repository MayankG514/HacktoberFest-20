#include <iostream>
using namespace std;

int main(){
	// Get char line input
	int maxNumberInput = 1000;
	char a[maxNumberInput];
	cin.getline(a,maxNumberInput);
	
	//Convert char array into integer array
	int number[maxNumberInput] = {0};
	int arrlen = 0;
	int i = 0;
	while(a[i] != '\0'){
		if(a[i] != ' '){number[arrlen] = a[i] - '0'; arrlen++;} // ASCII number digits start from 48, so we need to minus it by 48
	i++;
	}
	//Count amount of number input
	int arr1[10] = {0};
	for(int i=0; i<arrlen; i++){
		arr1[number[i]] += 1;
	}
	
	//Modify array by adding the previous counts
	 for(int i=1; i<10; i++){
		arr1[i] += arr1[i-1];
	}
	
	//Ascending array
	int ascendingArr[arrlen] = {0};
	for(int i=0; i<arrlen; i++){
		int index = arr1[number[i]];
		ascendingArr[index] = number[i];
		arr1[number[i]] -= 1;
	}
	
	//Print output
	for(int i=1; i<=arrlen; i++){
		cout << ascendingArr[i];
	} 
	
}
