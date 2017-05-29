#define GPD0CON (*(volatile unsigned long*)0xe02000a0)
#define GPD0DAT (*(volatile unsigned long*)0xe02000a4)

void buzzer_on(){
    GPD0DAT |= 0x1;
}

void buzzer_off(){
    GPD0DAT &= 0x0;
}

void delay(){
    int i = 0x50000;
    while(--i);
}

int main(void){
    GPD0CON |= 0x1;
    while(1){
        buzzer_on();
        delay();
        buzzer_off();
        delay();
    }
    return 0;
}
