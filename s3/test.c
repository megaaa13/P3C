#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int equals(int a, int b)
{
    return a != b;
}
int notequals(int a, int b)
{
    return a == b;
}
int greaterore(int a, int b)
{
    return a < b;
}
int greater(int a, int b)
{
    return a <= b;
}
int lessore(int a, int b)
{
    return a > b;
}
int less(int a, int b)
{
    return a >= b;
}

int main(int argc, char const *argv[])
{
    if (argc == 4)
    {
        if (strcasecmp("-eq", argv[2]) == 0)
        {
            return equals(atoi(argv[1]), atoi(argv[3]));
        }
        else if (strcasecmp("-ge", argv[2]) == 0)
        {
            return greaterore(atoi(argv[1]), atoi(argv[3]));
        }
        else if (strcasecmp("-gt", argv[2]) == 0)
        {
            return greater(atoi(argv[1]), atoi(argv[3]));
        }
        else if (strcasecmp("-le", argv[2]) == 0)
        {
            return lessore(atoi(argv[1]), atoi(argv[3]));
        }
        else if (strcasecmp("-lt", argv[2]) == 0)
        {
            return less(atoi(argv[1]), atoi(argv[3]));
        }
        else if (strcasecmp("-ne", argv[2]) == 0)
        {
            return notequals(atoi(argv[1]), atoi(argv[3]));
        }
        return 1;
    }
    return 1;
}