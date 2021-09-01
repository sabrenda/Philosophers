#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct		s_philo
{
	int						count_philo;
	int						num_eats;
	unsigned long long int	time_to_die;
	unsigned long long int	time_to_eat;
	unsigned long long int	time_to_sleep;
	unsigned long long int start_time;
	unsigned long long int start_life;
	pthread_t	thread;
	pthread_mutex_t				*l_fork;
	pthread_mutex_t				*r_fork;
	pthread_mutex_t				*info;
}					t_philo;

typedef struct		s_all
{
	int						num_philo;
	int						num_eats;
	unsigned long long int	time_to_die;
	unsigned long long int	time_to_eat;
	unsigned long long int	time_to_sleep;
	unsigned long long int	start_time;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	info;
	t_philo			*philos;
}					t_all;

int ft_strlen(char *str);
int ft_atoi(const char *str);
int ft_init(int ac, char **av, t_all *all);
void init_phil(t_all *all);
int	check_digit(char *arg);
int ft_start(t_all *al);
void	*philo(void *pl);
void	*monitor(void *al);
int	death_note(int *omnomnom, t_all *all, int *i);
unsigned long long int	ft_start_time(void);
void	go_to_sleep(t_philo *philo);
void	ft_eating(t_philo *philo);
void	take_a_fork(t_philo *philo);
void	my_usleep(long long int time);
int	ft_exit(char *str);
void clean_all(t_all *all);

#endif
