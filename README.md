# 42-fractol
Project basic of graphics with miniLibX. We will draw a fractal.

# Basic functions:
1. open -> int open(const char *path, int flags, mode_t mode);
Description: Open a File.
path: path of the file.
flags: Options to open the file.
mode (optional): for example we use it if we need permisions or other.
Return: Success -> file descriptor / Error -> -1.

2. close -> int close(int fd)
Description: Close a file.
fd: file descriptor.
Return: Success -> 0 / Error -> -1.

Example open & close:
Code c:
  int fd = open("example.txt", O_RDONLY);
  if (fd == -1)
    perror("Error to open the file)
  if (close(fd) == -1)
    perror("Error to close the file")
    
3. read -> ssize_t read(int fd, void *buf, size_t count);
Description: Read a file descriptor
fd: file desciptor (open).
buf: pointer of memory.
count: number of bytes to read.
Return: Success -> Numbers of bytes readed. (0 is the end od the file) / Error -> -1

4. write -> ssize_t write(int fd, cons void *buf, size_t count);
Description: Write buf in file descriptor
fd: file descriptor (open)
buf: pointer of memory
count: numbers of bytes
Return: Success -> numners of bytes writed / Error -> -1

5. malloc -> void* malloc(size_t size)
Description: Allocate memory
size: Number of bytes allocated
Return: Success -> void Pointer / Error -> NULL
   
6. free -> void free(void *ptr);
Description: Free memory
ptr: Pointer to free
Return: Nothing
  
7. perror -> void perror(cons char *s)
Description: Print an error message
s: error message
Return: Nothing
  
8. strerror -> char* strerror(int errnum)
Description: Error description
errnum: error code
Return: string

9. exit -> void exit(int stauts)
Description: Terminate the execution of a program
status: 0 (success) / other (error)
Return: Nothing


   
