#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sched.h>
#include<unistd.h>
#include<time.h>

int status;
pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid7,pid8,pid9,pid10,pid11,pid12;
struct sched_param param;

float PROCESS_A(){
  clock_t Start,End;
  Start=clock();
  pid1=fork();
  if(pid1==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid1==0){
    sched_setscheduler(pid1, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(pid1,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_B(){
  clock_t Start,End;
  Start=clock();
  pid5=fork();
  if(pid5==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid5==0){
    sched_setscheduler(pid5, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(pid5,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_C(){
  clock_t Start,End;
  Start=clock();
  pid9=fork();
  if(pid9==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid9==0){
    sched_setscheduler(pid9, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(pid9,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_A_P1(){
  clock_t Start,End;
  Start=clock();
  pid2=fork();
  if(pid2==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid2==0){
    param.sched_priority=1;
    sched_setscheduler(pid2, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(pid2,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_B_P1(){
  clock_t Start,End;
  Start=clock();
  pid6=fork();
  if(pid6==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid6==0){
    param.sched_priority=1;
    sched_setscheduler(pid6, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(pid6,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_C_P1(){
  clock_t Start,End;
  Start=clock();
  pid10=fork();
  if(pid10==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid10==0){
    param.sched_priority=1;
    sched_setscheduler(pid10, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(pid10,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_A_P2(){
  clock_t Start,End;
  Start=clock();
  pid3=fork();
  if(pid3==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid3==0){
    param.sched_priority=2;
    sched_setscheduler(pid3, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(pid3,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_B_P2(){
  clock_t Start,End;
  Start=clock();
  pid7=fork();
  if(pid7==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid7==0){
    param.sched_priority=2;
    sched_setscheduler(pid7, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(pid7,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_C_P2(){
  clock_t Start,End;
  Start=clock();
  pid11=fork();
  if(pid11==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid11==0){
    param.sched_priority=2;
    sched_setscheduler(pid11, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(pid11,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_A_P3(){
  clock_t Start,End;
  Start=clock();
  pid4=fork();
  if(pid4==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid4==0){
    param.sched_priority=3;
    sched_setscheduler(pid4, SCHED_OTHER,&param);
    execlp("make","make",NULL);
  }waitpid(pid4,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_B_P3(){
  clock_t Start,End;
  Start=clock();
  pid8=fork();
  if(pid8==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid8==0){
    param.sched_priority=3;
    sched_setscheduler(pid8, SCHED_RR,&param);
    execlp("make","make",NULL);
  }waitpid(pid8,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

float PROCESS_C_P3(){
  clock_t Start,End;
  Start=clock();
  pid12=fork();
  if(pid12==-1){
    printf("Unable to create Child Process\n");
  }
  else if(pid12==0){
    param.sched_priority=3;
    sched_setscheduler(pid12, SCHED_FIFO,&param);
    execlp("make","make",NULL);
  }waitpid(pid12,&status,0);
  End=clock();
  float total_time=(float)(End-Start);
  return total_time;
}

int main(){
    
  ////////////////////////////////////////////////////////////////////
  float T1=PROCESS_A();
  float T2=PROCESS_A_P1();
  float T3=PROCESS_A_P2();
  float T5=PROCESS_B();
  float T6=PROCESS_B_P1();
  float T7=PROCESS_B_P2();
  float T8=PROCESS_B_P3();
  float T9=PROCESS_C();
  float T10=PROCESS_C_P1();
  float T11=PROCESS_C_P2();
  float T12=PROCESS_C_P3();
  
  printf("\n\nPROCESS-A DEFAULT:");
  for(int i=0;i<T1;i++){
    printf("#");
  }
  printf(" %f\n",T1);

  printf("PROCESS-B DEFAULT:");
  for(int i=0;i<T5;i++){
    printf("#");
  }
  printf(" %f\n",T5);

  printf("PROCESS-C DEFAULT:");
  for(int i=0;i<T9;i++){
    printf("#");
  }
  printf(" %f\n",T9);
  //////////////////////////////////////////////////////////////////////

  printf("PROCESS-A PRIORITY-1:");
  for(int i=0;i<T2;i++){
    printf("#");
  }
  printf(" %f\n",T2);

  printf("PROCESS-B PRIORITY-1:");
  for(int i=0;i<T6;i++){
    printf("#");
  }
  printf(" %f\n",T6);

  printf("PROCESS-C PRIORITY-1:");
  for(int i=0;i<T10;i++){
    printf("#");
  }
  printf(" %f\n",T10);

/////////////////////////////////////////////////////////////////////

  printf("PROCESS-A PRIORITY-2:");
  for(int i=0;i<T3;i++){
    printf("#");
  }
  printf(" %f\n",T3);


  printf("PROCESS-B PRIORITY-2:");
  for(int i=0;i<T7;i++){
    printf("#");
  }
  printf(" %f\n",T7);

  printf("PROCESS-C PRIORITY-2:");
  for(int i=0;i<T11;i++){
    printf("#");
  }
  printf(" %f\n",T11);


//////////////////////////////////////////////////////////////////////

  float T4=PROCESS_A_P3();
  printf("PROCESS-A PRIORITY-3:");
  for(int i=0;i<T4;i++){
    printf("#");
  }
  printf(" %f\n",T4);


  printf("PROCESS-B PRIORITY-3:");
  for(int i=0;i<T8;i++){
    printf("#");
  }
  printf(" %f\n",T8);
  

  printf("PROCESS-C PRIORITY-3:");
  for(int i=0;i<T12;i++){
    printf("#");
  }
  printf(" %f\n",T12);
  //////////////////////////////////////////////////////////////////////
  return 0;
}