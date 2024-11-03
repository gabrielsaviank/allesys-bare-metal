#include <stdint.h>

// Define memory-mapped GPIO registers (refer to the ESP8266 memory map)
#define GPIO_OUT *(volatile uint32_t *)(0x60000300)
#define GPIO_ENABLE *(volatile uint32_t *)(0x60000310)

void delay(volatile int count) {
    while (count--) {}
}

int main() {
    GPIO_ENABLE |= (1 << 2);  // Enable GPIO2 as an output
    while (1) {
        GPIO_OUT ^= (1 << 2); // Toggle GPIO2
        delay(1000000);       // Simple delay
    }
}
