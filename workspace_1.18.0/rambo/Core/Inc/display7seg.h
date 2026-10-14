#ifndef __DISPLAY7SEG_H
#define __DISPLAY7SEG_H

extern const unsigned char seg7[];
extern const unsigned char disp7seg[];
extern int curr7seg;
extern int flag_7seg;

void print7seg(int, int, int);
void Atualiza7seg(int);

#endif
