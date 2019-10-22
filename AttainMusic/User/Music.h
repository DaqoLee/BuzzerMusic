#ifndef _MUSIC_H
#define _MUSIC_H

#include "stm32f4xx.h"

#define FREQUENCY 1000000 /* 分频后的频率：90M/89+1=1M */
#define T         800    /* 单位: ms */


#define A         0 
#define B         1
#define C         2
#define D         3
#define E         4
#define F         5
#define G         6

#define L1        0
#define L2        1
#define L3        2
#define L4        3
#define L5        4
#define L6        5
#define L7        6

#define M1        7
#define M2        8
#define M3        9
#define M4        10
#define M5 				11
#define M6 				12
#define M7 				13 

#define H1        14
#define H2        15
#define H3        15
#define H4        17
#define H5 				18
#define H6 				19
#define H7 				20

void PlayMusic(const int *MusicScore, int Lenght, int Tune);

#endif


