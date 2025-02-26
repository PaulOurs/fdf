#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;
        s++;
    }
    return NULL;
}

int ft_atoi_base(const char *str, const char *base)
{
    int result = 0;
    int base_len = 0;
    int sign = 1;
    int i;

    // Determine the length of the base
    while (base[base_len] != '\0')
        base_len++;

    // Skip leading whitespace
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')
        str++;

    // Handle sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

	str += 2;

    // Convert the string to an integer
    while (*str != '\0')
    {
        int digit = -1;
        for (i = 0; i < base_len; i++)
        {
            if (*str == base[i])
            {
                digit = i;
                break;
            }
        }
        if (digit == -1)
            break;
        result = result * base_len + digit;
        str++;
    }

    return result * sign;
}

int get_color(char *token)
{
    char *comma;

    comma = ft_strchr(token, ',');
    if (comma)
    {
        // Skip the comma and any whitespace
        comma++;
        while (*comma == ' ' || *comma == '\t')
            comma++;

        // Convert the hexadecimal part to an integer
        return ft_atoi_base(comma, "0123456789ABCDEF");
    }
    return 0xFFFFFF; // Default color if parsing fails
}

int main() {
    char *token = ",0xFF00FF";
    int color = get_color(token);
    printf("Color: 0x%X\n", color); // Should print: Color: 0xFF00FF
    return 0;
}
