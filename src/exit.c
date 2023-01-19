#include <connect_four.h>

int	exit_game(void *param)
{
	int i = -1;

	(void)param;
	if (data()->img)
	{
		while (data()->img[++i])
			mlx_destroy_image(data()->mlx, data()->img[i]);
		free(data()->img);
	}
	if (data()->mlx_img)
		mlx_destroy_image(data()->mlx, data()->mlx_img);
	if (data()->piece)
		free(data()->piece);
	if (data()->win)
		mlx_destroy_window(data()->mlx, data()->win);
	if (data()->mlx)
	{
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	exit (0);
	return (0);
}