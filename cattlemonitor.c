#include <reg51.h>
#include <lcd.h>
#define temp_sensor P1_0
#define accel_x P1_1
#define accel_y P1_2
#define accel_z P1_3
#define buzzer P3_0
void delay_ms(unsigned int ms);
void main() {
    unsigned int temperature, x_axis, y_axis, z_axis;
    lcd_init();
    buzzer = 0;
    while(1) {
        temperature = analogRead(temp_sensor);
        x_axis = analogRead(accel_x);
        y_axis = analogRead(accel_y);
        z_axis = analogRead(accel_z);
        lcd_clear();
        lcd_gotoxy(0, 0);
        lcd_printf("Temp: %d", temperature);
        lcd_gotoxy(0, 1);
        lcd_printf("X:%d Y:%d Z:%d", x_axis, y_axis, z_axis);
        if(temperature > THRESHOLD_TEMP || isMovementAbnormal(x_axis, y_axis, z_axis)) {
            buzzer = 1; 
        } else {
            buzzer = 0;
        }
        delay_ms(1000);
    }
}
unsigned int analogRead(unsigned char pin) {
    return 0;
}
int isMovementAbnormal(unsigned int x, unsigned int y, unsigned int z) {
    return 0;
}
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}
