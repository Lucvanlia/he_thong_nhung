#include <reg51.h>
#include <string.h> 


sbit BTN1 = P1^0;
sbit BTN2 = P1^1; 
sbit BTN3 = P1^2; 
sbit BTN4 = P1^3; 
sbit BTN5 = P1^4; 


sbit FAN = P2^0;


char correct_pass[] = "12345"; 
char input_pass[6];            
unsigned char pass_idx = 0;   


void Delay_ms(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 113; j++);
}


void UART_Init() {
    TMOD = 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}

void UART_SendChar(char c) {
    SBUF = c;
    while (TI == 0);
    TI = 0;
}


void UART_SendString(char *str) {
    while (*str) {
        UART_SendChar(*str++);
    }
}

void check_password() {
    if (pass_idx == 5) { 
        input_pass[5] = '\0'; 

        if (strcmp(input_pass, correct_pass) == 0) {
            FAN = 1;
            UART_SendString("\r\n=> DUNG MAT KHAU! QUAT DANG QUAY.\r\n");
        } else {
            FAN = 0;
            UART_SendString("\r\n=> SAI MAT KHAU! TAT QUAT.\r\n");
        }
        
        pass_idx = 0; 
        UART_SendString("Nhap lai mat khau: ");
    }
}


void handle_key_press(char key) {
    UART_SendChar(key); 
    input_pass[pass_idx] = key; 
    pass_idx++;
    check_password(); 
}

void main() {
    UART_Init();
    P1 = 0xFF; 
    FAN = 0;   
    
    UART_SendString("He thong khoi dong...\r\n");
    UART_SendString("Vui long nhap mat khau 5 so: ");

    while (1) {
        if (BTN1 == 0) {
            Delay_ms(20);
            if (BTN1 == 0) {
                handle_key_press('1'); 
                while (BTN1 == 0);
            }
        }
        if (BTN2 == 0) {
            Delay_ms(20);
            if (BTN2 == 0) {
                handle_key_press('2');
                while (BTN2 == 0);
            }
        }
        if (BTN3 == 0) {
            Delay_ms(20);
            if (BTN3 == 0) {
                handle_key_press('3');
                while (BTN3 == 0);
            }
        }
        if (BTN4 == 0) {
            Delay_ms(20);
            if (BTN4 == 0) {
                handle_key_press('4');
                while (BTN4 == 0);
            }
        }
        if (BTN5 == 0) {
            Delay_ms(20);
            if (BTN5 == 0) {
                handle_key_press('5');
                while (BTN5 == 0);
            }
        }
    }
}