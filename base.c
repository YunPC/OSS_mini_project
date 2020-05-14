#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Print all the records.
void print_all_records(Record records[]){
	// TODO: Modify this function as you need
  for(int i = 0; i < 1000; i++)
  {
    if(records[i].student_num == 0)
      continue;
    else
    {
      printf("\n######################################");
      printf("\nStudent name : %s, Student num : %d", records[i].name, records[i].student_num);
      printf("\nhave fever : %s", records[i].isfever ? "yes" : "no");
      printf("\nhave been tripped (within two weeks) : %s", records[i].wastriped ? "yes" : "no");
      printf("\nThe area of student's travles : %s", records[i].tripped_country);
      printf("\nindex %d", i);
      printf("\n######################################\n");
    }
  }
}

void print_search_names_information(Record records[]){
  char name[15];
  int student_num;
  
  int input;
  int inputId;
  printf("choose information\n");
  printf("1. student id, 2. name ");
  scanf("%d",&input);
  
  if(input = 1){
	printf("input id: ");
	scanf("%d",&inputId);
	for(int i=0;i<1000;i++){
            if(records[i].id==inputId){
	    printf("%d %s\n",records[i].id, records[i].name);
		}
	}	
	if(input = 2){
        printf("input name: ");
        scanf("%s",inputName);
        for(int i=0;i<1000;i++){
             if(strcmp(records[i].name,inputName)==0){
             printf("%d %s\n",records[i].id, records[i].name);
                	}
        	}
}
	

// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - add new record with key board
void add_a_record(Record records[]){
	// TODO: Modify this function as you need
  char name[15];
  int student_num;
  char isfever[5];
  char wastriped[5];
  char tripped_country[20];
  int idx = -1;
	printf("Student name : ");
  scanf("%s", name);
  printf("\nStudent number : ");
  scanf("%d", &student_num);
  printf("\nIs a new student have fever? (yes/no) : ");
  scanf("%s", isfever);
  printf("\nIs a new student tripped abroad within two weeks? (yes/no) : ");
  scanf("%s", wastriped);
  

  for(int i = 0; i < 1000; i++)
  {
    if(records[i].student_num == 0)
      idx = i;
  }
  if(idx == -1)
  {
    printf("\nRecord is full please delete any record.\n");
  }
  else
  {
    //student name
    strcpy(records[idx].name, name);
    //student number
    records[idx].student_num = student_num;
    //isfever
    if(!strcmp(isfever, "yes"))
      records[idx].isfever = true;
    else if(!strcmp(isfever, "no"))
      records[idx].isfever = false;
    //wastriped
    if(!strcmp(wastriped, "yes"))
      records[idx].wastriped = true;
    else if(!strcmp(wastriped, "no"))
      records[idx].wastriped = false;
    //tripped_country
    if(!strcmp(wastriped, "no"))
      strcpy(records[idx].tripped_country, "None");
    else if(!strcmp(wastriped, "yes"))
    {
      printf("\nIf a new student tripped abroad write the country (if not just enter)");
      scanf("%s", tripped_country);
      strcpy(records[idx].tripped_country, tripped_country);
    }
      
    
  }
}


// Function: load_datafile
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - overwrite the data
void load_datafile(Record records[])
{
    char str_tmp[1024];
    FILE *pFile = NULL;
    char *p;
    char filename[15];
    char temp[10];
    int idx = 0;
    printf("please write the filename : ");
    scanf("%s", filename);
    pFile = fopen(filename, "r");
    if( pFile != NULL)
    {
      while(!feof(pFile))
      {
        fgets(str_tmp, 1024, pFile);
        int count = 0;
        p = strtok(str_tmp, ",");
        //In one line
        while(p != NULL)
        {
          switch(count){
              case 0 : //name
              strcpy(records[idx].name, p);
              break;
              case 1 : //student_num
              records[idx].student_num = atoi(p);
              break;
              case 2 : //isfever
              if(!strcmp(p, "yes"))
                records[idx].isfever = true;
              else
                records[idx].isfever = false;
              case 3 : //wastriped
              if(!strcmp(p, "yes"))
                records[idx].wastriped = true;
              else
                records[idx].wastriped = false;
              case 4 : // country
              strcpy(records[idx].tripped_country, p);
          }
          count++;
          p = strtok(NULL, ",");
        }
        idx++;
      }
    }
    fclose(pFile);
    for(int i = idx ; i < 1000; i++)
    {
      strcpy(records[i].name, "");
      records[i].student_num = 0;
      strcpy(records[i].tripped_country, "");
    }
    printf("\nload complete!\n");
    
    

    
}

// Function: search_student
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - show students fit with user's specific condition
void search_student(Record records[])
{
  int choice;
  printf("\n##This show who have probability of infection##");
  printf("\nIf you want to see students who have fever put 1");
  printf("\nIf you want to see student who had been trip put 2")
  ;
  printf("\nIf you want to see both put 3")
  ;
  printf("\nchoice : ");
  scanf("%d", &choice);
  int idx;
  //only fever
  if(choice == 1)
  {
    for(int i = 0; i < 1000; i++)
  {
    if(records[i].student_num == 0)
      continue;
    else if(records[i].isfever == true)
    {
      printf("\n######################################");
      printf("\nStudent name : %s, Student num : %d", records[i].name, records[i].student_num);
      printf("\nhave fever : %s", records[i].isfever ? "yes" : "no");
      printf("\nhave been tripped (within two weeks) : %s", records[i].wastriped ? "yes" : "no");
      printf("\nThe area of student's travles : %s", records[i].tripped_country);
      printf("\n######################################\n");
    }
  }
  }
  //only trip
  else if(choice == 2)
  {
    for(int i = 0; i < 1000; i++)
  {
    if(records[i].student_num == 0)
      continue;
    else if(records[i].wastriped == true)
    {
      printf("\n######################################");
      printf("\nStudent name : %s, Student num : %d", records[i].name, records[i].student_num);
      printf("\nhave fever : %s", records[i].isfever ? "yes" : "no");
      printf("\nhave been tripped (within two weeks) : %s", records[i].wastriped ? "yes" : "no");
      printf("\nThe area of student's travles : %s", records[i].tripped_country);
      printf("\n######################################\n");
    }
  }
  }
  //both
  else if(choice == 3)
  {
    for(int i = 0; i < 1000; i++)
  {
    if(records[i].student_num == 0)
      continue;
    else if(records[i].wastriped == true && records[i].isfever == true)
    {
      printf("\n######################################");
      printf("\nStudent name : %s, Student num : %d", records[i].name, records[i].student_num);
      printf("\nhave fever : %s", records[i].isfever ? "yes" : "no");
      printf("\nhave been tripped (within two weeks) : %s", records[i].wastriped ? "yes" : "no");
      printf("\nThe area of student's travles : %s", records[i].tripped_country);
      printf("\n######################################\n");
    }
  }
  }


}

// Function: append_data_from_file
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - append record (not delete)
void append_data_from_file(Record records[])
{
  char str_tmp[1024];
    FILE *pFile = NULL;
    char *p;
    char filename[15];
    char temp[10];
    int idx = -1;
    printf("please write the filename : ");
    scanf("%s", filename);
    pFile = fopen(filename, "r");

    for(int i = 0; i < 1000; i++)
    {
      if(records[i].student_num == 0)
      {
        idx = i;
        break;
      }
    }
    if(idx == -1 || idx > 90)
    {
      printf("There is no space for memory");
    }
    else
    {
      if( pFile != NULL)
    {
      while(!feof(pFile))
      {
        fgets(str_tmp, 1024, pFile);
        int count = 0;
        p = strtok(str_tmp, ",");
        //In one line
        while(p != NULL)
        {
          switch(count){
              case 0 : //name
              strcpy(records[idx].name, p);
              break;
              case 1 : //student_num
              records[idx].student_num = atoi(p);
              break;
              case 2 : //isfever
              if(!strcmp(p, "yes"))
                records[idx].isfever = true;
              else
                records[idx].isfever = false;
              case 3 : //wastriped
              if(!strcmp(p, "yes"))
                records[idx].wastriped = true;
              else
                records[idx].wastriped = false;
              case 4 : // country
              strcpy(records[idx].tripped_country, p);
          }
          count++;
          p = strtok(NULL, ",");
        }
        idx++;
      }
    }
    }
    
    fclose(pFile);
    printf("\nload complete!\n");
}

// Function: export_data_file
// Input: record - array of Records; this may contain empty elements in the middle
// Output: data.txt
// - make data file
void export_data_file(Record records[])
{
  FILE *fp = fopen("data.txt", "w");
  char number[10];
  for(int i = 0; i < 1000; i++)
  {
    if(records[i].student_num == 0)
      continue;
    else
    {
      //name
      fputs(records[i].name, fp);
      fputs(",", fp);
      //student number
      sprintf(number, "%d", records[i].student_num);
      fputs(number, fp);
      fputs(",", fp);
      //isfever
      if(records[i].isfever == true)
        fputs("yes", fp);
      else
        fputs("no", fp);
      fputs(",", fp);
      //wastripped
      if(records[i].wastriped == true)
        fputs("yes", fp);
      else
        fputs("no", fp);
      //area
      fputs(",", fp);
      fputs(records[i].tripped_country, fp);
      fputs("\n", fp);
    }
  }

    fclose(fp);   
  printf("\n check the data file!\n");
}

// Function: export_report_file
// Input: record - array of Records; this may contain empty elements in the middle
// Output: report.txt
// - make report file
void export_report_file(Record records[])
{
  FILE *fp = fopen("report.txt", "w");
  char number[10];
  int count = 1;
  char total[5];
  fputs("Student List\n", fp);
  fputs("------------------------------------------\n", fp);
  for(int i = 0; i < 1000; i++)
  {
    if(records[i].student_num == 0)
      continue;
    else
    { 
      
      //name
      sprintf(total, "%d", count);
      fputs(total, fp);
      fputs("\n", fp);
      fputs("Name : ", fp);
      fputs(records[i].name, fp);
      fputs("\n", fp);
      //student number
      fputs("Student number : ", fp);
      sprintf(number, "%d", records[i].student_num);
      fputs(number, fp);
      fputs("\n", fp);
      //isfever
      fputs("Is he/she have fever? : ", fp);
      if(records[i].isfever == true)
        fputs("yes", fp);
      else
        fputs("no", fp);
      fputs("\n", fp);
      //wastripped
      fputs("Is he/she had been tripped within two weeks? : ", fp);
      if(records[i].wastriped == true)
        fputs("yes", fp);
      else
        fputs("no", fp);
      //area
      fputs("\n", fp);
      fputs("The Country he/she went : ", fp);
      fputs(records[i].tripped_country, fp);
      fputs("\n", fp);
      count++;
    }
  }

    fclose(fp);   
  printf("\n check the report file!\n");
}

void update_detail(Record records[])
{
  int key, index, update_num, new_num;
  int i;
  char new_info [15];
  print_all_records(records);
  printf("\nplease enter student number you want to update : ");
  scanf("%d", &key);
  for(i = 0 ; i < 1000; i++)
  {
    if(records[i].student_num == key)
    {
      printf("\nselect to what information you want to change");
      printf("\n 1. name, 2. student number, 3. fever 4. trip 5. tripped country : ");
      scanf("%d",&update_num);
      switch (update_num)
      {
        case 1:
        printf("\nplease enter new name : ");
        scanf("%s", new_info);
        strcpy(records[i].name, new_info);
        printf("\nupdated!\n");
        break;
        case 2:
        printf("\nplease enter new number : ");
        scanf("%d", &new_num);
        records[i].student_num = new_num;
        printf("\nupdated!\n");
        break;
        case 3:
        printf("\nfever symptom is changed\n");
        records[i].isfever = !records[i].isfever;
        break;
        case 4:
        printf("\ntrip status is changed\n");
        records[i].wastriped = !records[i].wastriped;
        break;
        case 5: 
        printf("\nplease enter country : ");
        scanf("%s", new_info);
        strcpy(records[i].tripped_country, new_info);
        printf("\nupdate fininshed!\n");
      }
    }
  }

}

void delete_student(Record records[])
{
  int key;
  print_all_records(records);
  printf("\nput the student num you want to delete : ");
  scanf("%d", &key);
  for(int i= 0 ; i < 1000; i++)
  {
    if(records[i].student_num == key)
      records[i].student_num = 0;
  }
  printf("\nstudent deleted\n");
  
}
