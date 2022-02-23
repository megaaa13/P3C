#include <stdint.h>
#include <stdlib.h>
 
int cmp_func (uint8_t (*f1) (uint8_t), uint8_t (*f2) (uint8_t)) {
    if (f1 == NULL || f2 == NULL)
    for (int i = 0; i < 256; i++) {
        if (f1(i) != f2(i)) return 1;
    }
    return 0;
}