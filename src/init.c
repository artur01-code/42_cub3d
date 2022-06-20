#include "../incl/cub3d.h"

void	ft_init(t_window *window)
{
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!window->win)
		ft_end_process(ERR_WINDOW_INIT);
	window->img = ft_init_image(window->mlx);
	ft_init_player(window);
}

t_image *ft_init_image(void *mlx)
{
	t_image	*image;

	image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!image)
		ft_end_process(ERR_IMAGE_INIT);
	image->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image->img)
		ft_end_process(ERR_IMAGE_INIT);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp), &(image->line_len), &(image->endian));
	return (image);
}

void	ft_init_player(t_window *window)
{
	window->player = (t_player *)ft_calloc(1, sizeof(t_player));
	printf("123\n");
	window->player->pos = ft_init_vector(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	window->player->dir = ft_init_vector(M_INIT_VECTOR_X, M_INIT_VECTOR_Y);
	window->player->size = 5;
	window->player->color = 0x0058BD55;
}

t_vec	*ft_init_vector (double x, double y)
{
	t_vec *vec;

	vec = ft_calloc(1, sizeof(t_vec));
	vec->x = x;
	vec->y = y;
	return (vec);
}