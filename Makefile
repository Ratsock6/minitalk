NAMESRV		= server
NAMECLIENT	= client
SRCCLIENT	= src/client.c
SRCSRV		= src/server.c

LIBFT		= libft/libft.a
LDFLAGS		= -Ilibft

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:		$(NAMESRV) $(NAMECLIENT)

$(LIBFT) :
	$(MAKE) -C libft

$(NAMESRV) : $(SRCSRV) $(LIBFT) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
$(NAMECLIENT) : $(SRCCLIENT) $(LIBFT) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
		$(MAKE) clean -C libft

fclean:	clean
		$(RM) $(LIBFT)
		$(RM) $(NAMESRV)
		$(RM) $(NAMECLIENT)

re:			fclean all

.PHONY:		all clean fclean re
