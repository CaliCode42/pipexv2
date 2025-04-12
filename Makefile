NAME = pipex

# Directories
SRC_DIR = src
LIBFT_DIR = libft
OBJ_DIR = obj
INCLUDE_DIR = includes

# Sources
SRC := \
	pipex.c \
	utils.c \

#Path to sources
VPATH = $(SRC_DIR) 

# Objects
OBJ_FILES := $(addprefix $(OBJ_DIR)/$(SRC_DIR)/, $(SRC:.c=.o)) \

# Compilation
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

#Libraries
LIBFT = $(LIBFT_DIR)/libft.a

#Objects directory
OBJDIRS := $(sort $(dir $(OBJ_FILES)))

# Rules
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) -o $(NAME) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: %.c | $(OBJDIRS)
	$(CC) $(CFLAGS) -c $< -o $@

#Create object directory if doesn't exist
$(OBJDIRS):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

debug : CFLAGS += -g
debug : $(NAME)

.PHONY: all clean fclean re debug