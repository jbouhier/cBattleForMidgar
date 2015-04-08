#include "my.h"

void msg_win(s_hero *hero)
{
	my_putstr("Hero ");
	my_putstr(hero->name);
	my_putstr(" defeated the monsters\nCongratulation, You Won !!\n");
}

void msg_lose(s_hero *hero)
{
	my_putstr("Hero ");
	my_putstr(hero->name);
	my_putstr(" is dead\nYou lost\n");
}

void msg_crit()
{
	my_putstr("\033[31;40mCritical Hit!\033[0m\n");
}