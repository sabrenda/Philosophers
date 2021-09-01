#include "philo.h"

void	take_a_fork(t_philo *philo)
{
	if (philo->count_philo % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->info);
	printf("%llu %d has taken a fork\n",
		ft_start_time() - philo->start_time, philo->count_philo + 1);
	pthread_mutex_unlock(philo->info);
	if (philo->count_philo % 2 == 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->info);
	printf("%llu %d has taken a fork\n",
		ft_start_time() - philo->start_time, philo->count_philo + 1);
	pthread_mutex_unlock(philo->info);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->info);
	printf("%llu %d is eating\n",
		ft_start_time() - philo->start_time, philo->count_philo + 1);
	philo->start_life = ft_start_time();
	pthread_mutex_unlock(philo->info);
	my_usleep(philo->time_to_eat);
}

void	go_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->info);
	printf("%llu %d is sleeping\n",
		ft_start_time() - philo->start_time, philo->count_philo + 1);
	pthread_mutex_unlock(philo->info);
	my_usleep(philo->time_to_sleep);
	pthread_mutex_lock(philo->info);
	printf("%llu %d is thinking\n",
		ft_start_time() - philo->start_time, philo->count_philo + 1);
	pthread_mutex_unlock(philo->info);
}

void	my_usleep(long long int time)
{
	struct timeval	t1;
	long long int		timing;

	gettimeofday(&t1, NULL);
	timing = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	while (time > (t1.tv_sec * 1000 + t1.tv_usec / 1000) - timing)
	{
		gettimeofday(&t1, NULL);
		usleep(100);
	}
}

void clean_all(t_all *all)
{
	int	i;

	if (all->m_forks)
	{
		i = 0;
		while (i < all->num_philo)
			pthread_mutex_destroy(&all->m_forks[i++]);
		free (all->m_forks);
	}
	if (all->philos)
		free (all->philos);
}
