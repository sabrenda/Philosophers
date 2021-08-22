#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h> //for linux
#include <sys/wait.h>  //for linux

typedef struct s_philo
{
	int num_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_eats;
} t_philo;

#endif
