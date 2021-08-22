#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // int usleep(useconds_t usec); 
#include <sys/time.h> // int gettimeofday(struct timeval *tv, struct timezone *tz);
#include <pthread.h>


#define N 5
// 5 philo

int main()
{
	int	l_fork;
	int	r_fork;
// думаю
// кушаю
// голодаю
// сплю
	int	ph[N] = {1, 2, 3, 4, 5};
// думаю пока не станет доступна вилка ->  беру ее , жду освобождения следующей
// когда взяла 2 вилки, кушаю определенное время
// опустила одну вилку, потому другую
// рипииит

    return (0);
}