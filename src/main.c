#include "arm_movement.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdio.h>

int main()
{
    stdio_init_all();
    arm_t *a = arm_init(16, 17, 18, 19, float_vec_init(6.0f, 8.5f, 10.4f));
    arm_move_to_origin(a);

    sleep_ms(5000);

    /*
    arm_move_to_xyz(a, float_vec_init(12.5f, 7.1f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(12.5f, 7.1f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(12.5f, 2.6f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(12.5f, 2.6f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(12.5f, -1.3f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(12.5f, -1.3f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(12.5f, -5.3f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(12.5f, -5.3f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    */

    arm_move_to_xyz(a, float_vec_init(7.0f, 7.1f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(7.0f, 7.1f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(7.0f, 2.6f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(7.0f, 2.6f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(7.0f, -1.3f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(7.0f, -1.3f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(7.0f, -5.3f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(7.0f, -5.3f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    
    
    arm_move_to_xyz(a, float_vec_init(16.3f, 7.1f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(16.3f, 7.1f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(16.3f, 2.6f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(16.3f, 2.6f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(16.3f, -1.3f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(16.3f, -1.3f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    arm_move_to_xyz(a, float_vec_init(16.3f, -5.3f, 0.0f), 1);
    sleep_ms(2000);
    arm_move_to_xyz(a, float_vec_init(16.3f, -5.3f, 0.0f), 0);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 0);
    sleep_ms(2000);
    arm_move_to_angles(a, float_vec_init(90.0f, 0.0f, 135.0f), 1);
    sleep_ms(2000);
    arm_move_to_origin(a);
    sleep_ms(2000);

    
    
   /* 
    adc_init();

    adc_gpio_init(26);
    adc_gpio_init(27);

    int x0 = 0;
    int x1 = 0;
    */
    for(;;)
    {
        /*
        adc_select_input(0);
        x0 = adc_read();

        adc_select_input(1);
        x1 = adc_read();

        arm_move_joystick(a, x0, x1, 0, 0, 0);

        */
    }

    return 0;
}