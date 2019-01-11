#include"main.h"
#include"judg.h"
#include"Enemy.h"
#include"Player.h"
#include"Boss.h"


bool PEjudg = false;
bool  SEjudg[ENEMY_MAX];


int hitjudg(float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float l, float m, int n, int o, DRAW_STATE p)
{

	//a=g_PShot.x
	//b=g_PShot.Xscale
	//c=g_Enemy.x
	//d=g_Enemy.Xjudg
	//e=g_PShot.y 
	//f=g_PShot.Yscale
	//g=g_Enemy.y
	//h=g_Enemy.Yjudg
	//j=g_Player.x
	//k=g_Player.Xjudg
	//l=g_Player.y
	//m=g_Player.Yjudg
	//n=SEjudg[i]
	//o=
	//p=g_EShot
	//íeÇ∆ÉGÉlÉ~Å[ÇÃìñÇΩÇËîªíË
	if (EnemySpeed != 0 && SEjudg[n] == false)
	{
		PShotSpeed[o] = 20;
		if ((a - b) <= (c + d) && (c - d) <= (a + b) && (e - f) <= (g + h) && (g - h) <= (e + f))
		{
			SEjudg[n] = true;
			Eright[n] = true;
			Eleft[n] = false;
			Edown[n] = false;
			downcount[n] = 0;
			g_PShot[o].x = 3000;
		}
	}
	//íxÇ≠Ç»Ç¡ÇƒÇÈÇ∆Ç´ÇÊÇ§
	if (EnemySpeed == 0)
	{
		if ((a - b) <= (c + d) && (c - d) <= (a + b) && (e - f) <= (g + h) && (g - h) <= (e + f))
		{
			PShotSpeed[o] = 0;
		}
	}
	//é©ã@Ç∆ìGÇÃìñÇΩÇËîªíË

	if (muteki == 240 * 4 && PEjudg == false)
	{
		if ((j - k) <= (c + d) && (c - d) <= (j + k) && (l - m) <= (g + h) && (g - h) <= (l + m))
		{
			playerflag -= 1;
			PEjudg = true;
			muteki = 0;
		}
		if (p.x - p.Xscale < j&& j < p.x + p.Xscale&& p.y - p.Yscale < l&&l < p.y + p.Yscale)
		{
			playerflag -= 1;
			PEjudg = true;
			muteki = 0;
		}
	}

	return 0;
}
int hitjudgB(float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float l, float m, int n, int o, DRAW_STATE p)
{

	//a=g_PShot.x
	//b=g_PShot.Xscale
	//c=g_Enemy.x
	//d=g_Enemy.Xjudg
	//e=g_PShot.y 
	//f=g_PShot.Yscale
	//g=g_Enemy.y
	//h=g_Enemy.Yjudg
	//j=g_Player.x
	//k=g_Player.Xjudg
	//l=g_Player.y
	//m=g_Player.Yjudg
	//n=SEjudg[i]
	//o=
	//p=g_EShot
	//íeÇ∆ÉGÉlÉ~Å[ÇÃìñÇΩÇËîªíË
	if (EnemySpeed != 0 && SEjudg[n] == false)
	{
		PShotSpeed[o] = 20;
		if ((a - b) <= (c + d) && (c - d) <= (a + b) && (e - f) <= (g + h) && (g - h) <= (e + f))
		{
   			BossHp -= 1;
			downcount[n] = 0;
			g_PShot[o].x = 3000;
		}
	}
	//íxÇ≠Ç»Ç¡ÇƒÇÈÇ∆Ç´ÇÊÇ§
	if (EnemySpeed == 0)
	{
		if ((a - b) <= (c + d) && (c - d) <= (a + b) && (e - f) <= (g + h) && (g - h) <= (e + f))
		{
			PShotSpeed[o] = 0;
		}
	}
	//é©ã@Ç∆ìGÇÃìñÇΩÇËîªíË

	if (muteki == 240 * 4 && PEjudg == false)
	{
		if ((j - k) <= (c + d) && (c - d) <= (j + k) && (l - m) <= (g + h) && (g - h) <= (l + m))
		{
			playerflag -= 1;
			PEjudg = true;
			muteki = 0;
		}
		if (p.x - p.Xscale < j&& j < p.x + p.Xscale&& p.y - p.Yscale < l&&l < p.y + p.Yscale)
		{
			playerflag -= 1;
			PEjudg = true;
			muteki = 0;
		}
	}

	return 0;
}
void judg3(int j, int k, int c, int d, int l, int m, int g, int h)
{
	if (muteki == 240 * 4 && PEjudg == false)
	{
		if ((j - k) <= (c + d) && (c - d) <= (j + k) && (l - m) <= (g + h) && (g - h) <= (l + m))
		{
			playerflag -= 1;
			PEjudg = true;
			muteki = 0;
		}
		
	}
}
