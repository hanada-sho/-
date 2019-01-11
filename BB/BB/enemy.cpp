#include"main.h"
#include"Enemy.h"
#include"Judg.h"
#include"Boss.h"
bool Eshotflag = false;
float EnemySpeed = 10.f;
void EnemyMove(int a);
void  E_ShotControl();
void enemyInit();
float EShotSpeed;
bool Eright[ENEMY_NUMBER];
bool Eleft[ENEMY_NUMBER];
bool Edown[ENEMY_NUMBER];
int downcount[ENEMY_NUMBER];
int EP = 1;
float KEEPTV;
float KEEPX[E_MAX_SHOT], KEEPY[E_MAX_SHOT], KEEPX2[E_MAX_SHOT], KEEPY2[E_MAX_SHOT];
bool enemy2right[4];
bool enemy2left[4];
int enemycount[ENEMY_NUMBER];



void enemyInit()
{
	
	g_Enemy[0] = { 180.f,-200.f,50.f,50.f,25.f,25.f };
	g_Enemy[1] = { 360.f,-150.f,50.f,50.f,25.f,25.f };
	g_Enemy[2] = { 540.f,-150.f,50.f,50.f,25.f,25.f };
	g_Enemy[3] = { 720.f,-200.f,50.f,50.f,25.f,25.f };
	g_Enemy[4] = { 180.f,-50.f,50.f,50.f,25.f,25.f };
	g_Enemy[5] = { 288.f,-450.f,50.f,50.f,25.f,25.f };
	g_Enemy[6] = { 396.f,-250.f,50.f,50.f,25.f,25.f };
	g_Enemy[7] = { 504.f,-650.f,50.f,50.f,25.f,25.f };
	g_Enemy[8] = { 612.f,-300.f,50.f,50.f,25.f,25.f };
	g_Enemy[9] = { 720.f,-600.f,50.f,50.f,25.f,25.f };
	g_Enemy[10] = { 180.f,-200.f,50.f,50.f,25.f,25.f };
	

	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		SEjudg[i] = false;
		Eright[i] = true;
		Eleft[i] = false;
		Edown[i] = false;
		downcount[i] = 0;
		dethcount[i] = 0;
		enemycount[i] = 0;
	}

	EShotSpeed = 60.f;


}

