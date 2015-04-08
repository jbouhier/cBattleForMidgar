#include "my.h"

int battle(s_hero *hero, s_foe *foe)
{
	int turn;
	char *output;

	turn = 1;
	do
	{
		if (turn == 1)
		{
			my_putstr("Your turn> ");
			output = readLine();
			hero_turn(output, hero, foe, &turn);
			hero_turn2(output, hero, foe, &turn);
		}
		if (turn == 0)
			foe_turn(hero, foe, &turn);
	}
	while (((hero->pv > 0) && (foe->nb > 0)) && (my_strcmp(output, "quit") != 0));

	if (foe->nb <= 0)
		msg_win(hero);
	if (hero->pv <= 0)
		msg_lose(hero);
	if (my_strcmp(output, "quit") == 0)
		my_putstr("You're leaving the game\n");
	return (0);
}

int hero_turn(char *output, s_hero *hero, s_foe *foe, int *turn)
{
	if (my_strcmp(output, "attack") == 0)
	{
		*turn = attack(hero, foe);
		return (*turn);
	}
	
	if (my_strcmp(output, "slash") == 0)
	{
		*turn = slash(hero, foe);
		return (*turn);
	}
		
	if ((my_strcmp(output, "fire")) == 0)
	{
		*turn = fire(hero, foe);
		return (*turn);
	}
	if ((my_strcmp(output, "thunder")) == 0)
	{
		*turn = thunder(hero, foe);
		return (*turn);
	}
	return (*turn);
}
int hero_turn2(char *output, s_hero *hero, s_foe *foe, int *turn)
{
	if ((my_strcmp(output, "stat")) == 0)
	{
		*turn = stat(*hero);
		return (*turn);
	}
	if ((my_strcmp(output, "libra")) == 0)
	{
		*turn = libra(hero, foe);
		return (*turn);
	}
	if ((my_strcmp(output, "ether")) == 0)
	{
		*turn = ether(hero);
		return (*turn);
	}
	if ((my_strcmp(output, "potion")) == 0)
	{
		*turn = potion(hero);
		return (*turn);
	}
	if ((my_strcmp(output, "heal")) == 0)
	{
		*turn = heal(hero);
		return (*turn);
	}
	return (*turn);
}

int foe_turn(s_hero *hero, s_foe *foe, int *turn)
{
	int nb_atk;

	if (foe->pv <= 0)
	{
		new_foe(hero, foe);
		return (*turn = 1);		
	}
	nb_atk = rand_a_b(1, 4);
	if (nb_atk == 1)
	{
		*turn = bite(foe, hero);
		return (*turn);
	}
	if (nb_atk == 2)
	{
		*turn = earthquake(foe, hero);
		return (*turn);
	}
	if (nb_atk == 3)
	{
		*turn = doom(foe, hero);
		return (*turn);
	}
	return (*turn);
}
