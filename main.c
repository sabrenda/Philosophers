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

void ft_start(int ac, char **av)
{

}

int main(int ac, char **av)
{
	if (ft_check_arg(ac, av))
		printf("bad arguments\n");
	else
		ft_start(ac, av);
	return (0);
}
