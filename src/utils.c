/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:02:15 by hefurrer          #+#    #+#             */
/*   Updated: 2023/06/05 08:04:15 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isgood(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	res = 0;
	i = 0;
	neg = 1;
	while (ft_isgood(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + ((str[i] - '0') * neg);
		i++;
	}
	return (res);
}
