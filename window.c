/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:15:44 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/17 13:38:41 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mlx_window (t_data *o)
{
    (void) o;
    void *mlx;
    mlx = mlx_init();
    void *mlx_window;
    mlx_window = mlx_new_window(mlx, 1920, 1280, "window");
    mlx_loop(mlx);
}