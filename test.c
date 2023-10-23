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
