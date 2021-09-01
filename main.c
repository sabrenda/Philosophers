#include "philo.h"

int	death_note(int *omnomnom, t_all *all, int *i)
{
	if (all->time_to_die < (ft_start_time() - all->philos[*i].start_life))
	{
		pthread_mutex_lock(&all->info);
		printf("%llu %d died\n",
			(ft_start_time() - all->philos[*i].start_time), *i + 1);
		return (1);
	}
	if (!all->philos[*i].num_eats)
		*omnomnom = *omnomnom - 1;
	return (0);
}

void	*monitor(void *al)
{
	t_all	*all;
	int i;
	int omnomnom;

	all = (t_all *)al;
	while (1)
	{
		i = 0;
		omnomnom = all->num_philo;
		while (i < all->num_philo)
		{
			if (death_note(&omnomnom, all, &i))
				return (NULL);
			i++;
		}
		if (!omnomnom)
		{
			pthread_mutex_lock(&all->info);
			return (NULL);
		}
	}
	return (NULL);
}

void	*philo(void *pl)
{
	t_philo *philo;

	philo = (t_philo*)pl;
	philo->start_life = ft_start_time();
	while (1)
	{
		take_a_fork(philo);
		ft_eating(philo);
		if (philo->count_philo % 2 == 0)
		{
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(philo->l_fork);
		}
		else
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
		}
		if (philo->num_eats != -1)
			if (philo->num_eats != 0)
				philo->num_eats--;
		go_to_sleep(philo);
	}
	return (NULL);
}

int ft_start(t_all *al)
{
	pthread_t	monik;
	int	i;

	i = 0;
	al->start_time = ft_start_time();
	if (pthread_create(&monik, NULL, monitor, (void *)al))
		return (1);
	while (i < al->num_philo)
	{
		if (pthread_create(&al->philos[i].thread, NULL, philo, (void *)&al->philos[i]))
			return (1);
		i++;
	}
	pthread_join(monik, NULL);
	pthread_mutex_destroy(&al->info);
	return (0);
}

int main(int ac, char **av)
{
	t_all all;
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_exit("bad arguments\n"));
	while (av[i])
	{
		if (check_digit(av[i]) || ft_atoi(av[i]) < 0)
			return (ft_exit("bad arguments\n"));
		i++;
	}
	if (ft_init(ac, av, &all))
		return (ft_exit("error memory\n"));
	else if (ft_start(&all))
	{
		clean_all(&all);
		return (ft_exit("error pthread\n"));
	}
	clean_all(&all);
	return (0);
}
