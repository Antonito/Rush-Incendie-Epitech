##
## Makefile for gfx_incendie in /gfx_incendie
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Dec  4 20:37:46 2015 Antoine Baché
## Last update Tue Dec  8 17:03:29 2015 Antoine Baché
##

SRCFIRE=	src/fire/main.c			\
		src/fire/palette.c		\
		src/fire/display_fire.c		\
		src/fire/music_settings.c	\
		src/fire/fire_calcul.c		\
		src/fire/key_mod.c		\
		src/fire/random_lines.c

SRCPLASMA=	src/plasma/main.c		\
		src/plasma/plasma_calcul.c	\
		src/plasma/display_plasma.c	\
		src/plasma/palette.c

SRCMYEFFECT=	src/my_effect/main.c		\
		src/my_effect/lava/palette.c	\
		src/my_effect/lava/display.c	\
		src/my_effect/lava/calculus.c	\
		src/my_effect/lava/lines.c	\
		src/my_effect/lava/lava.c

SRCROTATION=	src/rotation/main.c		\
		src/rotation/load_colors.c	\
		src/rotation/draw_picture.c	\
		src/rotation/free_elems.c	\
		src/rotation/load_ini.c		\
		src/rotation/my_getnbr.c

HEADER=		-Iinclude

LIB=    	-L/usr/local/lib		\
		-L/home/${USER}/.froot/lib	\
		-llapin				\
		-lsfml-audio			\
		-lsfml-graphics			\
		-lsfml-window			\
		-lsfml-system			\
		-lstdc++ -ldl			\
		-lm

PROJECT=	gfx_incendie

FIRE=		fire

PLASMA=		plasma

MYEFFECT=	my_effect

ROTATION=	rotation

CC=		gcc $(HEADER) -W -Wall -Werror -ansi -pedantic

RM=		rm -f

OBJFIRE=	$(SRCFIRE:.c=.o)

OBJPLASMA=	$(SRCPLASMA:.c=.o)

OBJMYEFFECT=	$(SRCMYEFFECT:.c=.o)

OBJROTATION=	$(SRCROTATION:.c=.o)

$(PROJECT):	$(FIRE) $(PLASMA) $(MYEFFECT) $(ROTATION)

$(FIRE):	$(OBJFIRE)
		$(CC) $(OBJFIRE) -o $(FIRE) $(LIB)

$(PLASMA):	$(OBJPLASMA)
		$(CC) $(OBJPLASMA) -o $(PLASMA) $(LIB)

$(MYEFFECT):	$(OBJMYEFFECT)
		$(CC) $(OBJMYEFFECT) -o $(MYEFFECT) $(LIB)

$(ROTATION):	$(OBJROTATION)
		$(CC) $(OBJROTATION) -o $(ROTATION) $(LIB)

all: 		$(PROJECT)

clean:
		$(RM) $(OBJFIRE) $(OBJPLASMA) $(OBJMYEFFECT) $(OBJROTATION)

fclean: 	clean
		$(RM) $(FIRE) $(PLASMA) $(MYEFFECT) $(ROTATION)

re: 		fclean all

.PHONY: 	all clean fclean re
