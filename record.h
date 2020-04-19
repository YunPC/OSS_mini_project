#ifndef _RECORD_H_
#define _RECORD_H_
#include <stdbool.h>
// type defition
typedef struct{
	char name[15];
  int student_num;
  bool isfever;
  bool wastriped;
  char tripped_country[20];

} Record;

#endif
