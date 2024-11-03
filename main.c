#include <stdint.h>

// Define memory-mapped GPIO and UART registers
#define GPIO_OUT *(volatile uint32_t *)(0x60000300)
#define GPIO_ENABLE *(volatile uint32_t *)(0x60000310)
#define UART0_FIFO *(volatile uint32_t *)(0x60000000)
#define UART0_STATUS *(volatile uint32_t *)(0x6000001C)
#define UART0_TX_FIFO_CNT 0xFF

void uart_init() {
    // Set up UART0 for serial communication (default baud rate: 115200)
    // More advanced settings may be required, depending on your needs
}

void uart_putc(char c) {
    while ((UART0_STATUS & UART0_TX_FIFO_CNT) == 0);
    UART0_FIFO = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

void delay(volatile int count) {
    while (count--) {}
}

int main() {
    uart_init();

    GPIO_ENABLE |= (1 << 2);

    uart_puts("Starting the loop...\n");

    while (1) {
        GPIO_OUT ^= (1 << 2);
        uart_puts("Toggled GPIO2\n");
        delay(1000000);
    }
}