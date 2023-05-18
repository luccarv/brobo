#include "arm_movement.h"
#include <math.h>
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

arm *arm_init(uint16_t gpio1, uint16_t gpio2, uint16_t gpio3, uint16_t gpio4, float3_t *size)
{
    arm *brobo = (arm*)malloc(sizeof(brobo));

    brobo->m1 = sg90_init(gpio1);
    brobo->m2 = sg90_init(gpio2);
    brobo->m3 = sg90_init(gpio3);
    brobo->m4 = sg90_init(gpio3);
    brobo->size = size;

    sg90_attach(brobo->m1);
    sg90_attach(brobo->m2);
    sg90_attach(brobo->m3);
    sg90_attach(brobo->m4);

    return brobo;
}

void arm_move_to_angles(arm *brobo, float3_t *angles, int claw)
{
    sg90_write(brobo->m1, angles->a);
    sg90_write(brobo->m2, angles->b);
    sg90_write(brobo->m3, angles->c);

    if(claw)
        sg90_write(brobo->m4, 0.0f);
    else
        sg90_write(brobo->m4, 180.0f);
}

void arm_move_to_origin(arm *brobo)
{
    sg90_write(brobo->m1, 90.0f);
    sg90_write(brobo->m2, 90.0f);
    sg90_write(brobo->m3, 90.0f);
    sg90_write(brobo->m4, 180.0f);
}

void arm_move_to_xyz(arm *brobo, float3_t *pos, int claw)
{
    float3_t *ang = arm_get_angles(pos, brobo->size);

    ang->a -= M_PI_2;
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

