NAME = sphere.c
FLAG = 
EXT = mobaz4/ex06/ft_putnbr.c
all : comp

comp :
	gcc $(FLAG) -I /usr/local/include $(NAME) $(EXT) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean : 
	rm a.out
