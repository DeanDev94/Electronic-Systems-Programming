/*	Name:	Dean Devereaux
Class:	EELX2
Date:	4rd December 2015
Program Description:

A GPS sends a string in the following format
$GPGLL,4916.45,N,12311.12,W,225444,A,*1D

Where:
GLL          =Geographic position, Latitude and Longitude
4916.46,N    =Latitude 49 deg. 16.45 min. North
12311.12,W   =Longitude 123 deg. 11.12 min. West
225444       =Fix taken at 22:54:44 UTC
A            =Data Active or V (void)
*iD          =checksum data
The checksum field consists of a '*' and two hex digits representing an 8 bit exclusive OR of all characters between, but not including, the '$' and '*'.
Design a C program that indicates if the longitude/latitude data is valid.
The data is valid if the DATA ACTIVE flag is A (V means void) and the calculated checksum matches the one at the end of the string.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void main()
{
	char GPSstring[41],checksum = 0, ch, sum,buf[5],cmpstring[5];
	int firstdigitindex = 0, lastdigitindex = 0, loopcount = 1, loop;
	puts("\t\t\tCHECKSUM COMPARER\n");//Heading of programme
	printf("\nEnter a GPS coorodinates in string format '$string*checksum'\n");//Enter GPS coorodinates
	scanf("%s", GPSstring);//read in value entered
	getch();

	while (GPSstring[loopcount] != '*')//Get a checksum by XORing the string, stop the loop before the checksum entered
	{
		ch = GPSstring[loopcount];
		printf("\ncharacter %c has ascii code %d which is %x in hex\n", ch, ch, ch);
		checksum = checksum ^ ch;// XOR the checksum with the next character entered
		printf("\nchecksum = %x\n", checksum);
		loopcount++;//increment to next character
	}
	sprintf(buf, "%x", checksum);// convert final checksum result into string format
	printf("\nFinal Checksum = %s\n", buf);//Display calculated checksum in string form

	while (GPSstring[firstdigitindex++] != '*');//Find the first digit of the typed checksum from GPS coordinates
	lastdigitindex = firstdigitindex;//Allow the last digit to start scanning where first digit stopped  
	firstdigitindex = firstdigitindex;
	while (GPSstring[lastdigitindex++] != '\0');//Find last digit of typed
	lastdigitindex = lastdigitindex - 2;
	for (loop = 0; firstdigitindex <= lastdigitindex; loopcount++, firstdigitindex++)
		cmpstring[loop++] = GPSstring[firstdigitindex];//Extract checksum, first digit to last digit

	cmpstring[loop] = '\0';//This cancels an end for extracted checksum 
	printf("\nChecksum typed = %s\n", cmpstring);//Display extracted checksum
	
		if (strcmp(buf, strlwr(cmpstring)) == 0)//compare the two strings and make extracted checksum lower case for correct answer
		{
			printf("\nData Valid\n");//Displays if Data is Correct
		}
		else
		{
			printf("\nData Invalid\n");//Dislay if Data is Correct
		}
	getch();
}
