
#include"main.h"
#include"Judg.h"
#include"Render.h"
#include"Boss.h"
#include"Enemy.h"
float tv = 0;
float scrollspeed = 0.003f;


RECT MainScore =
{
	600,
	100,
	1200,
	200,
};
RECT SCOREPOINT =
{
	1000,
	100,
	1400,
	200,
};
RECT LOWPOINT =
{
	600,
	500,
	1200,
	600,
};

void scroll()
{
	
		tv -= scrollspeed;
		if (tv == -0.9f)
		{
			tv = 0;
		}
	
}
void Render()
{

	//頂点情報を入れる--------------------------------------

	CUSTOMVERTEX background[4]
	{
		{ 128.f  ,0.f  ,1.f ,1.f, 0xFFFFFFFF, 0.f,tv },
	{ WIDTH,0.f  ,1.f ,1.f, 0xFFFFFFFF, 1.f, tv },
	{ WIDTH,HIGHT,1.f ,1.f, 0xFFFFFFFF, 1.f, tv + 1.f },
	{ 128.f  ,HIGHT,1.f ,1.f, 0xFFFFFFFF, 0.f, tv + 1.f },
	};

	CUSTOMVERTEX background2[4]
	{
		{ WIDTH  ,0.f  ,1.f ,1.f, 0xFFFFFFFF, 0.f,0.f },
	{ 1400.f,0.f  ,1.f ,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1400.f,HIGHT,1.f ,1.f, 0xFFFFFFFF, 1.f,  1.f },
	{ WIDTH  ,HIGHT,1.f ,1.f, 0xFFFFFFFF, 0.f, 1.f },
	};

	CUSTOMVERTEX player[4]
	{
		{ g_Player.x - g_Player.Xscale, g_Player.y - g_Player.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_Player.x + g_Player.Xscale, g_Player.y - g_Player.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_Player.x + g_Player.Xscale, g_Player.y + g_Player.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_Player.x - g_Player.Xscale, g_Player.y + g_Player.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 1.f },
	};
	CUSTOMVERTEX Muteki[4]
	{
		{ g_Player.x - g_Player.Xscale, g_Player.y - g_Player.Yscale,1.f,1.f, 0xFFFF0000, 0.f, 0.f },
	{ g_Player.x + g_Player.Xscale, g_Player.y - g_Player.Yscale,1.f,1.f, 0xFFFF0000, 1.f, 0.f },
	{ g_Player.x + g_Player.Xscale, g_Player.y + g_Player.Yscale,1.f,1.f, 0xFFFF0000, 1.f, 1.f },
	{ g_Player.x - g_Player.Xscale, g_Player.y + g_Player.Yscale,1.f,1.f, 0xFFFF0000, 0.f, 1.f },
	};

	CUSTOMVERTEX Boss1[4]
	{
	{ g_Boss1.x - g_Boss1.Xscale, g_Boss1.y - g_Boss1.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_Boss1.x + g_Boss1.Xscale, g_Boss1.y - g_Boss1.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_Boss1.x + g_Boss1.Xscale, g_Boss1.y + g_Boss1.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_Boss1.x - g_Boss1.Xscale, g_Boss1.y + g_Boss1.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 1.f },
	};
	
	CUSTOMVERTEX BossLEFT[4]
	{
	{ g_BossLEFT.x - g_BossLEFT.Xscale, g_BossLEFT.y - g_BossLEFT.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_BossLEFT.x + g_BossLEFT.Xscale, g_BossLEFT.y - g_BossLEFT.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_BossLEFT.x + g_BossLEFT.Xscale, g_BossLEFT.y + g_BossLEFT.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_BossLEFT.x - g_BossLEFT.Xscale, g_BossLEFT.y + g_BossLEFT.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 1.f },
	};

	CUSTOMVERTEX BossRIGHT[4]
	{
		{ g_BossRIGHT.x - g_BossRIGHT.Xscale, g_BossRIGHT.y - g_BossRIGHT.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_BossRIGHT.x + g_BossRIGHT.Xscale, g_BossRIGHT.y - g_BossRIGHT.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_BossRIGHT.x + g_BossRIGHT.Xscale, g_BossRIGHT.y + g_BossRIGHT.Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_BossRIGHT.x - g_BossRIGHT.Xscale, g_BossRIGHT.y + g_BossRIGHT.Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 1.f },
	};


	//画面の消去
	g_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);


	//描画の開始
	g_pD3Device->BeginScene();
	
	if (lowflag == false)
	{
		g_pD3Device->SetTexture(0, g_pTexture[BG_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background, sizeof(CUSTOMVERTEX));
	}
	else
	{
		g_pD3Device->SetTexture(0, g_pTexture[BG2_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background, sizeof(CUSTOMVERTEX));

	}
	
	g_pD3Device->SetTexture(0, g_pTexture[UI1_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background2, sizeof(CUSTOMVERTEX));
	if (playerflag >= 2)
	{
		g_pD3Device->SetTexture(0, g_pTexture[UI2_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background2, sizeof(CUSTOMVERTEX));
	}
	if (playerflag >= 3)
	{
		g_pD3Device->SetTexture(0, g_pTexture[UI3_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background2, sizeof(CUSTOMVERTEX));
	}
	if (lowpoint == 30)
	{
		g_pD3Device->SetTexture(0, g_pTexture[UI4_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background2, sizeof(CUSTOMVERTEX));
	}




	if (Bossflag == 1)
	{
		switch (tonboflag)
		{
		case 0:
			g_pD3Device->SetTexture(0, g_pTexture[BOSS1_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Boss1, sizeof(CUSTOMVERTEX));
			break;
		case 1:
			g_pD3Device->SetTexture(0, g_pTexture[BOSS1R_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Boss1, sizeof(CUSTOMVERTEX));
			break;
		case 2:
			g_pD3Device->SetTexture(0, g_pTexture[BOSS1L_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Boss1, sizeof(CUSTOMVERTEX));
			break;
		}
	}
		if (Bossflag == 2)
		{

			g_pD3Device->SetTexture(0, g_pTexture[BOSS2_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Boss1, sizeof(CUSTOMVERTEX));


			g_pD3Device->SetTexture(0, g_pTexture[BOSS2_RIGHT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, BossRIGHT, sizeof(CUSTOMVERTEX));


			g_pD3Device->SetTexture(0, g_pTexture[BOSS2_LEFT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, BossLEFT, sizeof(CUSTOMVERTEX));
		}

		if (Bossflag == 3)
		{

			g_pD3Device->SetTexture(0, g_pTexture[BOSS3_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Boss1, sizeof(CUSTOMVERTEX));

		}
	

	if (PEjudg == false)
	{
		switch (playerflag)
		{
		case 0:
			scene = GAMEOVER;
			
		break;

		case 1:
			g_pD3Device->SetTexture(0, g_pTexture[PLAYER3_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
			break;
		case 2:
			g_pD3Device->SetTexture(0, g_pTexture[PLAYER2_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
			break;
		case 3:
			g_pD3Device->SetTexture(0, g_pTexture[PLAYER1_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
			break;
		}

		if (muteki < 230 * 4)
		{
			g_pD3Device->SetTexture(0, g_pTexture[MUTEKI_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Muteki, sizeof(CUSTOMVERTEX));
		}
	}
	else
	{
		g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, player, sizeof(CUSTOMVERTEX));
	}
	if ( Bossflag == 1)
		{
		for (int Bshot = 0; Bshot < 5; Bshot++)
		{
				CUSTOMVERTEX Bossshot[4]
				{
				{ g_BShot[Bshot].x - g_BShot[Bshot].Xscale,  g_BShot[Bshot].y - g_BShot[Bshot].Yscale,1.f,1.f, 0xFF0000FF, 0.f, 0.f },
				{ g_BShot[Bshot].x + g_BShot[Bshot].Xscale,  g_BShot[Bshot].y - g_BShot[Bshot].Yscale,1.f,1.f, 0xFF0000FF, 1.f, 0.f },
				{ g_BShot[Bshot].x + g_BShot[Bshot].Xscale, g_BShot[Bshot].y + g_BShot[Bshot].Yscale ,1.f,1.f, 0xFF0000FF, 1.f, 1.f },
				{ g_BShot[Bshot].x - g_BShot[Bshot].Xscale, g_BShot[Bshot].y + g_BShot[Bshot].Yscale ,1.f,1.f, 0xFF0000FF, 0.f, 1.f },
				};
			switch (Bshot)
			{

			case 0:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot, sizeof(CUSTOMVERTEX));
				break;

			case 1:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot, sizeof(CUSTOMVERTEX));
				break;
			case 2:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot, sizeof(CUSTOMVERTEX));
				break;
			case 3:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot, sizeof(CUSTOMVERTEX));
				break;
			case 4:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot, sizeof(CUSTOMVERTEX));
				break;
			

			}

		}
	}

	if (Bossflag == 3)
	{
		for (int Bshot = 0; Bshot < 5; Bshot++)
		{
			CUSTOMVERTEX Bossshot2[4]
			{
			{ g_Boss1.x - g_BShot[Bshot].Xscale, g_Boss1.y + 100 - g_BShot[Bshot].Yscale,1.f,1.f, 0xFF0000FF, 0.f, 0.f },
			{ g_Boss1.x + g_BShot[Bshot].Xscale, g_Boss1.y + 100 - g_BShot[Bshot].Yscale,1.f,1.f, 0xFF0000FF, 1.f, 0.f },
			{ g_BShot[Bshot].x + g_BShot[Bshot].Xscale, g_BShot[Bshot].y + g_BShot[Bshot].Yscale - 80,1.f,1.f, 0xFF0000FF, 1.f, 1.f },
			{ g_BShot[Bshot].x - g_BShot[Bshot].Xscale, g_BShot[Bshot].y + g_BShot[Bshot].Yscale - 80,1.f,1.f, 0xFF0000FF, 0.f, 1.f },
			};

			switch (Bshot)
			{

			case 0:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot2, sizeof(CUSTOMVERTEX));
				break;

			case 1:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot2, sizeof(CUSTOMVERTEX));
				break;
			case 2:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot2, sizeof(CUSTOMVERTEX));
				break;
			case 3:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot2, sizeof(CUSTOMVERTEX));
				break;
			case 4:
				g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Bossshot2, sizeof(CUSTOMVERTEX));
				break;


			}
		}
	}
	
	for (int i = 0; i <ENEMY_MAX ; i++)
	{
		CUSTOMVERTEX enemy[4]
		{
			{ g_Enemy[i].x - g_Enemy[i].Xscale, g_Enemy[i].y - g_Enemy[i].Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_Enemy[i].x + g_Enemy[i].Xscale, g_Enemy[i].y - g_Enemy[i].Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_Enemy[i].x + g_Enemy[i].Xscale, g_Enemy[i].y + g_Enemy[i].Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_Enemy[i].x - g_Enemy[i].Xscale, g_Enemy[i].y + g_Enemy[i].Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 1.f },
		};
		switch (i)
		{
		case 0:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_ATTACK_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}

			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}
			break;

		case 1:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_ATTACK_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}
			break;
		case 2:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_ATTACK_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));

			}
			break;

		case 3:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_ATTACK_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}

			break;
		case 4:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{
					
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHIELD_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}

			break;
		case 5:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{

					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHIELD_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}

			break;
		case 6:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{

					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHIELD_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}

			break;
		case 7:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{

					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHIELD_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}

			break;
		case 8:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3 || EP == 0)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_ATTACK_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}

			break;
		case 9:
			if (SEjudg[i] == false)
			{
				if (EP == 1)
				{
					g_pD3Device->SetTexture(0, g_pTexture[TONBO_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
				if (EP == 3||EP==0)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_ATTACK_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
				}
			}
			else
			{
				g_pD3Device->SetTexture(0, g_pTexture[DETH_TEX]);
				g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemy, sizeof(CUSTOMVERTEX));
			}

			break;
		}
	}
		for (int Eshot = 0; Eshot < E_MAX_SHOT; Eshot++)
		{
			CUSTOMVERTEX EshotA[4]
			{
				{ g_EShot[Eshot].x - g_EShot[Eshot].Xscale, g_EShot[Eshot].y - g_EShot[Eshot].Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ g_EShot[Eshot].x + g_EShot[Eshot].Xscale, g_EShot[Eshot].y - g_EShot[Eshot].Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ g_EShot[Eshot].x + g_EShot[Eshot].Xscale, g_EShot[Eshot].y + g_EShot[Eshot].Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ g_EShot[Eshot].x - g_EShot[Eshot].Xscale, g_EShot[Eshot].y + g_EShot[Eshot].Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 1.f },
			};

			switch (Eshot)
			{
			case 0:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				break;

			case 1:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 2:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 3:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 4:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 5:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 6:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 7:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 8:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 9:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 10:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 11:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			case 12:
				if (EP == 2)
				{
					g_pD3Device->SetTexture(0, g_pTexture[MANTIS_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}
				if (EP == 0 || EP == 3)
				{
					g_pD3Device->SetTexture(0, g_pTexture[BEE_SHOT_TEX]);
					g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, EshotA, sizeof(CUSTOMVERTEX));
				}break;
			}
		}
	



	for (int Pshot = 0; Pshot <P_MAX_SHOT; Pshot++)
	{
		CUSTOMVERTEX PshotA[4]
		{
			{ g_PShot[Pshot].x - g_PShot[Pshot].Xscale, g_PShot[Pshot].y - g_PShot[Pshot].Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_PShot[Pshot].x + g_PShot[Pshot].Xscale, g_PShot[Pshot].y - g_PShot[Pshot].Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_PShot[Pshot].x + g_PShot[Pshot].Xscale, g_PShot[Pshot].y + g_PShot[Pshot].Yscale,1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_PShot[Pshot].x - g_PShot[Pshot].Xscale, g_PShot[Pshot].y + g_PShot[Pshot].Yscale,1.f,1.f, 0xFFFFFFFF, 0.f, 1.f },
		};

		switch (Pshot)
		{
		case 0:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;

		case 1:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 2:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 3:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 4:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 5:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 6:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 7:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 8:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 9:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 10:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 11:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 12:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 13:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		case 14:
			g_pD3Device->SetTexture(0, g_pTexture[SHOT_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, PshotA, sizeof(CUSTOMVERTEX));
			break;
		}
	}



	sprintf_s(Score, 255, "%d", Scorepoint);
	MainFont->DrawText(
		NULL,							// NULL
		Score,				// 描画テキスト
		-1,								// 全て表示
		&SCOREPOINT,							// 表示範囲
		DT_CENTER,     // 左寄せ
		D3DCOLOR_ARGB(0xff, 0xff, 0x00, 0x00)// 赤色
	);




	//描画の終了
	g_pD3Device->EndScene();

	//表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
}
