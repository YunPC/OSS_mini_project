#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "extras.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
void defragment(Record records[]){
	// TODO: Modify this function as you need
  int i=0, j = 999;
	while(i < j)
  {
    //switch time
    if(records[i].student_num == 0 && records[j].student_num != 0)
    {
      memcpy(&records[i], &records[j], sizeof(Record));
     records[j].student_num = 0;
      i++;
      j--;
    }
    //if i is not empty go to right
    if(records[i].student_num != 0)
      i++;
    //if j is empty go to left
    if(records[j].student_num == 0)
      j--;
  }
	printf("\nfinished\n");	
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[]){
	int fever_count = 0, trip_count = 0;
  for(int i = 0 ; i < 1000; i++)
  {
    if(records[i].isfever == true)
      fever_count++;
    if(records[i].wastriped == true)
      trip_count++;

  }
  printf("\n********************************");
  printf("\nNumber of students who has fever  : %d", fever_count);
  printf("\nNumber of students who has fever  : %d", trip_count);
  printf("\n********************************\n");

}

void swap(Record* xp, Record* yp)
{
  Record temp = *xp; 
    *xp = *yp; 
    *yp = temp;
}

void sort_record(Record records[])
{
  defragment(records);
  int arr[1000];
  int i, j, min_idx, size= 0;
  while(records[size].student_num != 0)
  {
    size++;
  }
  for(i =0; i < size-1; i++)
  {
    min_idx = i;
    for(j = i +1; j < size; j++)
    {
      if(records[j].student_num < records[min_idx].student_num)
        min_idx = j;
    }
    swap(&records[min_idx], &records[i]);
  }

}


// TODO: Add more functions to fulfill the optional requirements
