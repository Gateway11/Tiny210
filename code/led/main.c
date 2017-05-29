#define GPJCOM (*(volatile unsigned long*)0xe0200280)
#define GPJDAT (*(volatile unsigned long*)0xe0200244)

int main(void){
    GPJCOM = 0x00001111;
    GPJDAT = 0x0;
    while(1);
    return 0;
}
