#include"main.h"
int ArrowCount = 0;
int SelectArrowPosition = 1;
void SelectControl()
{
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), diks);

		XINPUT_STATE xinput;
		XInputGetState(0, &xinput);

		if (diks[DIK_LEFT])
		{
			SelectArrowPosition = 1;
		}

		if (diks[DIK_RIGHT])
		{
			SelectArrowPosition = 2;
		}

		//ENTERキーでメインゲームに行く
		if (!(prevDiks[DIK_RETURN]))
		{
			if ((diks[DIK_RETURN] & 0x80) || xinput.Gamepad.wButtons & XINPUT_GAMEPAD_B)
			{
				scene = MAINGAME;
			}
		}
		prevDiks[DIK_RETURN] = diks[DIK_RETURN] & 0x80;
	}
}

void SelectRender()
{
	//頂点情報を入れる--------------------------------------
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,   0.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1550.f, 0.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1550.f, 880.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 880.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CUSTOMVERTEX ARROW1[4]
	{
		{ ARROW_LEFT1,   ARROW_TOP, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ ARROW_LEFT1 + 128, ARROW_TOP, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ ARROW_LEFT1 + 128, ARROW_TOP + 128, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ ARROW_LEFT1, ARROW_TOP + 128, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	CUSTOMVERTEX ARROW2[4]
	{
		{ ARROW_LEFT2,   ARROW_TOP, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ ARROW_LEFT2 + 128, ARROW_TOP, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ ARROW_LEFT2 + 128, ARROW_TOP + 128, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ ARROW_LEFT2, ARROW_TOP + 128, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//画面の消去
	g_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//描画の開始
	g_pD3Device->BeginScene();

	g_pD3Device->SetTexture(0, g_pTexture[SELECT_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	ArrowCount++;

	if (ArrowCount % 60 <= 30)
	{
		if (SelectArrowPosition == 1)
		{
			g_pD3Device->SetTexture(0, g_pTexture[ARROW_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ARROW1, sizeof(CUSTOMVERTEX));
		}
		else if (SelectArrowPosition == 2)
		{
			g_pD3Device->SetTexture(0, g_pTexture[ARROW_TEX]);
			g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ARROW2, sizeof(CUSTOMVERTEX));
		}
	}

	//描画の終了
	g_pD3Device->EndScene();

	//表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
}
