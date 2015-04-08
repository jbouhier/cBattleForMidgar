#include "my.h"

int attack(s_hero *caster, s_foe *receiver)
{
	int crit;
	int dmg;

	crit = rand_a_b(1, 11);

	my_putstr("Hero ");
	my_putstr(caster->name);
	my_putstr(" use attack\n");
	if (crit == 1)
	{
		msg_crit();
		dmg = (7 * 1.2);
	}
	else
		dmg = 7;
	receiver->pv -= dmg;
	my_putstr(receiver->name);
	my_putstr(" lose \033[31;40m");
	my_put_nbr(dmg);
	my_putstr(" PV\033[0m\n");
	return (0);
}

int slash(s_hero *caster, s_foe *receiver)
{
	int crit;
	int dmg;

	crit = rand_a_b(1, 11);
	my_putstr("Hero ");
	my_putstr(caster->name);
	my_putstr(" use slash\n");
	if (crit == 1)
	{
		msg_crit();
		dmg = (10 * 1.2);
	}
	else
		dmg = 10;
	receiver->pv -= dmg;
	my_putstr(receiver->name);
	my_putstr(" lose \033[31;40m");
	my_put_nbr(dmg);
	my_putstr(" PV\033[0m\n");
	my_putstr(caster->name);
	my_putstr(" lose ");
	my_putstr("\033[31;40m2 PV\033[0m\n\n");
	caster->pv -= 2;
	return (0);
}

int fire(s_hero *caster, s_foe *receiver)
{
	int crit;
	int dmg;
	my_putstr("Hero ");
	my_putstr(caster->name);
	if (caster->pm < 3)
	{
		my_putstr(" can't use fire \033[34;40mMP\033[0m too low\n");
		return (1);
	}
	my_putstr(" use fire\n");
	crit = rand_a_b(1, 11);
	if (crit == 1)
	{
		msg_crit();
		dmg = (10 * 1.2);
	}
	else
		dmg = 10;
	my_putstr(receiver->name);
	receiver->pv -= dmg;
	my_putstr(" lose \033[31;40m");
	my_put_nbr(dmg);
	my_putstr(" PV\033[0m\nHero lose \033[34;40m3 MP\033[0m\n\n");
	caster->pm -= 3;
	return (0);
}

int thunder(s_hero *caster, s_foe *receiver)
{
	int crit;
	int dmg;
	crit = rand_a_b(1, 11);
	my_putstr("Hero ");
	my_putstr(caster->name);
	if (caster->pm < 6)
	{
		my_putstr(" can't use thunder \033[34;40mMP\033[0m too low\n");
		return (1);
	}
	my_putstr(" use thunder\n");
	if (crit == 1)
	{
		msg_crit();
		dmg = (15 * 1.2);
	}
	else
		dmg = 15;
	my_putstr(receiver->name);
	receiver->pv -= dmg;
	my_putstr(" lose \033[31;40m");
	my_put_nbr(dmg);
	my_putstr(" PV\033[0m\nHero lose \033[34;40m5 MP\033[0m\n\n");
	caster->pm -= 5;
	return (0);
}

int	libra(s_hero *caster, s_foe *receiver)
{
	if (caster->pm < 1)
	{
		my_putstr("Hero ");
		my_putstr(caster->name);
		my_putstr(" can't use libra ");
		my_putstr("\033[34;40mMP\033[0m");
		my_putstr(" too low\n");
		return (1);
	}
	my_putstr(receiver->name);
	my_putchar('\n');
	my_putstr("\033[33;40m|--Number : ");
	my_put_nbr((*receiver).nb);
	my_putchar('\n');
	my_putstr("\033[32;40m|--PV : ");
	my_put_nbr((*receiver).pv);
	my_putchar('\n');
	my_putstr("\033[34;40m|--PM : ");
	my_put_nbr((*receiver).pm);
	my_putchar('\n');
	my_putstr("\033[0m");
	return (0);
}
