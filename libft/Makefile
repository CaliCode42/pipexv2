NAME = libft.a

# Directories
SRC_DIR = src
B_DIR = bonus_src
FT_PRINTF_DIR = ft_printf
GNL_DIR = gnl
INCLUDES = includes
OBJ_DIR = objects

# Sources
SRC_FILES := \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_str_threejoin.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strsep.c \
	ft_strcspn.c \

# Bonus Sources
B_SRC := \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

# Sources ft_printf
PRINTF_FILES := \
	ft_atoi_base.c \
	ft_check_precision.c \
	ft_check_width.c \
	ft_convert_nb.c \
	ft_fill_withzero.c \
	ft_itoa_base.c \
	ft_parse_format.c \
	ft_present.c \
	ft_printf.c \
	ft_putformat.c \
	ft_putstr.c \
	ft_render_format.c \
	ft_strcpy.c \
	ft_strlen_int.c \
	print_type.c \
	ft_free.c \
	ft_pickstr.c \

GNL_FILES := \
	get_next_line_utils.c \
	get_next_line.c \

#Path for sources
VPATH = $(SRC_DIR) $(B_DIR) $(FT_PRINTF_DIR) $(GNL_DIR)

# Object files
OBJ_FILES = $(addprefix $(OBJ_DIR)/$(SRC_DIR)/, $(SRC_FILES:.c=.o)) \
			$(addprefix $(OBJ_DIR)/$(FT_PRINTF_DIR)/, $(PRINTF_FILES:.c=.o)) \
			$(addprefix $(OBJ_DIR)/$(GNL_DIR)/, $(GNL_FILES:.c=.o)) \
			$(addprefix $(OBJ_DIR)/$(B_DIR)/, $(B_SRC:.c=.o))

# Compilation
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

#Object directory
OBJDIRS := $(sort $(dir $(OBJ_FILES)))

# Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# Compilation
$(OBJ_DIR)/%.o: %.c | $(OBJDIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJDIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
