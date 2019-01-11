#pragma once


extern int Bossflag;
extern int bosspaturncount;
extern int bosspaturnflag; 
extern int BossHp;
extern int tonboflag;
extern float BKEEPX2[5];
extern float BKEEPY2[5];
extern float BKEEPX[5];
extern float BKEEPY[5];
void BossMove1();
void Bossinit();
void BossMove2();
void tonbomove1();
void tonbomove2();
void tonbomove3();
void kamakirimove(int j, int b, int c);
void kamakirimove2(int j, int b, int c);