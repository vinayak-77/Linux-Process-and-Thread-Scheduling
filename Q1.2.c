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

int main(int argc,char * argv[]){
    struct timespec start,stop;
    int pid1 = fork();
    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
      perror( "clock gettime" );
      exit( EXIT_FAILURE );
    }
    if(pid1==0){
        execl("ty1.sh",NULL);
        
    }
    else{
        wait(NULL);
        if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
            perror( "clock gettime" );
            exit( EXIT_FAILURE );
        }

        double B_Time = ( stop.tv_sec - start.tv_sec )
            + (double)( stop.tv_nsec - start.tv_nsec)/ (double)1000000000L;
        
        printf("\n");
        printf( "%lf\n", B_Time );
        printf("\n");
        

    }


    int pid2 = fork();
    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
      perror( "clock gettime" );
      exit( EXIT_FAILURE );
    }
    if(pid2==0){
        execl("./ty1.sh",NULL);
    }
    else{
        
        wait(NULL);
        if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
            perror( "clock gettime" );
            exit( EXIT_FAILURE );
        }

        double B_Time = ( stop.tv_sec - start.tv_sec )
            + (double)( stop.tv_nsec - start.tv_nsec)/ (double)1000000000L;
        printf("\n");
        printf( "%lf\n", B_Time );
        printf("\n");

    }


    int pid3 = fork();
    if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
      perror( "clock gettime" );
      exit( EXIT_FAILURE );
    }
    if(pid3==0){
        execl("./ty1.sh",NULL);
    }
    else{
        wait(NULL);
        if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
            perror( "clock gettime" );
            exit( EXIT_FAILURE );
        }

        double B_Time = ( stop.tv_sec - start.tv_sec )
            + (double)( stop.tv_nsec - start.tv_nsec)/ (double)1000000000L;
        printf("\n");
        printf( "%lf\n", B_Time );
        printf("\n");

    }
    return 0;
}