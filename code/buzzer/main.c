#define GPD0CON (*(volatile unsigned long*)0xe02000a0)
#define GPD0DAT (*(volatile unsigned long*)0xe02000a4)

#define GPH0CON (*(volatile unsigned long*)0xe0200c40)
#define GPH0DAT (*(volatile unsigned long*)0xe0200c44)

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
    GPH0CON &= 0x0;
    while(1){
        if(GPH0DAT & 0x1){
            buzzer_off();
        }else{
            buzzer_on();
        }
    }
    return 0;
}
