#ifndef CONNECT_FOUR_H
# define CONNECT_FOUR_H

# include <mlx.h>
# include <mlx_int.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define BOARD_HEIGHT 768
# define WINDOW_RES 896
# define PIECE_RES 128

enum s_types
{
	RED = 1,
	YELLOW
};

typedef struct s_obj
{
	int		x;
	double	start_y;
	int	end_y;
	int		is_free;
}t_obj;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		turn;
	int		board[6][7];
	t_img	**img;
	t_img	*mlx_img;
	t_obj	*piece;
}t_data;

t_data *data(void);
void	image_load(void);
void	board_render(void);
int		mouse(int event, void *param);
void	move(int x);
void	new_piece(void);
void	exit_game(void);
void	set_position_piece(int x);

#endif