#ifndef __MY_H__
# define __MY_H__
//#include <stdio.h>

# define clrscr() my_putstr("\033[H\033[2J")
# define PV_MAX 100
# define PM_MAX 30

typedef struct s_foe
{
	char name[20];
	int nb;
	int pv;
	int pm;
}s_foe;

typedef struct s_hero
{
	char name[20];
	int pv;
	int pm;
	int potion;
	int ether;
}s_hero;

char		*readLine();

void 		init_characters(s_hero *hero, s_foe *foe);
void 		new_foe(s_hero *hero, s_foe *foe);
int 		rand_a_b(int a, int b);

int 		attack(s_hero *caster, s_foe *receiver);
int 		slash(s_hero *caster, s_foe *receiver);
int 		fire(s_hero *caster, s_foe *receiver);
int 		thunder(s_hero *caster, s_foe *receiver);
int			libra(s_hero *caster, s_foe *receiver);

int 		bite(s_foe *caster, s_hero *receiver);
int 		earthquake(s_foe *caster, s_hero *receiver);
int 		doom(s_foe *caster, s_hero *receiver);
int 		stat(s_hero hero);

int 		potion(s_hero *hero);
int 		ether(s_hero *hero);
int 		potion_effect(s_hero *hero);
int 		ether_effect(s_hero *hero);

int 		heal_effect(s_hero *hero);
int 		heal(s_hero *hero);



int 		battle(s_hero *hero, s_foe *foe);
int 		hero_turn(char *output, s_hero *hero, s_foe *foe, int *turn);
int 		hero_turn2(char *output, s_hero *hero, s_foe *foe, int *turn);
int 		foe_turn(s_hero *hero, s_foe *foe, int *turn);

void 		msg_win(s_hero *hero);
void 		msg_lose(s_hero *hero);
void 		msg_crit();



void	my_putchar(char c);
int 	my_isneg(int n);
int 	my_put_nbr(int nb);
int 	my_swap(int *a, int *b);
int 	my_putstr(char *str);
int 	my_strlen(char *str);
int 	my_getnbr(char *str);
void 	my_sort_int_tab(int *tab, int size);
int 	my_power_rec(int nb, int power);
int 	my_square_root(int nb);
int 	my_is_prime(int nombre);
int 	my_find_prime_sup(int nb);
char 	*my_strcpy(char *dest, char *src);
char 	*my_strncpy(char *dest, char *src, int n);
char 	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int 	my_strcmp(char *s1, char *s2);
int 	my_strncmp(char *s1, char *s2, int n);
char 	*my_strupcase(char *str);
char 	*my_strlowcase(char *str);
char 	*my_strcapitalize(char *str);
int 	my_str_isalpha(char *str);
int 	my_str_isnum(char *str);
int 	my_str_islower(char *str);
int 	my_str_isupper(char *str);
int 	my_str_isprintable(char *str);
int 	my_showstr(char *str);
char 	*my_strcat(char *str1, char *str2);
char 	*my_strncat(char *str1, char *str2, int n);
int 	my_strlcat(char *str1, char *str2, int n);

#endif
