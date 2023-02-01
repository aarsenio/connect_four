#include <connect_four.h>

void	new_piece(void)
{
	data()->piece = malloc(sizeof(t_obj));
	if (!data()->piece)
		return ;
	data()->piece->x = -1;
	data()->piece->is_free = 0;
}

void	move(int x)
{
	if (x >= 0 && x < 7)
	{
		data()->board[data()->piece->end_y][x] = data()->turn;
		if (data()->turn == RED)
			data()->turn = YELLOW;
		else
			data()->turn = RED;
	}
}

int	mouse(int event, void *param)
{
	int i = 6;

	(void) param;
	if (event != 1 || !data()->piece ||(data()->piece && data()->piece->is_free))
		return (0);
	if (data()->piece)
	{
		if (data()->piece->x >= 0 && data()->piece->x < 7  && data()->board[0][data()->piece->x] == 0)
		{
			data()->piece->is_free = 1;
			while (--i >= 0)
				if (data()->board[i][data()->piece->x] == 0)
					break ;
			data()->piece->end_y = i;
		}
	}
	return (0);
}