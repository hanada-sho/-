#include"main.h"
#include"gameover.h"

RECT RESULTSCOREPOINT =
{
	520,
	280,
	1020,
	380,
};
void gameovercontrol()
{

	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), diks);

		XINPUT_STATE xinput;
		XInputGetState(0, &xinput);

		//ENTERキーでメインゲームに行く
		if (!(prevDiks[DIK_RETURN]))
		{
			if ((diks[DIK_RETURN] & 0x80) || xinput.Gamepad.wButtons & XINPUT_GAMEPAD_B)
			{
				format();
				scene = MAINGAME;
			}
		}
		prevDiks[DIK_RETURN] = diks[DIK_RETURN] & 0x80;
	}


}

void GameOverRender()
{
	//頂点情報を入れる--------------------------------------
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,   0.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1550.f, 0.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1550.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//画面の消去
	g_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//描画の開始
	g_pD3Device->BeginScene();

	g_pD3Device->SetTexture(0, g_pTexture[GAMEOVER_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	sprintf_s(Score, 255, "%d", Scorepoint);
	MainFont->DrawText(
		NULL,							// NULL
		Score,				// 描画テキスト
		-1,								// 全て表示
		&RESULTSCOREPOINT,							// 表示範囲
		DT_CENTER,     // 左寄せ
		D3DCOLOR_ARGB(0xff, 0xff, 0x00, 0x00)// 赤色
	);


	//描画の終了
	g_pD3Device->EndScene();

	//表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
}