#include "arm_movement.h"
#include "pico/stdlib.h"

int main()
{
    arm_t *a = arm_init(16, 17, 18, 19, float_vec_init(6.0f, 8.5f, 8.0f));
    arm_move_to_origin(a);

    
    sleep_ms(5000);

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

    
    
    for(;;)
    {
    }

    return 0;
}