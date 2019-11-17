#ifndef __song_H
#define __song_H
#ifdef __cplusplus
 extern "C" {
#endif
	 
	 
#define   L1      262
#define   L2      294
#define   L3      330
#define   L4      349
#define   L5      392
#define   L6      440
#define   L7      494

#define   M1      523
#define   M2      587
#define   M3      659
#define   M4      698
#define   M5      784
#define   M6      880
#define   M7      988

#define   H1      1047
#define   H2      1175
#define   H3      1319
#define   H4      1397
#define   H5      1568
#define   H6      1760
#define   H7      1976

#define   Pai     600


typedef struct
{
	unsigned short freq;
	short time_num;
}song_t;

extern song_t Song_Bie[];
extern song_t Hua_Huo[];
extern song_t Qian_QQ_Shi[];
extern song_t Min_Yue[];
extern song_t Dan_Yuan[];
extern song_t Shen_Hua[];
extern song_t molihua[];
extern song_t muyangqu[];
#endif

//#define   L1      147
//#define   L2      165
//#define   L3      175
//#define   L4      196
//#define   L5      221
//#define   L6      248
//#define   L7      278

//#define   M1      294
//#define   M2      330
//#define   M3      350
//#define   M4      393
//#define   M5      441
//#define   M6      495
//#define   M7      556

//#define   H1      589
//#define   H2      661
//#define   H3      700
//#define   H4      786
//#define   H5      882
//#define   H6      990
//#define   H7      1112
