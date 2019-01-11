#include"main.h"
#include"Player.h"


bool Pshotslow = false;
bool  Pshotflag = false;
int PShotSpeed[P_MAX_SHOT];



void PlayerInit()
{
	for (int i = 0; i < P_MAX_SHOT; i++)
		PShotSpeed[i] = 20;
}


void  P_ShotControl()
{
	if (Pshotflag)
	{

		for (int j = 0; j < P_MAX_SHOT; j++)
		{
			if (g_PShot[j].flag == 0)
			{
				g_PShot[j].flag = 1;
				g_PShot[j].x = g_Player.x;
				g_PShot[j].y = g_Player.y;
				g_PShot[j].Xscale = g_Player.Xscale - 20;
				g_PShot[j].Yscale = g_Player.Yscale +20;
				g_PShot[j].Xjudg = g_Player.Yjudg-5;
				g_PShot[j].Yjudg = g_Player.Yjudg+35;
				break;
			}
		}
	}
	for (int j = 0; j < P_MAX_SHOT; j++)
	{
		if (g_PShot[j].flag == 1)
		{
			if (Pshotslow == false) {
				g_PShot[j].y -= PShotSpeed[j];
			}
			else
			{
				g_PShot[j].y -= 1.f;
			}

			if (g_PShot[j].y < 0.f)
			{
				g_PShot[j].x = 2000;
				g_PShot[j].flag = 0;
			}

		}
	}


}
