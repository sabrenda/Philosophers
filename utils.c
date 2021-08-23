#include "philo.h"

int ft_atoi(const char *str)
{
	size_t i;
	unsigned long res;
	int b;

	i = 0;
	res = 0;
	b = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			b = -1;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - '0');
	if (res > 9223372036854775807)
	{
		if (b == 1)
			return (-1);
		return (0);
	}
	return (b * res);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
