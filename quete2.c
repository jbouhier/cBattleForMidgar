#include "my.h"
#include <stdlib.h>

void init_characters(s_hero *hero, s_foe *foe)
{
	hero->pv = 100;
	hero->pm = 30;
	hero->potion = 5;
	hero->ether = 5;

	my_strcpy(foe->name, "Monster");
	foe->nb = rand_a_b(1, 4);
	foe->pv = 75;
	foe->pm = 20;
}

void new_foe(s_hero *hero, s_foe *foe)
{
	foe->nb -= 1;

	if (foe->nb >0)
	{
		foe->pv = 75;
		foe->pm = 20;
		my_putstr("Hero ");
		my_putstr(hero->name);
		my_putstr(" killed a Monster\nA new Monster appear\n");
	}

}

int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}


int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		s_hero hero;
		s_foe foe;

		init_characters(&hero, &foe);
		if ((my_strcmp(argv[1], "-n") == 0))
		{
			my_strcpy(hero.name, argv[2]);
			clrscr();
			battle(&hero, &foe);
		}
		else
			my_putstr("USAGE: <-n> <Player name>\n");
			return (0);
	}
	else
	{
		my_putstr("USAGE: <-n> <Player name>\n");	
	}
	return (0);
}


//			gcc etape1.c battle.c interactions.c interactions2.c msg.c readline.c -L. ./libmy.a
