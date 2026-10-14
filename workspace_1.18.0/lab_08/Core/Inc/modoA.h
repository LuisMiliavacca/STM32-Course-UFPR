#ifndef __MODOA_H
#define __MODOA_H

extern int contador7seg;
extern int flag_count;

extern const unsigned char seg7[];
extern const unsigned char disp7seg[];
extern int curr7seg;
extern int flag_7seg;

void print7seg(int, int, int);
void Atualiza7seg(int);

#endif

