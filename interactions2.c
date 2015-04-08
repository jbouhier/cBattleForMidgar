#include "my.h"

int bite(s_foe *caster, s_hero *receiver)
{
	int crit;
	int dmg;

	crit = rand_a_b(1, 11);


	my_putstr("\n");
	my_putstr(caster->name);
	my_putstr(" use bite\n");
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
	my_putstr(" PV\033[0m\n\n");
	return (1);
}

int earthquake(s_foe *caster, s_hero *receiver)
{
	int crit;
	int dmg;

	crit = rand_a_b(1, 11);

	my_putstr("\n");
	my_putstr(caster->name);
	my_putstr(" use earthquake\n");
	if (crit == 1)
	{
		msg_crit();
		dmg = (15 * 1.2);
	}
	else
		dmg = 15;
	receiver->pv -= dmg;
	my_putstr(receiver->name);
	my_putstr(" lose \033[31;40m");
	my_put_nbr(dmg);
	my_putstr(" PV\033[0m\n");
	my_putstr(caster->name);
	my_putstr(" lose ");
	my_putstr("\033[31;40m3 PV\033[0m\n\n");
	caster->pv -= 3;
	return (1);
}

int doom(s_foe *caster, s_hero *receiver)
{
	int crit;
	int dmg;

	crit = rand_a_b(1, 11);
	my_putstr("\n");
	my_putstr(caster->name);
	my_putstr(" use doom\n");
	if (crit == 1)
	{
		msg_crit();
		dmg = (15 * 1.2);
	}
	else
		dmg = 15;
	receiver->pv -= dmg;
	my_putstr(receiver->name);
	my_putstr(" lose \033[31;40m");
	my_put_nbr(dmg);
	my_putstr(" PV\033[0m\n");
	my_putstr(caster->name);
	my_putstr(" lose ");
	my_putstr("\033[34;40m5 PM\033[0m\n\n");
	caster->pm -= 5;
	return (1);
}

int	stat(s_hero hero)
{
	my_putstr("Hero : ");
	my_putstr(hero.name);
	my_putchar('\n');

	my_putstr("\033[32;40m|--PV : ");
	my_put_nbr(hero.pv);

	my_putchar('\n');

	my_putstr("\033[34;40m|--PM : ");
	my_put_nbr(hero.pm);
	my_putchar('\n');

	my_putstr("\033[36;40m|--Ether : ");
	my_put_nbr(hero.ether);
	my_putchar('\n');
	my_putstr("\033[31;40m|--Potion : ");
	my_put_nbr(hero.potion);
	my_putchar('\n');
	my_putchar('\n');
	my_putstr("\033[0m");
	return (1);
}
