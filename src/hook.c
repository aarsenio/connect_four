#include <connect_four.h>

void	new_piece(void)
{
	data()->piece = malloc(sizeof(t_obj));
	if (!data()->piece)
		return ;
	data()->piece->is_free = 0;
}

void	set_position_piece(int x)
{
	int i = 6;

	data()->piece->x = x;	
	while (--i >= 0)
		if (data()->board[i][x] == 0)
			break ;
	data()->piece->end_y = (i * PIECE_RES) + 128;
}


void	move(int x)
{
	int i = 6;
	while (--i >= 0)
	{
		if (data()->board[i][x] == 0)
		{
			data()->board[i][x] = data()->turn;
			break ;
		}
	}
	if (data()->turn == RED)
		data()->turn = YELLOW;
	else
		data()->turn = RED;
}

int	mouse(int event, void *param)
{

	(void) param;
	if (event != 1 || (data()->piece && data()->piece->is_free))
		return (0);
	if (data()->piece)
	{
		if (data()->board[0][data()->piece->x] == 0)
			data()->piece->is_free = 1;
	}
	return (0);
}