NAME = get_next_line.a

MY_SOURCES = get_next_line.c\
				get_next_line_utils.c

BONUS_SRCS= get_next_line_bonus.c\
					get_next_line_utils_bonus.c

OBJECTS = $(MY_SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

INCS = get_next_line.h\
		get_next_line_bonus.h

RM = rm -f

# Define the archiver command
LIBC = ar rcs

$(NAME): $(OBJECTS) 
	$(LIBC) $(NAME) $(OBJECTS)

all:$(NAME)

bonus: $(OBJECTS) $(BONUS_OBJECTS) 
	$(LIBC) $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
# Cleaning intermediate files
clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

# Full clean, including the executable
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets (not real files)
.PHONY: all clean fclean bonus re .c .o 

