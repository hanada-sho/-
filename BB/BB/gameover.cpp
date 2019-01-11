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

		//ENTER�L�[�Ń��C���Q�[���ɍs��
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
	//���_��������--------------------------------------
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,   0.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1550.f, 0.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1550.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 800.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//��ʂ̏���
	g_pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);

	//�`��̊J�n
	g_pD3Device->BeginScene();

	g_pD3Device->SetTexture(0, g_pTexture[GAMEOVER_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	sprintf_s(Score, 255, "%d", Scorepoint);
	MainFont->DrawText(
		NULL,							// NULL
		Score,				// �`��e�L�X�g
		-1,								// �S�ĕ\��
		&RESULTSCOREPOINT,							// �\���͈�
		DT_CENTER,     // ����
		D3DCOLOR_ARGB(0xff, 0xff, 0x00, 0x00)// �ԐF
	);


	//�`��̏I��
	g_pD3Device->EndScene();

	//�\��
	g_pD3Device->Present(NULL, NULL, NULL, NULL);
}