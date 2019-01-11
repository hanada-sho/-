#pragma once


 void EnemyMove(int a);
 void  E_ShotControl();
 void enemyInit();
 void enemymove1();
 void enemymove2();
extern bool Eshotflag ;
extern float EShotSpeed;
extern float EnemySpeed ;
extern bool Eright[ENEMY_NUMBER];
extern bool Eleft[ENEMY_NUMBER];
extern bool Edown[ENEMY_NUMBER];
extern int downcount[ENEMY_NUMBER];
extern int dethcount[ENEMY_NUMBER];
extern float KEEPTV;
extern float KEEPX[E_MAX_SHOT], KEEPY[E_MAX_SHOT], KEEPX2[E_MAX_SHOT], KEEPY2[E_MAX_SHOT];
extern int EP;
extern bool enemy2right[4];
extern bool enemy2left[4];
