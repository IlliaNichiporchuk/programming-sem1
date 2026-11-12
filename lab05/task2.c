#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Прототипи функцій
void configure_register(uint32_t *reg);
int check_status_flag(const uint32_t *reg, uint8_t bit_pos);

int main(void) {
    uint32_t reg = 0x10000002;
    int status;

    printf("Register before: 0x%08" PRIX32 "\n", reg);

    configure_register(&reg);

    printf("Register after:  0x%08" PRIX32 "\n", reg);

    status = check_status_flag(&reg, 28);

    if (status == -1) {
        printf("Error: invalid pointer or bit position.\n");
        return 1;
    }

    printf("Bit 28 status: %d\n", status);

    return 0;
}

// Налаштування бітів регістра
void configure_register(uint32_t *reg) {
    if (reg == NULL) {
        return;
    }

    *reg |= (UINT32_C(1) << 5);   // Встановити біт 5
    *reg &= ~(UINT32_C(1) << 1);  // Скинути біт 1
    *reg ^= (UINT32_C(1) << 14);  // Інвертувати біт 14
}

// Перевірка стану біта
int check_status_flag(const uint32_t *reg, uint8_t bit_pos) {
    if (reg == NULL || bit_pos >= 32) {
        return -1;
    }

    return (*reg >> bit_pos) & UINT32_C(1);
}