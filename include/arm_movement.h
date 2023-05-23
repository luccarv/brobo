#ifndef _ARM_MOVEMENT_H_

#include "sg90.h"

#define RAD2DEG 180.0f*M_1_PI


typedef struct
{
    float a;
    float b;
    float c;
}float3_t;

typedef struct {
    sg90_t *m1;
    sg90_t *m2;
    sg90_t *m3;
    sg90_t *m4;

    float3_t *prev_angles;
    float3_t *size;
}arm_t;

arm_t *arm_init(uint16_t gpio1, uint16_t gpio2, uint16_t gpio3, uint16_t gpio4, float3_t *size);
void arm_move_to_xyz(arm_t *brobo, float3_t *pos, int claw);
void arm_move_to_angles(arm_t *brobo, float3_t *angles, int claw);
void arm_move_to_origin(arm_t *brobo);
void arm_move_joystick(arm_t *brobo, uint16_t x, uint16_t y, uint16_t bz1, uint16_t bz2, uint16_t bg, float3_t *prev_pos);

float3_t *float_vec_init(float x, float y, float z);
float3_t *arm_get_angles(float3_t *pos, float3_t *size);

#endif