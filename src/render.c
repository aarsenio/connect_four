#include <connect_four.h>

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

void	draw_piece(int x, int y, t_img *img)
{
	int				i = -1;
	int				j = -1;


	while (++j < PIECE_RES)
	{
		i = -1;
		while (++i < PIECE_RES)
			mlx_draw_pixel(data()->mlx_img, x + i, y + j, mlx_get_pixel(img, i, j));
	}
}

void	draw_all_pieces(void)
{
	int				i = -1;
	int				j = -1;

	while (++j < 6)
	{
		i = -1;
		while (++i < 7)
		{
			if (data()->board[j][i] == RED)
				draw_piece(i * PIECE_RES, (j * PIECE_RES) + 128, data()->img[RED]);
			else if (data()->board[j][i] == YELLOW)
				draw_piece(i * PIECE_RES, (j * PIECE_RES) + 128, data()->img[YELLOW]);
		}
	}
}

void	draw_white(void)
{
	int				i = -1;
	int				j = -1;

	while (++j < WINDOW_RES)
	{
		i = -1;
		while (++i < WINDOW_RES)
			mlx_draw_pixel(data()->mlx_img, i, j, 0xFFFFFF);
	}
}

void	draw_board(void)
{
	unsigned int	color;
	int				i = -1;
	int				j = -1;

	while (++j < BOARD_HEIGHT)
	{
		i = -1;
		while (++i < WINDOW_RES)
		{
			color = mlx_get_pixel(data()->img[0], i, j);
			if (color != mlx_rgb_to_int(0, 215, 0, 255))
				mlx_draw_pixel(data()->mlx_img, i, j + 128, color);
		}
	}
}

void	image_load(void)
{
	int	height = BOARD_HEIGHT;
	int width = WINDOW_RES;
	int res = PIECE_RES;

	data()->mlx_img = mlx_new_image(data()->mlx, WINDOW_RES, WINDOW_RES);
	data()->img = malloc(sizeof(t_img *) * 5);
	if (!data()->img)
		return ;
	data()->img[0] = mlx_xpm_file_to_image(data()->mlx, "images/board.xpm", &height, &width);
	data()->img[1] = mlx_xpm_file_to_image(data()->mlx, "images/red.xpm", &res, &res);
	data()->img[2] = mlx_xpm_file_to_image(data()->mlx, "images/yellow.xpm", &res, &res);
	data()->img[3] = NULL;
	new_piece();
}

void	board_render(void)
{
	draw_white();
	draw_all_pieces();
	if (data()->piece)
	{
		draw_piece(data()->piece->x * PIECE_RES, data()->piece->start_y, data()->img[data()->turn]);
		if (data()->piece->is_free)
		{
			data()->piece->start_y += 15.9f;
			if ((int)(data()->piece->start_y) >= data()->piece->end_y){
			move(data()->piece->x);
			free(data()->piece);
			new_piece();
			}
		}
	}
	draw_board();
	mlx_put_image_to_window(data()->mlx, data()->win, data()->mlx_img, 0, 0);
}
