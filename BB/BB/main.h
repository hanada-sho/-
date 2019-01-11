#pragma once

#include <windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include<math.h>
#include<dinput.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<xinput.h>
#include<time.h>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define DISPLAY_WIDTH 1920
#define DISPLAY_HIGHT 1080
#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}
#define WIDTH 768.f
#define HIGHT 820.f
#define MOVE_SPEED 6
#define P_MAX_SHOT 15
#define E_MAX_SHOT 12
#define ENEMY_MAX 10
#define ENEMY_NUMBER 10
#define VIBRATION_TIME 60
#define ARROW_LEFT1 110
#define ARROW_LEFT2 730
#define ARROW_TOP 450

#pragma comment(lib,"winmm")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"Xinput.lib")


enum SCENE
{
	TITLE,
	SELECT,
	MAINGAME,
	GAMEOVER,
	GAMECLEAR,
	RESULT,
};

enum TEXTURE
{
	BACKGROUND_TEX,
	PLAYER1_TEX,
	PLAYER2_TEX,
	PLAYER3_TEX,
	CLEAR_TEX,
	BG_TEX,
	BG2_TEX,
	BEE_SHOT_TEX,
	MANTIS_SHOT_TEX,
	SHOT_TEX,
	ENEMY_TEX,
	DETH_TEX,
	TITLE_BG_TEX,
	SELECT_TEX,
	RESULT_TEX,
	TITLE_SCROL_TEX,
	MUTEKI_TEX,
	BEE_SHIELD_TEX,
	BEE_GUNNER_TEX,
	BEE_ATTACK_TEX,
	MANTIS_TEX,
	TONBO_TEX,
	UI1_TEX,
	UI2_TEX,
	UI3_TEX,
	UI4_TEX,
	BOSS1_TEX,
	BOSS1R_TEX,
	BOSS1L_TEX,
	BOSS2_TEX,
	BOSS2_LEFT_TEX,
	BOSS2_RIGHT_TEX,
	BOSS3_TEX,
	BOSS4_TEX,
	PRESS_ENTER_TEX,
	ARROW_TEX,
	PAUSE_TEX,
	GAMEOVER_TEX,
	TEXMAX,
};

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

struct DRAW_STATE
{
	float x, y, Xscale, Yscale, Xjudg, Yjudg, flag = 0;
};


//Directx関係----------------------------

extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	画像の情報を入れておく為のポインタ配列
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;		//	パラメータ
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern IDirect3D9*			  g_pDirect3D;		//	Direct3Dのインターフェイス
extern LPDIRECTINPUT8 pDinput ;
extern LPDIRECTINPUTDEVICE8 pKeyDevice;
extern HRESULT InitD3d(HWND);
extern HRESULT InitDinput(HWND);										//---------------------------------------
extern LPD3DXFONT MainFont;
extern DRAW_STATE g_Player;
extern DRAW_STATE g_Boss1;
extern DRAW_STATE g_BossRIGHT;
extern DRAW_STATE g_BossLEFT;
extern DRAW_STATE g_BShot[5];
extern DRAW_STATE g_Enemy[ENEMY_MAX];
extern DRAW_STATE g_PShot[P_MAX_SHOT];
extern DRAW_STATE g_EShot[E_MAX_SHOT];

extern int prevDiks[256];
extern int scene;
extern int muteki;
extern char Score[255];
extern int Scorepoint ;
extern int lowpoint ;
extern bool regen;
extern int playerflag;
extern bool lowflag;

void format();
void ALLtonbo();
void ALLmitubati();
void ALLkamakiri();