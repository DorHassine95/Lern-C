#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
 
int IncluseString(char*,char*);
int isPermutation(char*,char*);
void removeDups(char*);
void minimizeString(char*);
int isPolidromPermutation(char*);
char* charsToRemoveForPolidromPermutation(char*,int*);

int main() {
	char s= "notpolindrom";
	int size = sizeof(s);
	printf("%s",charsToRemoveForPolidromPermutation(&s, &size));
}

///////////////Q1///////////////////
//if the char in string one found in string to,
//no mather about the sort, return 1, else return 0
int IncluseString(char* s1, char* s2) {
	char count[26] = { 0 };
	for (int i = 0; s2[i]; i++) {
		count[s2[i] - 'a']++;
	}
	for (int i = 0; i < s1[i]; i++) {
		count[s1[i] - 'a']--;
		if((count[s1[i]-'a'])<0){
			return 0;
		}
	}
	return 1;
}
////////////////////Q2///////////////////////
//check if the s2 is the permutation of s1 return 1
//else return 0
int isPermutation(char* s1, char* s2) {
	char count[26] = { 0 };
	for (int i = 0; s1[i]; i++) {
		count[s1[i] - 'a']++;
		count[s2[i] - 'a']--;
	}
	for (int i = 0; i<26; i++) {
		if(count[i] != 0 ) {
			return 0;
	}
	}
	return 1;
}
////////////////////////Q3//////////////////////
//remove dubling char in string 
//exp: "aabbbc"---->"abc"
void removeDups(char* S) {
	int i, j;
	for (i = 1, j = 1; S[i]; i++) {
		if (S[i] != S[j - 1]) {
			S[j++] = S[i];
		}
		S[j] = '\0';
		}
	}
///////////////////////Q4//////////////////////
//no double in String and put number of the time doubling 
void minimizeString(char* S) {
		int i, j, count = 1;
		for (i = 0, j = 0; S[i]; i++) {
			if (S[i] != S[i + 1]) {
				S[j++] = S[i];
				if (count > 1) {
					S[j++] = count + '0';
				}
				count = 1;
			}
			else
				count++;
		}
		S[j] = '\0';
	}
///////////////////////Q5/////////////////
//if the string polindrom return 1, else return 0
int isPolidromPermutation(char* S) {
	int i;
	int count[26] = { 0 };
	for (i = 0; S[i]; i++) {
		count[S[i] - 'a']++;
	}
	int counter=0;
	for (int i = 0; i < 26; i++) {
		if ((count[i] % 2) != 0) {
			counter++;
		}
	}
	if (counter > 1) {
		return 0;
	}
	return 1;
}
/////////////////Q6////////////////////
char* charsToRemoveForPolidromPermutation(char* S, int* sizePtr) {
	int counterOdd = 1,counterOne=0,index=0;
	int count[26] = { 0 };
	char* new = (char*)malloc(strlen(S));
	for (int i = 0; S[i]; i++) {
		count[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] == 1) {
			new[index++] = count[i] + 'a';
		}
		if (count[i] >= 3 && ((count[i]%2) != 0) && counterOdd == 1) {
			new[index++] = count[i] + 'a';
			counterOdd++;
		}if ((count[i] % 2) && counterOdd > 1) {
			new[index++] = count[i] + 'a';
		}
	}
	sizePtr = sizeof(new);
	return new;
}