#include"main.h"
#include"title.h"


int prevDiks[256];
int scene = TITLE;
bool titlescrol = false;
int pressEntercount = 0;
float titleScrolY = 800;

void TitleControl()
{
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), diks);

		XINPUT_STATE xinput;
		XInputGetState(0, &xinput);

		//ENTERキーで機体選択画面に行く
		if (!(prevDiks[DIK_RETURN]))
		{
			if ((diks[DIK_RETURN] & 0x80 || xinput.Gamepad.wButtons & XINPUT_GAMEPAD_B))
			{
				scene = SELECT;
			}
		}
		prevDiks[DIK_RETURN] = diks[DIK_RETURN] & 0x80;
	}
}


void TitleRender()
{
	//頂点情報を入れる--------------------------------------
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,   0.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1550.f, 0.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1550.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CUSTOMVERTEX pressEnter[4]
	{
		{ 407.f,   600.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1113.f, 600.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1113.f, 632.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 407.f, 632.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CUSTOMVERTEX titleScrol[4]
	{
		{ 0.f,   titleScrolY, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1550.f, titleScrolY, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1550.f, titleScrolY + 800.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, titleScrolY + 800.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//画面の消去
	g_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//描画の開始
	g_pD3Device->BeginScene();

	if (titlescrol == true)
	{
		pressEntercount++;

		g_pD3Device->SetTexture(0, g_pTexture[TITLE_BG_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

		if (pressEntercount % 60 <= 30)
			g_pD3Device->SetTexture(0, g_pTexture[PRESS_ENTER_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, pressEnter, sizeof(CUSTOMVERTEX));
	}
	if (titlescrol == false)
	{
		g_pD3Device->SetTexture(0, g_pTexture[TITLE_SCROL_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, titleScrol, sizeof(CUSTOMVERTEX));

		titleScrolY -= 1.f;

		if (titleScrolY <= -800)
		{
			titlescrol = true;
		}
	}

	//描画の終了
	g_pD3Device->EndScene();

	//表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
}