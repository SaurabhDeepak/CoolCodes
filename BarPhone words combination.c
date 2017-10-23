// A program to print all the possible words combination whenever some digits are dialled in a bar phone. E.g.: When 23 is dialled, the
//combination of possible words are: ad, ae, af, bd, be, bf, cd, ce, cf. As 2 corresponds to "abc" and 3 corresponds to "def" on a bar phone.
#include <stdio.h>
#include <string.h>

// hashTable[i] stores all characters that correspond to digit 'i' in phone. e.g.: digit '2' corresponds to characters 'abc'.
//for digit 0 and digit 1, no characters as they do not correspond to any characters.
//the hashTable has a memory of [10][5] because there are 10 numbers(0 to9) and 4 characters maximum for digit 7(pqrs) and digit 9(wxyz).
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// A recursive function to print all possible words. The output words are stored in word[] recursively.
void printWordsUtil(int number[], int currentdigit, char word[], int n)
{
	// printing the word, when a word is created
	int i;
	if (currentdigit == n)
	{
		printf("%s ", word);
		return ;
	}

	// Try all 3 possible characters (4 characters for digit 7 and digit 9) for current digit in number[] and recur the for remaining digits
	for (i=0; i<strlen(hashTable[number[currentdigit]]); i++)
	{
		word[currentdigit] = hashTable[number[currentdigit]][i];
		printWordsUtil(number, currentdigit+1, word, n);
		if (number[currentdigit] == 0 || number[currentdigit] == 1)
			return;
	}
}

//It creates an output array result[] in which words creatd will be stored and calls printWordsUtil()
void printWords(int number[], int n)
{
	char result[n+1];
	result[n] ='\0';
	printWordsUtil(number, 0, result, n);
}

//Main program
int main(void)
{
	int number[10];     //It will contain the 10 digit mobile number given by the user
	printf("Please enter a 10 digit mobile number: \n");
	int i=0;
	for(i=0; i<=9; i++)
	{
	    scanf("%d", &number[i]);
	}
	int n = sizeof(number)/sizeof(number[0]);   //sizeof(number)=40 bytes and sizeof(number[0])=4 bytes. Therefore, n=10
	
  //These print statments are just for testing purpose and has no use in the code, hence commented.
  /*printf("size of number = %lu \n",sizeof(number));//40
	printf("\n size of number[0] = %lu \n",sizeof(number[0]));//4
	printf("\n value of n = %d \n",n);//10 */
	printWords(number, n);
	return 0;
}
