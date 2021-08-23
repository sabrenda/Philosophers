#include "philo.h"

int ft_check_arg(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (1);
	while (av[i])
	{
		if (ft_atoi(av[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

void ft_init(int ac, char **av, t_all *all)
{
	all->num_philo = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		all->num_eats = ft_atoi(av[5]);
	else
		all->num_eats = -1;
}

void ft_start(int ac, char **av)
{
	t_all all;

	ft_init(ac, av, &all);

}

int main(int ac, char **av)
{
	if (ft_check_arg(ac, av))
		printf("bad arguments\n");
	else
		ft_start(ac, av);
	return (0);
}
