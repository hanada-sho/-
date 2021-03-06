
#include"main.h"
#include"result.h"
#include"render.h"


void ResultControl()
{
	HRESULT hr = pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		pKeyDevice->GetDeviceState(sizeof(diks), diks);

		XINPUT_STATE xinput;
		XInputGetState(0, &xinput);

		//ENTERキーでタイトルに行く
		if (!(prevDiks[DIK_RETURN]))
		{
			if ((diks[DIK_RETURN] & 0x80 || xinput.Gamepad.wButtons & XINPUT_GAMEPAD_B))
			{
				scene = TITLE;
			}
		}
		prevDiks[DIK_RETURN] = diks[DIK_RETURN] & 0x80;
	}
}

void ResultRender()
{
	//頂点情報を入れる--------------------------------------
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,   0.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1000.f, 0.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1000.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//画面の消去
	g_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//描画の開始
	g_pD3Device->BeginScene();

	g_pD3Device->SetTexture(0, g_pTexture[RESULT_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));


	




	//描画の終了
	g_pD3Device->EndScene();

	//表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
}