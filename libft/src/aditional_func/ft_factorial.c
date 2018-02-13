/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:20:58 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/29 13:21:00 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int nb)
{
	int pr;

	pr = 1;
	if (nb > 0 && nb < 13)
	{
		while (nb > 1)
		{
			pr *= nb;
			nb--;
		}
	}
	else
		pr = 0;
	if (nb == 0)
		pr = 1;
	return (pr);
}
