SRCS = pipex.c  utils3.c  utils2.c  utils.c  utils4.c utils5.c

SRCS_B = get_next_line_bonus.c  get_next_line_utils_bonus.c  pipex_bonus.c  \
		utils2_bonus.c  utils3_bonus.c  utils4_bonus.c  utils5_bonus.c  utils_bonus.c

RM	= rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJF_B = $(SRCS_B:.c=.o)
OBJF = $(SRCS:.c=.o)
NAME = pipex

RESET		=	'\033[0m'
GREEN		=	'\033[32m'
GRAY		=	'\033[2;37m'
ITALIC		=	'\033[3m'

.c.o 	:
			@echo $(ITALIC)$(GREEN) "     - Compiling the file /$<..." $(RESET)
			@$(CC) $(CFLAGS) -c $< -o $@

all  :$(NAME)

bonus	: $(OBJF_B)
			@echo $(ITALIC)$(GRAY) "     - creating the executable file $(NAME) ..." $(RESET)
			@$(CC) $(CFLAGS) $(OBJF_B) -o $(NAME)

$(NAME) : $(OBJF)
			@echo $(ITALIC)$(GRAY) "     - creating the executable file $(NAME) ..." $(RESET)
			@$(CC) $(CFLAGS) $(OBJF) -o $(NAME)

clean	: 
			@echo $(ITALIC)$(GRAY) "     - deleting the object files..." $(RESET)
			@$(RM) $(OBJF) $(OBJF_B)

fclean	: clean
			@echo $(ITALIC)$(GRAY) "     - deleting the executable files..." $(RESET)
			@$(RM) $(NAME) $(NAME_B)

re		: fclean all

.PHONY	: all clean fclean re bonus 
.SECONDARY: