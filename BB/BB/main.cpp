#include"main.h"
#include"Enemy.h"
#include"Player.h"
#include"Render.h"
#include"Result.h"
#include"title.h"
#include"select.h"
#include"judg.h"
#include"deth.h"
#include"Boss.h"
#include"gameover.h"
#include"gameclear.h"
LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為のポインタ配列
IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
D3DDISPLAYMODE		  g_D3DdisplayMode;
IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス
LPDIRECTINPUT8 pDinput = NULL;
LPDIRECTINPUTDEVICE8 pKeyDevice = NULL;
HRESULT InitD3d(HWND);
HRESULT InitDinput(HWND);										//------------------------------------
LPD3DXFONT MainFont;
DRAW_STATE g_Player = { 450.f, 600.f, 30.f ,30.f,15.f,15.f };
DRAW_STATE g_Boss1 = { 450.f, -200.f, 100.f ,100.f,70.f,70.f };
DRAW_STATE g_BossRIGHT = { 300.f, -200.f, 100.f ,100.f,70.f,70.f };
DRAW_STATE g_BossLEFT = { 600.f, -200.f, 100.f ,100.f,70.f,70.f };
DRAW_STATE g_Enemy[ENEMY_MAX];
DRAW_STATE g_PShot[P_MAX_SHOT];
DRAW_STATE g_BShot[5];
DRAW_STATE g_EShot[E_MAX_SHOT];


bool ikkaidaketooru = false;
bool regen = true;
char Score[255];
int Scorepoint=0;
int lowpoint=30;
int muteki = 240 * 4;
int playerflag = 3;
int realcount = 0;
bool one = true;
bool onet = true;
int rate = 10;
bool lowflag = false;

void format()
{

	 ikkaidaketooru = false;
	 regen = true;
	 Score[255];
	Scorepoint = 0;
	lowpoint = 30;
	muteki = 240 * 4;
	playerflag = 3;
	realcount = 0;
	 one = true;
	 onet = true;
	rate = 10;
	 lowflag = false;
	bosspaturncount = 0;
	bosspaturnflag = 0;
	Bossflag = 0;
	BossHp = 50;
	tonboflag = 0;
	 Eshotflag = false;
	 EnemySpeed = 10.f;
	  EP = 1;
	 PEjudg = false;
	 Pshotslow = false;
	  Pshotflag = false;
	 tv = 0;
	ArrowCount = 0;
	SelectArrowPosition = 1;
	prevDiks[256];
	 titlescrol = false;
	pressEntercount = 0;
	 titleScrolY = 800;
	 g_Player = { 450.f, 600.f, 30.f ,30.f,15.f,15.f };
	 g_Boss1 = { 450.f, -200.f, 100.f ,100.f,70.f,70.f };
	 g_BossRIGHT = { 300.f, -200.f, 100.f ,100.f,70.f,70.f };
	 g_BossLEFT = { 600.f, -200.f, 100.f ,100.f,70.f,70.f };
	 EShotSpeed = 0.f;

}

void timecontrol()
{
	if (realcount == 1200)
	{
		realcount += 1;
			Bossflag = 1;
			g_Boss1.y = 200;
			g_BShot[0] = { 450.f, -300.f, 20.f ,20.f,20.f,30.f };
			g_BShot[1] = { 450.f, -300.f, 20.f ,20.f,20.f,30.f };
			g_BShot[2] = { 450.f, -300.f, 20.f ,20.f,20.f,30.f };
			EP = 0;
			enemyInit();
	}
	if (realcount == 3600)
	{
		realcount += 1;
		BossHp = 150;
		Bossflag = 2;
		g_Boss1 = { 450.f, 200.f, 300.f ,150.f,80.f,100.f };
		g_BossRIGHT.y = 250;
		g_BossLEFT.y = 250;
		EP = 0;
		enemyInit();

	}
	if (realcount == 7200)
	{
		
		realcount += 1;
		BossHp = 400;
		Bossflag = 3;
		g_Boss1 = { 450.f, 200.f, 100.f ,100.f,70.f,70.f };
		EP = 0;
		enemyInit();
	}
}

void keyControl()
{
	//キーボードで押されているキーを調べ、対応する方向に移動させる
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), &diks);
		static int count;
		
		count++;
		{
			if (PEjudg == false)
			{
				if (diks[DIK_LEFT] & 0x80 && (g_Player.x - g_Player.Xscale) > 128.f)
				{
					g_Player.x -= MOVE_SPEED;
				}
				if (diks[DIK_RIGHT] & 0x80 && (g_Player.x + g_Player.Xscale) < WIDTH)
				{
					g_Player.x += MOVE_SPEED;
				}
				if (diks[DIK_UP] & 0x80  && (g_Player.y - g_Player.Yscale) > 28.f)
				{
					g_Player.y -= MOVE_SPEED;
				}
				if (diks[DIK_DOWN] & 0x80  && (g_Player.y + g_Player.Yscale) < HIGHT - 45)
				{
					g_Player.y += MOVE_SPEED;
				}
				if (diks[DIK_SPACE] & 0x80  && count % rate == 0)
				{
					Pshotflag = true;
				}
				else
				{
					Pshotflag = false;
				}
			}
			if (count % 20 == 0)
			{
				Eshotflag = true;
			}
			else if (count %20 != 0)
			{
				Eshotflag = false;
			}
			
			
			if (diks[DIK_A] & 0x80 &&lowpoint==30)
			{
				lowflag = true;	
			}
			
		}
	}
}

void lowskill()
{
	if (lowflag)
	{
		static int lowcount = 0;
		rate = 7;
		EShotSpeed = 200.f;
		Eshotflag = false;
		lowcount++;
		lowpoint -= lowcount / 7;//7フレごとに、１になる。
		if (lowcount == 7)//lowcountのリセット
		{
			lowcount = 0;
		}
		regen = false;
		EnemySpeed = 0.3f;
		Pshotslow = true;
		scrollspeed = 0.001f;
		if (lowpoint == 0)
		{
			lowflag = false;
		}
	}
	else
	{
		rate = 10;
		scrollspeed = 0.003f;
		Pshotslow = false;
		EShotSpeed = 60.f;
		EnemySpeed = 2.5f;
		regen = true;
	}

}

void AllJudgcontrol()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		for (int j = 0; j < P_MAX_SHOT; j++)
		{
			for (int k = 0; k < E_MAX_SHOT; k++)
			{
				hitjudg(g_PShot[j].x, g_PShot[j].Xscale, g_Enemy[i].x, g_Enemy[i].Xjudg, g_PShot[j].y, g_PShot[j].Yscale, g_Enemy[i].y, g_Enemy[i].Yjudg, g_Player.x, g_Player.Xjudg, g_Player.y, g_Player.Yjudg, i, j, g_EShot[k]);
				for (int l = 0; l < 6; l++)
				{
					hitjudgB(g_PShot[j].x, g_PShot[j].Xscale, g_Boss1.x, g_Boss1.Xjudg, g_PShot[j].y, g_PShot[j].Yscale, g_Boss1.y, g_Boss1.Yjudg, g_Player.x, g_Player.Xjudg, g_Player.y, g_Player.Yjudg, i, j, g_BShot[l]);
					judg3(g_Player.x, g_Player.Xjudg, g_BossLEFT.x, g_BossLEFT.Xjudg, g_Player.y, g_Player.Yjudg, g_BossLEFT.y, g_BossLEFT.Yjudg);
					judg3(g_Player.x, g_Player.Xjudg, g_BossRIGHT.x, g_BossRIGHT.Xjudg, g_Player.y, g_Player.Yjudg, g_BossRIGHT.y, g_BossRIGHT.Yjudg);
				}
			}
		}
		dethcontrol(i);
	}
}

void Regen()
{
	static int lowc = 0;
	if (regen == true)
	{
		lowc++;
		if (lowpoint <= 30)
		{
			lowpoint += lowc / 30;//30フレームで1回復する
			if (lowc == 30)
			{
				lowc = 0;
			}
		}
	}
	if (lowpoint > 30)//100以上回復しない。
	{
		lowpoint = 30;
	}
	if (lowpoint < 0)//0以下にならないようにする。
	{
		lowpoint = 0;
	}
}



