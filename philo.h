#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h> //for linux
#include <sys/wait.h>  //for linux

struct s_all;

typedef struct		s_philo
{
	unsigned long long int limit;
	unsigned long long int last_eat;
	int				position;
	int				is_eating;
	int				l_fork;
	int				r_fork;
	int				eat_count;
	struct s_all	*all;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}					t_philo;

typedef struct		s_all
{
	int						num_philo;
	unsigned long long int	time_to_die;
	unsigned long long int	time_to_eat;
	unsigned long long int	time_to_sleep;
	int						num_eats;
	unsigned long long int	start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
}					t_all;

#endif
