#include <unistd.h>

int ft_handle_percent(void)
{
    write(1, "%", 1);
    return(1);
}