#ifndef __MUSIC_H
#define __MUSIC_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "song.h"
	 
extern char sta;
extern char Music_Num;
	 
void BEEP1_TEXT(void);
void BEEP2_TEXT(void);
void BEEP1_SOUND(unsigned short frq,short time,short pai);
void BEEP2_SOUND(unsigned short frq,short time,short pai);
void BEEP1_PLAY(song_t song[],short pai);
void BEEP2_PLAY(song_t song[],short pai);
void USER_BEEP1(unsigned short frq);
void USER_BEEP2(unsigned short frq);

	 
#endif
