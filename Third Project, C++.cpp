#include <iostream>
#include <math.h>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

/*
First task: write a program that accepts a natural number, and returns the prime number closest to it, for example
For the input 25 the function will return 23 and for the input 28 the function will return. 29
If there are two numbers that are equally close (from below and above) the function will return the smaller of them) - meaning for the input 9 the function will return 7 and not 11.
*/

bool isprime(int num) // A function to check whether a number is prime or not.
{

	if (num < 2) // Input and condition for the number

	{
		return false;
	}
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;

}
int closeprime(int num) // A function to check which is the closest prime number - from above or below.
{
	if (num < 2) // Input and condition for the number.
	{
		return 2;
	}
	for (int i = 0; i < num; i++)
	{
		if (isprime(num - i) == true)
		{
			return (num - i);
		}
		if (isprime(num + i) == true)
		{
			return (num + i);
		}
	}
}

void get_close_to_prime()

{
	int num; // variable definition
	cout << "Please enter your number:" << endl; // output to receive a variable
	cin >> num; // input to receive a variable
	cout << "the closest prime number to the number you choose is:" << closeprime(num) << endl; // function call

}


/*
Second task:
Write a function that accepts an array and its size and returns true if and only if all elements in the array are different from each other.
bool isDiff(int a[], int size)
 For example: for the array {1,2,3,4,5} the function will return true, for the array {1,2,3,4,2} the function will return false.
*/

bool isDiff(int arr[], int size) // A function to check if the numbers are different in the array
{
	for (int i = 0; i < size; i++)
	{
		for (int k = i + 1; k < size; k++)
		{
			if (arr[k] == arr[i])
			{
				return false;
			}
		}
	}
	return true;
}

void myarrays(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Please enter num " << i << " of array: "; // Setting output to receive numbers for an array
		cin >> a[i]; // receiving an array 
	}
}

void get_is_Diff()

{
	int arr[5]; // Array definition
	int size; // Input to receive array size 
	cout << "Please enter size of array: " << endl; // Output to receive array size
	cin >> size; // Receiving an array size variable
	myarrays(arr, size); // function call
	cout << endl; // profit definition 
	if (isDiff(arr, size) == true)
	{
		cout << "all the numbers in the array is diffrent" << endl;
	}
	else
	{
		cout << "your have some numbers that is the same in the array ";
		cout << endl;
	}

}


/*
Third task: Write a function large_of_average(double a[],int size) double that receives an array of real numbers (double) and its size, the function returns the percentage of elements in the array that are actually larger than the average.
For example: for the array {1,2,3,4,5} a function will return 40%.
*/

double large_of_average(double arr[], int size)

{
	int sum = 0; // Receiving a variable for a sum
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	double avg = double(sum) / double(size); // Defining an average variable using double
	int count = 0; // Receiving a variable for average calculation
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > avg)
		{
			count++;
		}
	}
	return ((double(count) / double(size)) * 100);
}


double myarrays(double a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Please enter num " << i << " of array: "; // Output for receiving numbers
		cin >> a[i]; // Input to receive an array
	}
	return 0;
}

void get_large_of_average()

{
	double arr[5]; // array definition
	int size; // Defining a variable for the size of an array
	cout << "Please enter size of array: " << endl; // Output for array size
	cin >> size; // Output variable to receive array size
	myarrays(arr, size); // First function call 
	cout << endl;
	cout << "the prectenage of numbers bigger than average in the array is " << large_of_average(arr, size) << "%" << endl; // קריאת לפונקציה שנייה
}


/*
Fourth task: write a function that receives an array and its size. An array consisting of only zeros and ones. The function returns the length of the longest sequence of zeros.
For example:
Input: 1,0,0,1,1,0,1,0,0,0,1,0 Output 3
*/

int sub_seq_of_zeros(int a[], int size)
{
	int i; // variable definition 
	int result = 0; // variable definition 
	for (i = 0; i < size; i++)
	{
		int subresult = 0;
		for (int j = i; j < size; j++)
		{
			if (a[j] == 0)
			{
				subresult++;
			}
			else
			{
				break;
			}
		}
		if (subresult > result)
		{
			result = subresult;
		}
	}
	return result;
}
int build_array_random(int a[], int size)
{
	int i; // variable definition
	srand((int)time(0)); // A function that chooses random numbers
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 2; //Picking numbers not randomly between 1-0
	}
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
	return a[i];
}
void get_sub_seq_of_zeros()

{
	int a[20]; // Defining an array variable
	int size; // Setting a variable to receive the size of an array 
	cout << "Please enter size of array up to 20: "; // Output to receive array size
	cin >> size; // Input to receive array size
	build_array_random(a, size); // Call to function 1
	cout << "Longest sequence of zero's is: " << sub_seq_of_zeros(a, size) << endl; // Call to function 2
}

/*
Fifth task: write a function (double arrayStdev(double [] arr, int size
which receives an array of real numbers and its size and returns the standard deviation of the members of the array.
The standard deviation of the members of the array is calculated according to the formula:
For example: if the members of the array are: 1,2,3,4,5 then the standard deviation is √2=1.4142.
*/

double arrayStdev(double a[], int size)
{
	double mean = 0; // Variable definition 1
	double stdev = 0; // Variable definition 2
	for (int i = 0; i < size; i++)
	{
		mean += a[i];
	}
	mean = mean / size; // First action definition
	for (int i = 0; i < size; i++)
	{
		stdev += pow((a[i] - mean), 2);
	}
	stdev = sqrt((1 / (double)size) * (stdev));
	return stdev;
}
void print_array(double a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
}
void build_array(double a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "array[" << i << "]=";
		cin >> a[i];
	}
}
void get_arrayStdev()

{
	double a[10]; // Setting array size
	int size; // Setting a variable to receive the size of an array
	cout << "Please enter a size of Array up to 10: "; // Output to receive array size
	cin >> size; // Input to receive array size
	build_array(a, size); // function call 1
	print_array(a, size); // function call 2
	cout << "The Stdev of this Array is: " << arrayStdev(a, size) << endl; // function call 3
}

int main()

{
	//Opening messages
	cout << "Matala_03 by Ariel Topaz\n\n";
	cout << "Choose opertion from the menu below\n\n";

	int opCod = 0;
	do
	{
		//menu
		cout << endl
			<< "Menu:\n"
			<< "0. for  exit\n"
			<< "1. for print numbers that close to prime\n"
			<< "2. for get Diff\n"
			<< "3. for get large of average\n"
			<< "4. for get sub seq of zeros\n"
			<< "5. for get arraysradev\n"
			<< "Enter your choice:\n";
		cin >> opCod; // Using functions to define the five exercises for convenience and using the menu

		switch (opCod)
		{
		case 1:
			get_close_to_prime();
			break;

		case 2:
			get_is_Diff();
			break;

		case 3:
			get_large_of_average();
			break;

		case 4:
			get_sub_seq_of_zeros();
			break;
		case 5:
			get_arrayStdev();
			break;
		case 0:
			cout << "Exiting The Progtam, have a nice day." << endl << endl << endl << endl;//exit messeg
			break;

		default:
			cout << "Invloid opertion cod" << endl << endl;//eror messeg for invalid input
		}
	} while (opCod != 0);

	return 0;
}