/**
*メッセージ処理
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}
HRESULT InitDinput(HWND hWnd)
{
	HRESULT hr;
	//directinputオブジェクトの作成
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDinput, NULL)))
	{
		return hr;
	}
	//directinputデバイスオブジェクトの作成
	if (FAILED(hr = pDinput->CreateDevice(GUID_SysKeyboard,
		&pKeyDevice, NULL)))
	{
		return hr;
	}

	//デバイスをキーボードに設定
	if (FAILED(hr = pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}
	//協調レベルの設定
	if (FAILED(hr = pKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}
	pKeyDevice->Acquire();
	return S_OK;
}
/**
*オブジェクトの開放
*/
void FreeDx()
{
	for (int i = 0; i <= TEXMAX; i++)
	{
		SAFE_RELEASE(g_pTexture[i]);
	}
	SAFE_RELEASE(g_pD3Device);
	SAFE_RELEASE(g_pDirect3D);
	SAFE_RELEASE(pDinput);
	if (pKeyDevice)
	{
		pKeyDevice->Unacquire();
	}
	SAFE_RELEASE(pKeyDevice);
	SAFE_RELEASE(MainFont);
}
/**
*メインルーチン
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{

	MSG msg;
	WNDCLASS Wndclass;
	HWND hWnd;

	//Windows情報の設定
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TEXT("AAAA");	//クラス名
											//Windowの登録
	RegisterClass(&Wndclass);
	//Windowの生成
	hWnd = CreateWindow(
		TEXT("AAAA"),								//ウィンドウのクラス名
		TEXT("ビートル"), 							//ウィンドウのタイトル
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,	//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x
		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		DISPLAY_WIDTH,							// Width（幅）
		DISPLAY_HIGHT,							// Height（高さ）
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
	);
	if (!hWnd) return 0;

	//DirectX オブジェクトの生成
	g_pDirect3D = Direct3DCreate9(
		D3D_SDK_VERSION);

	//directinputの初期化関数を呼ぶ
	if (FAILED(InitDinput(hWnd)))
	{
		return 0;
	}

	//Display Mode の設定
	g_pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&g_D3DdisplayMode);

	ZeroMemory(&g_D3dPresentParameters,
		sizeof(D3DPRESENT_PARAMETERS));
	g_D3dPresentParameters.BackBufferFormat = g_D3DdisplayMode.Format;
	g_D3dPresentParameters.BackBufferCount = 1;
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_D3dPresentParameters.Windowed = TRUE;

	//デバイスを作る
	g_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3Device);

	//描画設定
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	//頂点に入れるデータを設定
	g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);


	D3DXCreateTextureFromFile(
		g_pD3Device,
		"text3.png",
		&g_pTexture[PLAYER3_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"text2.png",
		&g_pTexture[PLAYER2_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"came_cleared.png",
		&g_pTexture[CLEAR_TEX]);


	D3DXCreateTextureFromFile(
		g_pD3Device,
		"text.png",
		&g_pTexture[PLAYER1_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"stage1.png",
		&g_pTexture[BG_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"ui_main.png",
		&g_pTexture[UI1_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"ui_main_life2.png",
		&g_pTexture[UI2_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"ui_main_life3.png",
		&g_pTexture[UI3_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"ui_main_on.png",
		&g_pTexture[UI4_TEX]);




	D3DXCreateTextureFromFile(
		g_pD3Device,
		"shot.png",
		&g_pTexture[SHOT_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"mitubachi.png",
		&g_pTexture[ENEMY_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"bee_shield.png",
		&g_pTexture[BEE_SHIELD_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"bee_gunner.png",
		&g_pTexture[BEE_GUNNER_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"bee_attack.png",
		&g_pTexture[BEE_ATTACK_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss2_arm_left.png",
		&g_pTexture[BOSS2_RIGHT_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss2_arm_right.png",
		&g_pTexture[BOSS2_LEFT_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss2.png",
		&g_pTexture[BOSS2_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"stage_3.png",
		&g_pTexture[BG2_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"deth.png",
		&g_pTexture[DETH_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"push_enterkey.png",
		&g_pTexture[PRESS_ENTER_TEX]);


	D3DXCreateTextureFromFile(
		g_pD3Device,
		"b7.png",
		&g_pTexture[MANTIS_SHOT_TEX]);


	D3DXCreateTextureFromFile(
		g_pD3Device,
		"b17.png",
		&g_pTexture[BEE_SHOT_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"title.png",
		&g_pTexture[TITLE_BG_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"aircraft_choose.png",
		&g_pTexture[SELECT_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"result.png",
		&g_pTexture[RESULT_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"titlescrol.png",
		&g_pTexture[TITLE_SCROL_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"muteki.png",
		&g_pTexture[MUTEKI_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"gameover.png",
		&g_pTexture[GAMEOVER_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"mantis_small.png",
		&g_pTexture[MANTIS_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"dragonfly_small.png",
		&g_pTexture[TONBO_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss1.png",
		&g_pTexture[BOSS1_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss1R.png",
		&g_pTexture[BOSS1R_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss1L.png",
		&g_pTexture[BOSS1L_TEX]);


	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss3.png",
		&g_pTexture[BOSS3_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"boss4.png",
		&g_pTexture[BOSS4_TEX]);


	D3DXCreateTextureFromFile(
		g_pD3Device,
		"cursor.png",
		&g_pTexture[ARROW_TEX]);


	D3DXCreateTextureFromFile(
		g_pD3Device,
		"push_enterkey.png",
		&g_pTexture[PRESS_ENTER_TEX]);



	//フォントオブジェクトの作成
	D3DXCreateFont(
		g_pD3Device,				// Direct3Dデバイス
		40,						// 高さ
		25,							// 幅
		FW_BLACK,					// フォントの太さ 普通
		NULL,						// 下線
		FALSE,						// 斜体
		DEFAULT_CHARSET,			// 文字セット
		OUT_DEFAULT_PRECIS,			// 出力制度は普通
		DEFAULT_QUALITY,			// 文字品質を重視
		FIXED_PITCH | FF_SCRIPT,	// ピッチとファミリ
		TEXT("venus rising"),		// フォント名
		&MainFont);


	DWORD SyncOld = timeGetTime();	//	システム時間を取得
	DWORD SyncNow;

	timeBeginPeriod(1);
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) //	1秒間に60回この中に入るはず
			{
				switch (scene)
				{
				case TITLE:
					TitleRender();
					TitleControl();
					break;
				case SELECT:
					SelectRender();
					SelectControl();
					break;
				case MAINGAME:
					if (EP != 0)
					{
						realcount++;
					}
					keyControl();
					if (ikkaidaketooru == false)
					{
						enemyInit();
						PlayerInit();
						Bossinit();
						ikkaidaketooru = true;
					}

					P_ShotControl();
					E_ShotControl();
					AllJudgcontrol();
					timecontrol();
					for (int i = 0; i < 4; i++)
					{
						switch (EP)
						{
						case 1:
							enemymove1();
							break;
						case 2:

							if (one)
							{
								g_Enemy[0] = { 180.f,-400.f,50.f,50.f,25.f,25.f };
								g_Enemy[1] = { 180.f,-100.f,50.f,50.f,25.f,25.f };
								g_Enemy[2] = { 720.f,-100.f,50.f,50.f,25.f,25.f };
								g_Enemy[3] = { 720.f,-400.f,50.f,50.f,25.f,25.f };
								for (int i = 0; i < 4; i++)
								{
									enemy2right[i] = false;
									enemy2left[i] = false;
								}

								one = false;
							}
							enemymove2();
							break;
						case 3:
							EnemyMove(i);
							break;
						}
					}
					if (Bossflag == 1)
					{
						if (BossHp <= 0)
						{
							Bossflag = 0;
							EP = 2;
							Eshotflag = true;
							g_Boss1.y = -500;
							bosspaturncount = 0;
							bosspaturnflag = 0;
							Scorepoint += 5000;
						}
						ALLtonbo();
					}
						if (Bossflag == 2)
						{
							if (BossHp <= 0)
							{
								Bossflag = 0;
								EP = 3;
								Eshotflag = true;
								g_Boss1.y = -500;
								g_BossRIGHT.y = -500;
								g_BossLEFT.y = -500;
								bosspaturncount = 0;
								bosspaturnflag = 0;
								Scorepoint += 10000;
							}
							ALLkamakiri();
							
						}
						if (Bossflag == 3)
						{
							if (BossHp <= 0)
							{
								Bossflag = 0;
								EP = 0;
								Eshotflag = true;
								g_Boss1.y = -500;
								bosspaturncount = 0;
								bosspaturnflag = 0;
								Scorepoint += 20000;
								scene = GAMECLEAR;
							}
							ALLmitubati();
						}

						lowskill();
						Regen();
						scroll();
						Render();
						break;
				case GAMEOVER:
					gameovercontrol();
					GameOverRender();
					break;
				case GAMECLEAR:
						gameclearcontrol();
						GameclearRender();
						break;
				case RESULT:
					ResultRender();
					ResultControl();
					break;
					}
					SyncOld = SyncNow;
				}
			}
		}
		timeEndPeriod(1);
		FreeDx();
		return (int)msg.wParam;
	}


	void ALLtonbo()
	{
		switch (bosspaturnflag)
		{
		case 0:
			
			enemyInit();
			if (bosspaturncount == 119)
			{
				bosspaturnflag = 1;
			}
			break;
		case 1:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 180.f;
				g_Boss1.y = g_Player.y;
			}

			tonbomove2();
			if (g_Boss1.x > 720)
			{
				bosspaturncount = 239;
				bosspaturnflag = 2;
			}
			break;
		case 2:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 720.f;
				g_Boss1.y = g_Player.y;
			}
			tonbomove3();
			if (g_Boss1.x < 180)
			{
				bosspaturncount = 360 - 1;
				bosspaturnflag = 3;
			}
			break;
		case 3:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 180.f;
				g_Boss1.y = g_Player.y;
			}
			tonbomove2();
			if (g_Boss1.x > 720)
			{
				bosspaturncount = 480 - 1;
				bosspaturnflag = 4;
			}
			break;
		case 4:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 700.f;
				g_Boss1.y = g_Player.y;
			}
			tonbomove3();
			if (g_Boss1.x < 180)
			{
				bosspaturncount = 600 - 1;
				bosspaturnflag = 5;
			}
			break;
		case 5:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 180.f;
				g_Boss1.y = g_Player.y;
			}
			tonbomove2();
			if (g_Boss1.x > 720)
			{
				bosspaturncount = 720 - 1;
				bosspaturnflag = 6;
			}
			break;
		case 6:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 700.f;
				g_Boss1.y = g_Player.y;
			}
			tonbomove3();
			if (g_Boss1.x < 180)
			{
				bosspaturncount = 840 - 1;
				bosspaturnflag = 7;
			}
			break;
		case 7:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 180.f;
				g_Boss1.y = g_Player.y;
			}
			tonbomove2();
			if (g_Boss1.x > 720)
			{
				bosspaturncount = 960 - 1;
				bosspaturnflag = 8;
			}
			break;
		case 8:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = 700.f;
				g_Boss1.y = g_Player.y;

			}
			tonbomove3();
			if (g_Boss1.x < 180)
			{
				bosspaturncount = 1080 - 1;
				bosspaturnflag = 9;
			}

			break;
		case 9:
			if (bosspaturncount == 120 * bosspaturnflag)
			{
				g_Boss1.x = g_Player.x;
				g_Boss1.y = -200;
			}
			tonbomove1();
			if (g_Boss1.y > WIDTH)
			{
				bosspaturncount = 1200 - 1;
				bosspaturnflag = 10;
			}
			break;
		case 10:
			g_Boss1.y = -200;
			EP = 2;
			Bossflag = 0;
			bosspaturnflag=0;
			break;
		};

		bosspaturncount += 1;



	
}

void ALLkamakiri()
{
	
	static bool one = true;
	if (one)
	{
		bosspaturnflag = 0;
		bosspaturncount = 0;
		one = false;
	}
	switch (bosspaturnflag)
	{
	case 0:
		kamakirimove(0, 600, 250);
		break;
	case 1:
		kamakirimove2(1, 300, 250);
		break;
	
	};
	bosspaturncount += 1;
}

void ALLmitubati()
{
	bosspaturnflag = bosspaturncount / 120;
	switch (bosspaturnflag)
	{
	case 0:
	
		g_Enemy[0] = { 180.f,-200.f,50.f,50.f,25.f,25.f };
		g_Enemy[1] = { 360.f,-100.f,50.f,50.f,25.f,25.f };
		g_Enemy[2] = { 540.f,-100.f,50.f,50.f,25.f,25.f };
		g_Enemy[3] = { 720.f,-200.f,50.f,50.f,25.f,25.f };
		break;
	case 1:
	
		if (onet)
		{
			g_BShot[0] = { g_Boss1.x, -g_Boss1.y + 100, 20.f ,40.f,20.f,30.f };
			g_BShot[1] = { g_Boss1.x, -g_Boss1.y + 100, 20.f ,40.f,20.f,30.f };
			g_BShot[2] = { g_Boss1.x, -g_Boss1.y + 100, 20.f ,40.f,20.f,30.f };
			onet = false;
		}
		BossMove1();
		break;
	case 2:
		Bossinit();
		break;
	case 3:
		BossMove1();
		break;
	case 4:
		Bossinit();
		break;
	case 5:
		Eshotflag = true;
		if (bosspaturncount == 600)
		{
			g_Enemy[0] = { 150.f,100.f,50.f,50.f,25.f,25.f };
			g_Enemy[1] = { 300.f,200.f,50.f,50.f,25.f,25.f };
			g_Enemy[2] = { 600.f,200.f,50.f,50.f,25.f,25.f };
			g_Enemy[3] = { 750.f,100.f,50.f,50.f,25.f,25.f };
		}
		break;
	case 6:
		if (bosspaturncount == 750)
		{
			g_Enemy[4] = { 380.f,300.f,50.f,50.f,25.f,25.f };
			g_Enemy[5] = { 430.f,300.f,50.f,50.f,25.f,25.f };
			g_Enemy[6] = { 480.f,300.f,50.f,50.f,25.f,25.f };
			g_Enemy[7] = { 530.f,300.f,50.f,50.f,25.f,25.f };
		}
		break;

	case 7:
		BossMove2();
		break;

	case 8:
		bosspaturncount = 119;
		break;
	};
	bosspaturncount += 1;
}