#include "arm_movement.h"
#include <math.h>
#include <pico/stdlib.h>
#include <stdlib.h>

float3_t *float_vec_init(float x, float y, float z)
{
    float3_t *vec = (float3_t*)malloc(sizeof(float3_t));
    vec->a = x;
    vec->b = y;
    vec->c = z;

    return vec;
} 

float3_t *arm_get_angles(float3_t *pos, float3_t *size)
{
    float a = atan2(pos->a, pos->b) + M_PI;

    float c = acos(((pos->c-size->a)*(pos->c-size->a) + pos->b*pos->b 
                       + pos->a*pos->a - size->b*size->b - size->c*size->c)/(2*size->b*size->c));

    float b = atan2(pos->c-size->a, -sqrt(pos->a*pos->a + pos->b*pos->b)) 
              - atan2(size->c*sin(c), size->b + size->c*cos(c));
    
    return float_vec_init(a, b, c);
}

arm_t *arm_init(uint16_t gpio1, uint16_t gpio2, uint16_t gpio3, uint16_t gpio4, float3_t *size)
{
    arm_t *brobo = (arm_t*)malloc(sizeof(arm_t));

    brobo->m1 = sg90_init(gpio1);
    brobo->m2 = sg90_init(gpio2);
    brobo->m3 = sg90_init(gpio3);
    brobo->m4 = sg90_init(gpio4);
    brobo->size = size;

    brobo->prev_angles = float_vec_init(90.0f-13.0f, 0.0f, 0.0f);

    sg90_attach(brobo->m1);
    sg90_attach(brobo->m2);
    sg90_attach(brobo->m3);
    sg90_attach(brobo->m4);

    return brobo;
}

void arm_move_to_angles(arm_t *brobo, float3_t *angles, int claw)
{
    if(claw)
        sg90_write(brobo->m4, 0.0f);
    else
        sg90_write(brobo->m4, 180.0f);

    int i = 0;

    if(brobo->prev_angles->a < angles->a)
    {
        for(i = brobo->prev_angles->a; i <= angles->a - 13.0f; i += 2)
        {
            sg90_write(brobo->m1, (float) i );
            sleep_ms(40);
        }
        sg90_write(brobo->m1, angles->a-13.0f);
        sleep_ms(40);
    }
    else if(brobo->prev_angles->a > angles->a)
    {
        for(i = brobo->prev_angles->a; i >= angles->a - 13.0f; i -= 2)
        {
            sg90_write(brobo->m1, (float) i );
            sleep_ms(40);
        }
        sg90_write(brobo->m1, angles->a-13.0f);
        sleep_ms(40);
    }
    
    if(brobo->prev_angles->c != angles->c)
    {
        sg90_write(brobo->m3, angles->c + 5.0f);
        sleep_ms(600);
    }

    if(brobo->prev_angles->b < angles->b)
    {
        for(int i = brobo->prev_angles->b; i <= angles->b - 13.0f; i += 2)
        {
            sg90_write(brobo->m2, (float) i);
            sleep_ms(40);
        }
        sg90_write(brobo->m2, angles->b-13.0f);
        sleep_ms(40);
    }    
    else if(brobo->prev_angles->b < angles->b)
    {
        for(int i = brobo->prev_angles->b; i >= angles->b - 13.0f; i -= 2)
        {
            sg90_write(brobo->m2, (float) i);
            sleep_ms(40);
        }
        sg90_write(brobo->m2, angles->b-13.0f);
        sleep_ms(40);
    }
    brobo->prev_angles = angles;
}


void arm_move_to_joystick_angles(arm_t *brobo, float3_t *angles, int claw)
{
    if(claw)
        sg90_write(brobo->m4, 0.0f);
    else
        sg90_write(brobo->m4, 180.0f);

    int i = 0;

    if(brobo->prev_angles->a < angles->a)
    {
        for(i = brobo->prev_angles->a; i <= angles->a - 13.0f; i += 7)
        {
            sg90_write(brobo->m1, (float) i );
            sleep_ms(40);
        }
    }
    else if(brobo->prev_angles->a > angles->a)
    {
        for(i = brobo->prev_angles->a; i >= angles->a - 13.0f; i -= 7)
        {
            sg90_write(brobo->m1, (float) i );
            sleep_ms(40);
        }
    }

    if(brobo->prev_angles->b < angles->b)
    {
        for(i = brobo->prev_angles->b; i <= angles->b - 13.0f; i += 7)
        {
            sg90_write(brobo->m2, (float) i );
            sleep_ms(40);
        }
    }
    else if(brobo->prev_angles->b > angles->b)
    {
        for(i = brobo->prev_angles->b; i >= angles->b - 13.0f; i -= 7)
        {
            sg90_write(brobo->m2, (float) i );
            sleep_ms(40);
        }
    }

    if(brobo->prev_angles->c < angles->c)
    {
        for(i = brobo->prev_angles->c; i <= angles->c - 5.0f; i += 7)
        {
            sg90_write(brobo->m3, (float) i );
            sleep_ms(40);
        }
    }
    else if(brobo->prev_angles->c > angles->c)
    {
        for(i = brobo->prev_angles->c; i >= angles->c - 5.0f; i -= 7)
        {
            sg90_write(brobo->m3, (float) i );
            sleep_ms(40);
        }
    }
    brobo->prev_angles = angles;
}

void arm_move_to_origin(arm_t *brobo)
{
    sg90_write(brobo->m4, 180.0f);
    
    int i = 0;
    
    for(i = brobo->prev_angles->b; i >= 0; i -= 7)
    {
        sg90_write(brobo->m2, i);
        sleep_ms(40);
    }
    
    for(i = brobo->prev_angles->c; i >= 0; i -= 7)
    {
        sg90_write(brobo->m3, i);
        sleep_ms(40);
    }

    sleep_ms(200);
    
    sg90_write(brobo->m1, 90.0f-13.0f);

    brobo->prev_angles = float_vec_init(90.0f - 13.0f, 0.0f, 0.0f);
}

void arm_move_to_xyz(arm_t *brobo, float3_t *pos, int claw)
{
    float3_t *ang = arm_get_angles(pos, brobo->size);

    ang->a -= M_PI;
    ang->b -= 0.0f;
    ang->c -= -M_PI_2;

    ang->a *= RAD2DEG;
    ang->b *= RAD2DEG;
    ang->c *= RAD2DEG;

    ang->c = 180.0f - ang->c;

    if(ang->a < 0.0f)
        ang->a += 360.0f;

    if(ang->b < 0.0f)
        ang->b += 360.0f;

    if(ang->c < 0.0f)
        ang->c += 360.0f;
    
    arm_move_to_angles(brobo, ang, claw);
}

void arm_move_joystick(arm_t *brobo, uint16_t x, uint16_t y, uint16_t bz1, uint16_t bz2, uint16_t bg, float3_t *prev_pos) 
{
    x *= 180.0f/4095.0f ;

    y *= 180.0f/4095.0f;

    if(x - prev_pos->a < 3.0f || prev_pos->a - x < 3.0f)
        prev_pos->a = x;

    if(y - prev_pos->b < 3.0f || prev_pos->b - y < 3.0f)
        prev_pos->b = y;

    if(bz1 >= 1 && bz2 <= 0)
        prev_pos->c += 2.0f;
    else if (bz1 <= 0 && bz2 >= 1)
        prev_pos->c -= 2.0f;

    if(prev_pos->c - 180.0f > 0.01f)
        prev_pos->c = 180.0f;
    else if(prev_pos->c < 0.0f)
        prev_pos->c = 0.0f;

    arm_move_to_joystick_angles(brobo, prev_pos, bg);
}