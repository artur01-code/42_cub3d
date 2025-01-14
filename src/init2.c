#include "../incl/cub3d.h"

void	ft_init_player(t_window *window)
{
	window->player = (t_player *)ft_calloc(1, sizeof(t_player));
	window->player->key = (t_key *)ft_calloc(1, sizeof(t_key));
	window->player->pos = ft_init_vector(0, 0);
	window->player->size = 6;
	window->player->color = 0x0058BD55;
	window->player->key->w = 0;
	window->player->key->a = 0;
	window->player->key->s = 0;
	window->player->key->d = 0;
	window->player->key->a_l = 0;
	window->player->key->a_r = 0;
	window->player->key->a_u = 0;
	window->player->key->a_d = 0;
	window->player->key->e = 0;
	window->player->mouse_x = 0;
	window->player->mouse_hide = 0;
	window->player->speed = M_BASE_SPEED;
}

t_vec	*ft_init_vector(double x, double y)
{
	t_vec	*vec;

	vec = ft_calloc(1, sizeof(t_vec));
	vec->x = x;
	vec->y = y;
	return (vec);
}

t_rc	*ft_init_ray(void)
{
	t_rc	*ray;

	ray = (t_rc *)ft_calloc(1, sizeof(t_rc));
	ray->dir = (t_vec *)ft_calloc(1, sizeof(t_vec));
	ray->side_dist = (t_vec *)ft_calloc(1, sizeof(t_vec));
	ray->map_pos = (t_vec_i *)ft_calloc(1, sizeof(t_vec_i));
	ray->delta_dist = ft_calloc(1, sizeof(t_vec));
	return (ray);
}

void	ft_init_player_dir(t_player *player, char dir)
{
	player->plane.x = 0;
	player->dir = ft_init_vector(0.0, 0.0);
	if (dir == 'N')
	{
		player->dir->y = -1;
		player->plane.x = M_FOV;
		player->plane.y = 0;
	}
	else if (dir == 'E')
	{
		player->dir->x = 1;
		player->plane.y = M_FOV;
	}
	else if (dir == 'S')
	{
		player->dir->y = 1;
		player->plane.x = -1 * M_FOV;
		player->plane.y = 0;
	}
	else if (dir == 'W')
	{
		player->dir->x = -1;
		player->plane.y = -1 * M_FOV;
	}
}
