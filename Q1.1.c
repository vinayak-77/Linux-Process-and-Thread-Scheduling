#include <bits/types/struct_sched_param.h>
#define _GNU_SOURCE
#include <bits/time.h>

#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sched.h>
#include <sys/types.h>
#include <sys/types.h>
#include<unistd.h>
#include <math.h>
#include<sys/syscall.h>
#include<time.h>
#include<sys/wait.h>

struct sched_param param;

void * countA(){
    struct sched_param param;
    long long int count = 1;
    long long int target = pow(2,32);
    while(count<=target){
        count++;
    }
}

void * countB(){
    struct sched_param param;
    long long int count = 1;
    long long int target = pow(2,32);
    while(count<=target){
        count++;
    }
}

void * countC(){
    struct sched_param param;
    long long int count = 1;
    long long int target = pow(2,32);
    while(count<=target){
        count++;
    }
}


int main(int argc,char * argv[]){
    pthread_t thrA,thrB,thrC;
    struct timespec start1,start2,start3,end1,end2,end3;
    FILE *ptr;
    ptr = fopen("timing.txt", "a");
    
    int i = 15;

    if( clock_gettime( CLOCK_REALTIME, &start1) == -1 ) {
      perror( "clock gettime" );
      exit( EXIT_FAILURE );
    }

    pthread_create(&thrA, NULL, countA, NULL);

    pthread_setschedparam(thrA, SCHED_OTHER,&param);


    if( clock_gettime( CLOCK_REALTIME, &start2) == -1 ) {
      perror( "clock gettime" );
      exit( EXIT_FAILURE );
    }
    
    pthread_create(&thrB, NULL, countB, NULL);

    pthread_setschedparam(thrB, SCHED_RR, &param);

    pthread_setschedprio(thrB, i);


    if( clock_gettime( CLOCK_REALTIME, &start3) == -1 ) {
      perror( "clock gettime" );
      exit( EXIT_FAILURE );
    }
    pthread_create(&thrC, NULL, countC, NULL);


    pthread_setschedparam(thrC, SCHED_FIFO,&param);

    pthread_setschedprio(thrC, i);

    
    pthread_join(thrA, NULL);
    if( clock_gettime( CLOCK_REALTIME, &end1) == -1 ) {
            perror( "clock gettime" );
            exit( EXIT_FAILURE );
        }

    double A_Time = ( end1.tv_sec - start1.tv_sec )
        + (double)( end1.tv_nsec - start1.tv_nsec)/ (double)1000000000L;
    
    printf( "%lf\n", A_Time );
        


    pthread_join(thrB, NULL);

    if( clock_gettime( CLOCK_REALTIME, &end2) == -1 ) {
            perror( "clock gettime" );
            exit( EXIT_FAILURE );
        }

    double B_Time = ( end2.tv_sec - start2.tv_sec )
        + (double)( end2.tv_nsec - start2.tv_nsec)/ (double)1000000000L;
    
    printf( "%lf\n", B_Time );


    pthread_join(thrC, NULL);

    if( clock_gettime( CLOCK_REALTIME, &end3) == -1 ) {
            perror( "clock gettime" );
            exit( EXIT_FAILURE );
        }

    double C_Time = ( end3.tv_sec - start3.tv_sec )
        + (double)( end3.tv_nsec - start3.tv_nsec)/ (double)1000000000L;
    
    printf( "%lf\n", C_Time );

    
    fprintf(ptr, "%d ",i);
    fprintf(ptr, "%f ",A_Time);
    fprintf(ptr, "%f ",B_Time);
    fprintf(ptr, "%f\n\n",C_Time);
    fclose(ptr);

    return 0;
}