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
    
3. read -> ssize_t read(int fd, void *buf, size_t count)
Description: Read a file descriptor
fd: file desciptor (open).
buf: pointer to save the data.
count: number of bytes to read.
Return: Success -> Numbers of bytes readed. (0 is the end od the file) / Error -> -1

6. write ->
7. malloc ->
8. free ->
9. perror ->
10. strerror ->
11. exit ->
