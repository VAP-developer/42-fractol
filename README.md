# 42-fractol
Project basic of graphics with miniLibX. We will draw a fractal.

# Basic functions:
1. open -> int open(const char *path, int flags, mode_t mode);
```
Description: Open a File.
path: path of the file.
flags: Options to open the file.
mode (optional): for example we use it if we need permisions or other.
Return: Success -> file descriptor / Error -> -1.
```

2. close -> int close(int fd)
```
Description: Close a file.
fd: file descriptor.
Return: Success -> 0 / Error -> -1.
```
    
3. read -> ssize_t read(int fd, void *buf, size_t count);
```
Description: Read a file descriptor
fd: file desciptor (open).
buf: pointer of memory.
count: number of bytes to read.
Return: Success -> Numbers of bytes readed. (0 is the end od the file) / Error -> -1
```

4. write -> ssize_t write(int fd, cons void *buf, size_t count);
```
Description: Write buf in file descriptor
fd: file descriptor (open)
buf: pointer of memory
count: numbers of bytes
Return: Success -> numners of bytes writed / Error -> -1
```

5. malloc -> void* malloc(size_t size)
```
Description: Allocate memory
size: Number of bytes allocated
Return: Success -> void Pointer / Error -> NULL
```
   
6. free -> void free(void *ptr);
```
Description: Free memory
ptr: Pointer to free
Return: Nothing
```
  
7. perror -> void perror(cons char *s)
```
Description: Print an error message
s: error message
Return: Nothing
```
  
8. strerror -> char* strerror(int errnum)
```
Description: Error description
errnum: error code
Return: string
```

9. exit -> void exit(int stauts)
```
Description: Terminate the execution of a program
status: 0 (success) / other (error)
Return: Nothing
```
# STEP 1: My first window
Para este paso necesitare crear una estructura de ficheros, un compilador Makefile y un main.c

La estructura de los ficheros será la siguiente:
```
📂 Fractol
├── 📁 srcs
│   ├── main.c
│   └── (.c)
├── 📁 includes
│   └── (.h)
├── 📁 minilibx-linux
│   └── minilibx-linux.tgz
├── 📁 libft
│   └── (libft / gnl / ft_printf)
└── Makefile
```

El main.c consistira en abrir una ventana y ser capaz de cerrarla.
```c
#include "mlx.h"
#include <stdlib.h>

int     close_window(void *param)
{
        (void)param;
        exit(0);
        return (0);
}

int     main(void)
{
        void    *mlx;
        void    *window;

        mlx = mlx_init();
        if (mlx == NULL)
                return (1);
        window = mlx_new_window(mlx, 800, 600, "My window");
        if (window == NULL)
                return (1);
        mlx_hook(window,17,0,close_window,NULL);
        mlx_loop(mlx);
        return (0);
}
~    
```

Y por último lo mas importante, construir un buen Makefile.
Para este paso empezamos creando las flags de compilación:
```
NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs
MAKE = make -sC
MKDIR = mkdir -p
```
El nombre va a ser fractol por tanto vamos a necesitar un main.c
Las siguientes flags son las mismas que los anteriores proyectos, las unicas que añadimos son:
- MAKE = make -sC (ejecuta make en modo silecnios (s) mostrando solo errores y cambiando de directorio (C)).
- MKDIR = mkdir -p (crea un nuevo directorio y crea los directorios padres si no existen (p)).

Ahora vamos con la libft:
```
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LINKER = -lft -L $(LIBFT_DIR)
```
Necesitamos la dirección de la carpeta donde este la libft.
El archivo libft.a
Y un LINKER = -lft -L $(LIBFT_DIR)
- -L $(LIBFT_DIR): Especifica un directorio donde el enlazador buscara las bibliotecas
- -lft: (l) especifica biblioteca y (ft) nombre biblioteca sin el prefijo lib ni extension .a

En un futuro añadiremos archivos a la carpeta includes:
```
INCLUDES_DIR = includes
INCLUDES_FLAG = -I$(INCLUDES_DIR) \
                        -I$(LIBFT_DIR) \

INCLUDES = $(wildcard $(INCLUDES_DIR)/*.h) \
                $(LIBFT_DIR)/libft.h
```
Indicamos una direcion donde guardemos los archivos includes.
- -I$(INCLUDES_DIR) \ -IS(LIBFT_DIR): Agrega un directorio a la lista de lugares donde buscamos los archivos
- $(wildcar $(INCLUDES_DIR/ *.h) \ $(LIBFT_DIR)/libft.h: Busca los archivos que acaben en .h en includes dir y libft.h

Construimos los sources y objects
```
SRCS_DIR = srcs/
SRC_FILES = main.c
SRCS = $(addprefix $(SRCS_DIR), $S(SRC_FILES))

OBJS_DIR = objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
```
Para este primer paso solo necesitamos el main.c

Contruimos la base para trabajar con la minilibx-linux
```
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LINKER += -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
INCLUDES_FLAG += -I$(MLX_DIR)
```
Indicamos la dirección donde tenemos la minilibx. Con MLX guardamos el archivo libmlx.a
LINKER += -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR) almacena la biblioteca que se debe enlazar en el ejecutable.
- -lmlx: enlaza la biblioteca llamada mlx.
- -lm: Enlaza la biblioteca matemática.
- -lz: Enlaza la biblioteca de compresión zlib.
- -lXext: Enlaza la biblioteca que extiende funcionalidades de ventanas.
- -lX11: Enlaza la biblioteca para interactuar con ventanas.
- -L $(MLX_DIR): Donde debe de buscarlas

El resto del Makefile es como los proyectos anteriores pero con unas modificaciones:
```
all: $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT):
        @$(MAKE) $(LIBFT_DIR)

$(MLX) :
        @$(MAKE) $(MLX_DIR)

$(OBJS_DIR):
        @$(MKDIR) $(OBJS_DIR)

$(NAME): $(OBJS) Makefile
        @$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
        @$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean:
        @$(RM) $(OBJS_DIR)

fclean:
        @$(RM) $(NAME)
        @$(MAKE) $(LIBFT_DIR) fclean
        @$(MAKE) $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
```

Con todo esto ya prodriamos ejeturar nuestro make para despues llamar al programa ./fractol.
