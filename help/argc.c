#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // int usleep(useconds_t usec); 
// #include <mutex>
#include <sys/time.h> // int gettimeofday(struct timeval *tv, struct timezone *tz);
#include <pthread.h>

// argc 
// argv
// ./philo_one 3 410 200 200

// 0 - программа

// 1 - кол-во фил // argv[1]     /// (void *)&num1  -> num1; 2; 3; 4; 5;	
	// pthread_create(&pot1, NULL, waiting, (void *)&num1);
// 2 - время смерти
// 3 - время еды
// 4 - время сна

// N - филосов , N+1 след филосов, N-1 предыдущий

// struct timeval tv1, tv2, dtv;
// struct timezone tz;
// struct t_timeval  
// {
//     time_t      tv_sec;   // —  секунды (хранится целое число секунд) 
//     suseconds_t tv_usec;  // —  дополнительное число микросекунд
// }       s_tim;

int main(int argc, char **argv)
{
    struct timeval my;
    int i;
    int time;

    i = 0;
    time = gettimeofday(&my, NULL);
    printf ("\033[41;30msec\e[0m = |%ld|\n", my.tv_sec);
    printf ("\033[44;30musec\e[0m = |%d|\n", my.tv_usec);

    printf ("\033[43;30mtime\e[0m = |%d|\n", time);

    while (i != 3)
    {
        printf ("\n\033[1;45;36m in process \e[0m\n");
        printf ("\033[0;33m sec\e[0m = |%ld|\n", my.tv_sec);
        printf ("\033[0;34m usec\e[0m = |%d|\n", my.tv_usec);
        printf ("i = \033[32m|%d|\e[0m,", i);
        printf (" \033[2margv\e[0m\e[0m = |%s|\n", argv[i]);
        i++;
    }
    return (0);
}