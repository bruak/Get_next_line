# Get Next Line (GNL)

A C function that reads a line from a file descriptor. This project focuses on understanding and implementing file manipulation, memory allocation, buffer management, and static variables in C programming.

## Table of Contents
- [Get Next Line (GNL)](#get-next-line-gnl)
  - [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [Features](#features)
  - [Function Prototypes](#function-prototypes)
  - [How It Works](#how-it-works)
  - [Usage](#usage)
  - [Example](#example)
  - [Compilation](#compilation)
  - [Bonus Part](#bonus-part)

## Description

The `get_next_line` function reads a line from a file descriptor and returns it without the newline character. When called in a loop, this function allows reading a file line by line until the end is reached. This implementation handles various edge cases such as invalid file descriptors, reading errors, and memory allocation failures.

## Features

- **Line-by-line reading**: Reads text from a file descriptor one line at a time
- **Memory management**: Properly handles memory allocation and deallocation
- **Static variables**: Uses static variables to keep track of remaining text
- **Buffer size flexibility**: Works with different buffer sizes defined at compilation
- **Multiple FD support**: Can handle multiple file descriptors simultaneously

## Function Prototypes

```c
// Main function
char *get_next_line(int fd);

// Utility functions
char *read_function(int fd, char *str);
char *ft_getline(char *fullStr);
char *ft_getrest(char *fullStr);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(char *s, int c);
size_t ft_strlen(char *s);
```

## How It Works

1. **get_next_line**: The main function that receives a file descriptor and returns the next line from it
2. **read_function**: Reads data from the file descriptor into a buffer and adds it to an accumulator
3. **ft_getline**: Extracts the next line from the accumulated string
4. **ft_getrest**: Extracts the remainder of the string after the line for future calls
5. **ft_strjoin**: Concatenates two strings, freeing the first string
6. **ft_strchr**: Finds the first occurrence of a character in a string
7. **ft_strlen**: Calculates the length of a string

The function uses a static variable to maintain state between successive calls, remembering what was already read but not yet returned.

## Usage

Include the header file in your program:

```c
#include "get_next_line.h"
```

Call the function in a loop to read all lines from a file:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    // Process the line
    printf("%s", line);
    free(line); // Don't forget to free the allocated memory
}
close(fd);
```

## Example

A sample program is provided in `test.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int i = 0;
    while ((line = get_next_line(fd)))
    {
        printf("%d: %s\n", i, line);
        free(line);
        i++;
    }    
    
    close(fd);
    return (0);
}
```

## Compilation

Compile your program with the source files and define the buffer size:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c test.c -o gnl
```

You can adjust the buffer size by changing the value of BUFFER_SIZE:

```bash
# Compile with a different buffer size
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c test.c -o gnl
```

## Bonus Part

The standard version of `get_next_line` handles reading from a single file descriptor. The bonus part extends this functionality to handle multiple file descriptors simultaneously, allowing for interleaved reads without losing track of each file's position.

---

*This project is part of the 42 School curriculum.*