void  E_ShotControl()
{
	
		if (Eshotflag)
		{

			for (int j = 0; j < E_MAX_SHOT; j++)
			{
				if (g_EShot[j].flag == 0)
				{
					if (j >= 9 && SEjudg[j / 3] == false)
					{
						g_EShot[j].flag = 1;
						g_EShot[j].x = g_Enemy[3].x;
						g_EShot[j].y = g_Enemy[3].y;
						KEEPX2[j] = g_Enemy[3].x;
						KEEPY2[j] = g_Enemy[3].y;
						KEEPX[j] = g_Player.x;
						KEEPY[j] = g_Player.y;
						g_EShot[j].Xscale = g_Enemy[3].Xscale - 40;
						g_EShot[j].Yscale = g_Enemy[3].Yscale - 40;
						g_EShot[j].Xjudg = g_Enemy[3].Yjudg;
						g_EShot[j].Yjudg = g_Enemy[3].Yjudg;
					}

					else if (j >= 6 && j < 9 && SEjudg[j / 3] == false)
					{
						g_EShot[j].flag = 1;
						g_EShot[j].x = g_Enemy[2].x;
						g_EShot[j].y = g_Enemy[2].y;
						KEEPX2[j] = g_Enemy[2].x;
						KEEPY2[j] = g_Enemy[2].y;
						KEEPX[j] = g_Player.x;
						KEEPY[j] = g_Player.y;
						g_EShot[j].Xscale = g_Enemy[2].Xscale - 40;
						g_EShot[j].Yscale = g_Enemy[2].Yscale - 40;
						g_EShot[j].Xjudg = g_Enemy[2].Yjudg-20;
						g_EShot[j].Yjudg = g_Enemy[2].Yjudg-20;

					}
					else if (j >= 3 && j < 6 && SEjudg[j / 3] == false)
					{
						g_EShot[j].flag = 1;
						g_EShot[j].x = g_Enemy[1].x;
						g_EShot[j].y = g_Enemy[1].y;
						KEEPX2[j] = g_Enemy[1].x;
						KEEPY2[j] = g_Enemy[1].y;
						KEEPX[j] = g_Player.x;
						KEEPY[j] = g_Player.y;
						g_EShot[j].Xscale = g_Enemy[1].Xscale - 40;
						g_EShot[j].Yscale = g_Enemy[1].Yscale - 40;
						g_EShot[j].Xjudg = g_Enemy[1].Yjudg-20;
						g_EShot[j].Yjudg = g_Enemy[1].Yjudg-20;
					}
					else if (j >= 0 && j < 3 && SEjudg[j / 3] == false)
					{
						g_EShot[j].flag = 1;
						g_EShot[j].x = g_Enemy[0].x;
						g_EShot[j].y = g_Enemy[0].y;
						KEEPX2[j] = g_Enemy[0].x;
						KEEPY2[j] = g_Enemy[0].y;
						KEEPX[j] = g_Player.x;
						KEEPY[j] = g_Player.y;
						g_EShot[j].Xscale = g_Enemy[0].Xscale - 40;
						g_EShot[j].Yscale = g_Enemy[0].Yscale - 40;
						g_EShot[j].Xjudg = g_Enemy[0].Yjudg-20;
						g_EShot[j].Yjudg = g_Enemy[0].Yjudg-20;
					}

				}
			}
		}
		for (int j = 0; j < E_MAX_SHOT; j++)
		{
			if (g_EShot[j].flag == 1)
			{
				/*
				g_EShot[j].y += EShotSpeed;*/
				if (KEEPX2[j] - KEEPX[j] > 0)
				{
					g_EShot[j].x -= (KEEPX2[j] - KEEPX[j]) / EShotSpeed;
				}
				if (KEEPX[j] - KEEPX2[j] > 0)
				{
					g_EShot[j].x += (KEEPX[j] - KEEPX2[j]) / EShotSpeed;
				}
				if (KEEPY2[j] - KEEPY[j] > 0)
				{
					g_EShot[j].y -= (KEEPY2[j] - KEEPY[j]) / EShotSpeed;
				}
				if (KEEPY[j] - KEEPY2[j] > 0)
				{
					g_EShot[j].y += (KEEPY[j] - KEEPY2[j]) / EShotSpeed;
				}
				if (g_EShot[j].y > HIGHT || g_EShot[j].y < 0.f || g_EShot[j].x<128.f || g_EShot[j].x>WIDTH)
				{
					g_EShot[j].x = 2000;
					g_EShot[j].flag = 0;
				}

			}
		}
	}

	void enemymove1()
	{
	
		for (int i = 4; i <10; i++)
		{
			if (SEjudg[i] == false)
			{
				g_Enemy[i].y += EnemySpeed;
				if (g_Enemy[i].y >= 820)
				{
					g_Enemy[i].y = 0;
				}
			}
		}
	}
	void enemymove2()
	{

		for (int i = 0; i < 2; i++)
		{
			if (SEjudg[i] == false)
			{
				if (g_Enemy[i].y <= HIGHT - 30)
				{
					g_Enemy[i].y += EnemySpeed;
				}
				else
				{
					enemycount[i] += 1;
				}



				if (g_Enemy[i].y >= 50.f)
				{
					if (enemy2left[i] == false)
					{
						enemy2right[i] = true;
					}

					if (enemy2right[i])
					{
						g_Enemy[i].x += EnemySpeed ;
						if (g_Enemy[i].x >= 300.f)
						{
							enemy2right[i] = false;
							enemy2left[i] = true;
						}
					}
					if (enemy2left[i])
					{
						g_Enemy[i].x -= EnemySpeed ;
						if (g_Enemy[i].x <= 180.f)
						{
							enemy2right[i] = true;
							enemy2left[i] = false;
						}
					}

				}
				if (enemycount[i] == 180)
				{
					g_Enemy[i].y = -50;
					enemycount[i] = 0;
				}
			}

		}
		{
			for (int j = 2; j < 4; j++)
			{
				if (SEjudg[j] == false)
				{
					if (g_Enemy[j].y <= HIGHT - 30)
					{
						g_Enemy[j].y += EnemySpeed;
					}
					else
					{
						enemycount[j] += 1;
					}
				if (g_Enemy[j].y >= 50.f)
				{
					if (enemy2right[j] == false)
					{
						enemy2left[j] = true;
					}

					if (enemy2right[j])
					{
						g_Enemy[j].x += EnemySpeed ;
						if (g_Enemy[j].x >= 730.f)
						{
							enemy2right[j] = false;
							enemy2left[j] = true;
						}
					}
					if (enemy2left[j])
					{
						g_Enemy[j].x -= EnemySpeed ;
						if (g_Enemy[j].x <= 610.f)
						{
							enemy2right[j] = true;
							enemy2left[j] = false;
						}
					}

				}
				if (enemycount[j] == 180)
				{
					g_Enemy[j].y = -50;
					enemycount[j] = 0;
				}
			}
			}
		}
	}






void EnemyMove(int a)
{
	if (Bossflag == 0)
	{
		if (SEjudg[a] == false)
		{
			if (Eright[a] == true)
			{
				g_Enemy[a].x += EnemySpeed+5;
			}
			if (g_Enemy[a].x >= 750.f)
			{
				Eright[a] = false;
				Edown[a] = true;
			}
			if (Edown[a])
			{
				g_Enemy[a].y += EnemySpeed+5;
				downcount[a]++;

				if (downcount[a] == 30)
				{
					downcount[a] = 31;
					Edown[a] = false;
					Eleft[a] = true;
				}
			}
			if (Eleft[a])
			{
				g_Enemy[a].x -= EnemySpeed+5;

				if (g_Enemy[a].x <= 150.f)
				{
					Edown[a] = true;
					Eleft[a] = false;
				}
			}
			if (downcount[a] == 60)
			{
				downcount[a] = 0;
				Edown[a] = false;
				Eright[a] = true;
			}
			if (g_Enemy[a].y > HIGHT)
			{
				g_Enemy[a].y = -30;
			}
		}
	}
}














