/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:13:00 by hefurrer          #+#    #+#             */
/*   Updated: 2023/06/05 08:13:02 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_args	args;

	args = get_args(av, ac);
	printf("%d\n", args.nop);
	return (0);
}
