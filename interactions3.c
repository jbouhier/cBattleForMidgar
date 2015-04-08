#include "my.h"

int potion(s_hero *hero)
{
	int value;

	if (hero->potion > 0)
	{
		value = potion_effect(hero);
		my_putstr("Hero ");
		my_putstr(hero->name);
		my_putstr(" use \033[31;40mPotion\033[0m\n");
		my_putstr("Hero ");
		my_putstr(hero->name);
		my_putstr(" gain \033[31;40m");
		my_put_nbr(value);
		my_putstr(" PV\033[0m\n");
		my_putstr("hero lose \033[31;40m1 Potion\033[0m\n\n");
		return(0);
	}
	else
	{
		my_putstr("Hero ");
		my_putstr(hero->name);
		my_putstr(" doesn't have any ");
		my_putstr("");
		my_putstr("\033[31;40mpotion\n\n\033[0m");
	}
	return (1);
}

int ether(s_hero *hero)
{
	int value;

	if (hero->ether > 0)
	{
		value = ether_effect(hero);
		my_putstr("Hero ");
		my_putstr(hero->name);
		my_putstr(" use \033[34;40mEther\033[0m\n");
		my_putstr("Hero ");
		my_putstr(hero->name);
		my_putstr(" gain \033[34;40m");
		my_put_nbr(value);
		my_putstr(" PM\033[0m\n");
		my_putstr("hero lose \033[34;40m1 Ether\033[0m\n\n");
		return(0);
	}
	else
	{
		my_putstr("Hero ");
		my_putstr(hero->name);
		my_putstr(" doesn't have any ");
		my_putstr("");
		my_putstr("\033[34;40mether\n\n\033[0m");
	}
	return (1);	
}

int potion_effect(s_hero *hero)
{
	int value;

	value = 0;

	hero->potion -= 1;
	value = 100 - hero->pv;
	if (value < 30)
	{
		hero->pv += value;
		return (value);	
	}
	else
	{
		hero->pv += 30;
		return (30);
	}
	return (value);
}

int ether_effect(s_hero *hero)
{
	int value;

	value = 0;
	hero->ether -= 1;
	value = 30 - hero->pm;
	if (value < 12)
	{
		hero->pm += value;
		return (value);
	}
	else
	{
		hero->pm += 12;
		return (12);
	}
	return (value);
}
