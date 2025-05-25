#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <conio.h>

void dayAndDate(time_t current_time, struct tm *tm);
void tweleveHourTime(time_t current_time, struct tm *tm);
void twentyfourHourTime(time_t current_time, struct tm *tm);
void wait_seconds();

int main(){
  time_t current_time;
  struct tm *tm;
  
  while (1) {
    int choice;
    system("cls");
    printf("~- Digital Clock -~\n\n");
    printf("1. 12 hour format(default choice)\n");
    printf("2. 24 hour format\n");
    printf("3. Exit\n");
    printf("Enter your choice(1/2/3): ");
    scanf("%d", &choice);

    if(choice == 3){
      exit(0);
    }

    printf("\n");

    printf("For going to main menu press [3]\n");
    dayAndDate(current_time, tm);
    switch(choice){
      case 1:
        tweleveHourTime(current_time, tm);
        break;
      case 2:
        twentyfourHourTime(current_time, tm);
        break;
      default:
        tweleveHourTime(current_time, tm);
        break;
    }
  }

  return 0;
}

void dayAndDate(time_t current_time, struct tm *tm){
  char dayAndDate_Buffer[50];
  current_time = time(NULL);
  tm = localtime(&current_time);

  strftime(dayAndDate_Buffer, sizeof(dayAndDate_Buffer), "%A, %B %d, %Y", tm);
  printf("Date: %s\n", dayAndDate_Buffer);
}

void tweleveHourTime(time_t current_time, struct tm *tm){
  char timeBuffer[12];

  while (1) {
    current_time = time(NULL);
    tm = localtime(&current_time);

    strftime(timeBuffer, sizeof(timeBuffer), "%I:%M:%S %p", tm);
    printf("\rThe time is: %s ", timeBuffer);
    fflush(stdout);

    wait_seconds();
    
    //not cross platform
    if(_kbhit()){
      char ch = _getch();
      if(ch == '3'){
        break;
      }
    }
  }
  

}

void twentyfourHourTime(time_t current_time, struct tm *tm){
  char timeBuffer[12];

  while (1) {
    current_time = time(NULL);
    tm = localtime(&current_time);

    strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S %p", tm);
    printf("\rThe time is: %s ", timeBuffer);
    fflush(stdout);
    
    wait_seconds();
    
    //not cross platform
    if(_kbhit()){
      char ch = _getch();
      if(ch == '3'){
        break;
      }
    }
  }
}

void wait_seconds(){
  #ifdef _WIN32
    Sleep(1000);
  #else
    sleep(1);
  #endif
}


