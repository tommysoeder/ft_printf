NAME = libftprintf.a

SRCS = ft_printf.c \
ft_handle_format.c \
ft_handle_string.c \
ft_handle_char.c \
ft_handle_integer.c \
ft_handle_unsigned.c \
ft_handle_hex_lower.c \
ft_handle_hex_upper.c \
ft_hex_utils.c \
ft_handle_pointer.c \
ft_handle_percent.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
