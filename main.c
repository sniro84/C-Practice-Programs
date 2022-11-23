#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define N 6
#define FALSE 0
#define TRUE 1

int findMin(int a[], int length); // 1. finds minimum in array
int findMax(int a[], int length); // 2. finds maximum in array
int countOccurrences(int a[] , int length, int x); // 3. returns the number of times x appears in the array
void reverseArray(int a[], int length);  // 4. reverses an array
void printArray(int a[], int length); //5. prints an array
bool isPalindrom(char s[]); //6. check if string is a palindrom
int sumArray(int a[], int length); //7. returns the sum of elements in array
double average(double a[], int length); //8. returns the average of an array
int fibo(int n); //9. returns the nth term in the fibonaci series
int countVowels(char s[]); // 10. returns the number of vowels in a string
char* appendString(char s1[], char s2[]);  // 11. appends s2 to s1 and returns the new string
int* arrayCopy(int a[], int length); // 12. creates and returns a copy of an array
double* vectorAddition(double v1[], double v2[], int len); // 13. returns the sum of 2 vectors
double dotProduct(double v1[], double v2[], int len); // 14. returns the dot product of 2 vectors
int wordCount(char* subStr, char* s); // 15. returns the number of times a substring appears in a string
void removeChar(char s[], char c); // 16. removes all occourence of a character from a string
void printReverseRec(char s[]); // 17. print the string in reverse with recursion
int binToDec(char bin[]); //18. returns a decimal representation of a binary number



int main()
{

    //double b[] = {6.6,8,9.42};
    //printf("%.2lf", average(b,3));
    //char s1[] = "Snir";
    //char s2[] = "Holland";
    char b[] = "1";
    printf("%d", binToDec(b));
    return 0;
}

// 1. finds minimum in array
int findMin(int a[], int length)
{
    int i;
    int min = a[0];
    for(i=1; i<length; i++)
        if (a[i]<min)
            min = a[i];
    return min;
}

// 2. finds maximum in array
int findMax(int a[], int length)
{
    int i;
    int max = a[0];
    for(i=1; i<length; i++)
        if (a[i]>max)
            max = a[i];
    return max;
}

// 3. returns the number of times x appears in the array
int countOccurrences(int a[] , int length, int x)
{
    int i , count=0;
    for(i=0; i<length; i++)
        if(a[i] == x)
            count++;
    return count;
}

// 4. reverses an array
void reverseArray(int a[], int length)
{
    int i, temp;
    for(i=0; i<length/2; i++)
    {   //swap values
        temp = a[i];
        a[i] = a[length-i-1];
        a[length-i-1] = temp;
    }

}

//5. prints an array
void printArray(int a[], int length)
{
    int i;
    for(i=0; i<length; i++)
        printf("%d ", a[i]);
    printf("\nDone printing array.\n");
}

//6. check if string is a palindrom
bool isPalindrom(char s[])
{
    int i ,len, mid;
    len = strlen(s);
    mid = len/2;

    for(i=0; i<mid; i++)
        if(s[i] != s[len-i-1])
            return false;
    return true;
}

//7. returns the sum of elements in array
int sumArray(int a[], int length)
{
    int i, res = 0;
    for(i=0; i<length; i++)
        res += a[i];
    return res;
}

//8. returns the average of an array
double average(double a[], int length)
{
    int i;
    double avg , sum = 0;
    for(i=0; i<length; i++)
        sum += a[i];
    avg = sum / length;
    return avg;
}

//9. returns the nth term in the fibonaci series
int fibo(int n)
{
    if(n==0 || n==1)
        return n;
    return fibo(n-1) + fibo(n-2);
}

// 10. returns the number of vowels in a string
int countVowels(char s[])
{
    int i, count = 0;
    for(i=0; i<strlen(s); i++)
    {
        switch(tolower(s[i])) // tolower taken from <ctype.h>
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
    }
    return count;
}

// 11. appends s2 to s1 and returns the new string
char* appendString(char s1[], char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int destLen = len1 + len2 + 1;  // "+1" for the null terminator
    char* dest = (char*)malloc(destLen * sizeof(char));

    int i,j;
    for(i=0; i<len1; i++)      // first we fill chars from s1
        dest[i] = s1[i];
    for(j=0; j<len2; i++,j++)  // now we fill chars from s2
        dest[i] = s2[j];
    dest[i] = '\0';
    return dest;
}

// 12. creates and returns a copy of an array
int* arrayCopy(int src[], int length)
{
    int* destArr = (int*)malloc(length*sizeof(int));
    int i;
    for(i=0; i<length; i++)
        destArr[i] = src[i];
    return destArr;
}

// 13. returns the sum of 2 vectors
double* vectorAddition(double v1[], double v2[], int len)
{
    double* result = (double*)malloc(len* sizeof(double));
    int i;
    for(i=0; i<len; i++)
        result[i] = v1[i] + v2[i];
    return result;
}

// 14. returns the dot product of 2 vectors
double dotProduct(double v1[], double v2[], int len)
{
    double result = 0;
    int i;
    for(i=0; i<len; i++)
        result += v1[i]*v2[i];
    return result;
}

// 15. returns the number of times a substring appears in a string
int wordCount(char* subStr, char* s)
{
    int i, count = 0;
    for(i=0; i<strlen(s); i++)
    {
        if (s[i] == subStr[0])
        {
            int j;
            for(j=0; j<strlen(subStr); j++)
                if (s[i+j] != subStr[j])
                    break;
            if (j == strlen(subStr)) // a substring has been found
                count++;
        }
    }
    return count;
}

// 16. removes all occourence of a character from a string
void removeChar(char s[], char c)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if (s[i] == c)
        {
            int j=i;
            while (s[j] != '\0')
            {
                s[j] = s[j+1];   // shifting the entire substring to the left one unit
                j++;
            }
        }
        else
            i++;
    }
}

// 17. print the string in reverse with recursion
void printReverseRec(char* s)
{
    if (*s!= '\0')
    {
        printReverseRec(s+1);
        printf("%c", *s);
    }
}

//18. returns a decimal representation of a binary number
int binToDec(char bin[])
{
    int i, res = 0 , factor = 1;
    int last = strlen(bin)-1; // last char position in the string
    for(i=last; i>=0; i--)
    {
        if (bin[i] == '1')
            res += factor;
        factor *= 2;
    }
    return res;
}

