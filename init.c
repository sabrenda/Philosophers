#include "philo.h"

void init_phil(t_all *all)
{
	int	i;

	i = -1;
	all->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all->num_philo);
	while (++i < all->num_philo)
		pthread_mutex_init(&all->m_forks[i], NULL);
	pthread_mutex_init(&all->info, NULL);
	i = 0;
	while (i < all->num_philo)
	{
		all->philos[i].count_philo = i;
		all->philos[i].info = &all->info;
		all->philos[i].l_fork = &all->m_forks[i];
		all->philos[i].r_fork = &all->m_forks[(i + 1) % all->num_philo];
		all->philos[i].time_to_die = all->time_to_die;
		all->philos[i].time_to_eat = all->time_to_eat;
		all->philos[i].time_to_sleep = all->time_to_sleep;
		all->philos[i].num_eats = all->num_eats;
		all->philos[i].start_time = all->start_time;
		all->philos[i].start_life = all->start_time;
		i++;
	}
}

int ft_init(int ac, char **av, t_all *all)
{
	all->num_philo = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		all->num_eats = ft_atoi(av[5]);
	else
		all->num_eats = -1;
	all->philos = (t_philo *)malloc(sizeof(*(all->philos)) * all->num_philo);
	if (!all->philos)
		return (1);
	all->start_time = ft_start_time();
	init_phil(all);
	return (0);
}
