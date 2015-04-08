#include "my.h"

int heal_effect(s_hero *hero)
{
	int value;

	value = 0;
	value = PV_MAX - hero->pv;
	if (value < (PV_MAX * 0.25))
	{
		value = PV_MAX - hero->pv;
		return (value);
	}
	else
	{
		hero->pv += (PV_MAX * 0.25);
		return (PV_MAX * 0.25);
	}
	return (0);
}

int heal(s_hero *hero)
{
	int value;
	int crit;
	int heal_value;

	value = 0;
	my_putstr("Hero ");
	my_putstr(hero->name);
	if (hero->pm < 3)
	{
		my_putstr(" can't use heal \033[34;40mMP\033[0m too low\n");
		return (1);
	}
	else
	{
		value = heal_effect(hero);
		crit = rand_a_b(1, 11);
		if (crit == 1)
		{
			my_putstr("\033[31;40mCritical Heal!\033[0m\n");
			heal_value = (value * 1.2);
		}
		else
			heal_value = value;
		hero->pv += heal_value;
		my_putstr(" use \033[31;40mHeal\033[0m\nHero ");
		my_putstr(hero->name);
		my_putstr(" gain \033[31;40m");
		my_put_nbr(heal_value);
		my_putstr(" PV\033[0m\nHero lose \033[34;40m3 PM\033[0m\n\n");
	}
	return (0);
}