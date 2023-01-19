#include <connect_four.h>

void	exit_game(void)
{
	int i = -1;

	if (data()->img)
	{
		while (data()->img[++i])
			mlx_destroy_image(data()->mlx, data()->img[i]);
		free(data()->img);
	}
	if (data()->win)
		mlx_destroy_window(data()->mlx, data()->win);
	if (data()->mlx)
	{
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	exit (0);
}