#include"main.h"
#include"Boss.h"
#include"Enemy.h"
#include"judg.h"
int bosspaturncount = 0;
int bosspaturnflag = 0;
int Bossflag = 0;
int BossHp = 50;
int tonboflag = 0;
float BKEEPX2[5];
float BKEEPY2[5];
float BKEEPX[5];
float BKEEPY[5];

void Bossinit()
{
		g_BShot[0] = { g_Boss1.x, g_Boss1.y+100, 20.f ,20.f,20.f,30.f };
		g_BShot[1] = { g_Boss1.x, g_Boss1.y + 100, 20.f ,20.f,20.f,30.f };
		g_BShot[2] = { g_Boss1.x, g_Boss1.y + 100, 20.f ,20.f,20.f,30.f };
}

 void BossMove1()
 {
	 g_BShot[0].x -= 3.f;
	 g_BShot[0].y += 10.f;
	 g_BShot[1].y += 10.f;
	 g_BShot[2].x += 3.f;
	 g_BShot[2].y += 10.f;
	 
 }
 void BossMove2()
 {

	 Eshotflag = false;
	 for(int i=0;i<4;i++)
	 if (SEjudg[i] == false)
	 {
		 if (SEjudg[i] == false && g_Enemy[i].y <= HIGHT && g_Enemy[i].y >= 0)g_Enemy[i].y += EnemySpeed + 6;
	 }
	 
 }
 void tonbomove1()
 {
	 tonboflag = 0;
	 g_Boss1.y += EnemySpeed;
 }

 void tonbomove2()
 {
	 tonboflag = 1;
	 g_Boss1.x += EnemySpeed+2.f ;
 }
 

 void tonbomove3()
 {
	 tonboflag = 2;
	 g_Boss1.x -= EnemySpeed+2.f ;
 }

 void kamakirimove( int j, int b, int c)
 {
	
	 static bool onetime = true;
	 if (onetime)
	 {
		 BKEEPX2[j] = g_BossLEFT.x;
		 BKEEPY2[j] = g_BossLEFT.y;
		 BKEEPX[j] = g_Player.x;
		 BKEEPY[j] = g_Player.y;
		 onetime = false;
	 }


	 if (BKEEPX2[j] - BKEEPX[j] > 0)
	 {
		 g_BossLEFT.x -= (BKEEPX2[j] - BKEEPX[j]) / EShotSpeed;
	 }
	 if (BKEEPX[j] - BKEEPX2[j] > 0)
	 {
		 g_BossLEFT.x += (BKEEPX[j] - BKEEPX2[j]) / EShotSpeed;
	 }
	 if (BKEEPY2[j] - BKEEPY[j] > 0)
	 {
		 g_BossLEFT.y -= (BKEEPY2[j] - BKEEPY[j]) / EShotSpeed;
	 }
	 if (BKEEPY[j] - BKEEPY2[j] > 0)
	 {
		 g_BossLEFT.y += (BKEEPY[j] - BKEEPY2[j]) / EShotSpeed;
	 }
	 if (g_BossLEFT.y > HIGHT || g_BossLEFT.y < 0.f || g_BossLEFT.x<128.f || g_BossLEFT.x>WIDTH)
	 {
		 g_BossLEFT.x = b;
		 g_BossLEFT.y = c;
		 onetime = true;
		 bosspaturnflag = 1;

	 }
 }
 
 void kamakirimove2( int j, int b, int c)
 {

	 static bool onetime = true;
	 if (onetime)
	 {
		 BKEEPX2[j] = g_BossRIGHT.x;
		 BKEEPY2[j] = g_BossRIGHT.y;
		 BKEEPX[j] = g_Player.x;
		 BKEEPY[j] = g_Player.y;
		 onetime = false;
	 }


	 if (BKEEPX2[j] - BKEEPX[j] > 0)
	 {
		 g_BossRIGHT.x -= (BKEEPX2[j] - BKEEPX[j]) / EShotSpeed;
	 }
	 if (BKEEPX[j] - BKEEPX2[j] > 0)
	 {
		 g_BossRIGHT.x += (BKEEPX[j] - BKEEPX2[j]) / EShotSpeed;
	 }
	 if (BKEEPY2[j] - BKEEPY[j] > 0)
	 {
		 g_BossRIGHT.y -= (BKEEPY2[j] - BKEEPY[j]) / EShotSpeed;
	 }
	 if (BKEEPY[j] - BKEEPY2[j] > 0)
	 {
		 g_BossRIGHT.y += (BKEEPY[j] - BKEEPY2[j]) / EShotSpeed;
	 }
	 if (g_BossRIGHT.y > HIGHT || g_BossRIGHT.y < 0.f || g_BossRIGHT.x<128.f || g_BossRIGHT.x>WIDTH)
	 {
		 g_BossRIGHT.x = b;
		 g_BossRIGHT.y = c;
		 onetime = true;
		 bosspaturnflag = 0;
	 }
 }

 
