#include "Result.h"
#include "Goods.h"
#include "Main.h"
#include "GameMain.h"

enum RESULTSCENE
{
	PAGE1,
	PAGE2,
	PAGE3
};

static CENTRAL_STATE cursorResult{ 100,490,25,25 };

static bool apperText[10];
int selectedGoods[3];
static int resultPage;
static int nomalSum = 0;
static int saleSale = 0;

void resultControl(void);
void resultRenderOne(void);
void resultRenderTwo(void);
void resultRenderThree(void);
void apperResult(void);

int addPrice(int num, int nomalOrSale);


void result() 
{
	static bool isFirst = true;

	if (isFirst) {
		setNowLoading();

		SetUpFont(25, 20, DEFAULT_CHARSET, NULL, RESULT_FONT);
		SetUpFont(70, 50, DEFAULT_CHARSET, NULL, SCORE_FONT);
		SetUpFont(120, 75, DEFAULT_CHARSET, NULL, LAST_SCORE_FONT);

		ReadInTexture("Texture/result/result.png", RESULT_BG_TEX);
		ReadInTexture("Texture/result/resultLast.png", RESULT_POP_TEX);
		ReadInTexture("Texture/result/R_UI.png", RESULT_END_TEX);
		ReadInTexture("Texture/result/star1.png",RESULT_STAR1_TEX);
		ReadInTexture("Texture/result/star2.png",RESULT_STAR2_TEX);
		ReadInTexture("Texture/result/star3.png",RESULT_STAR3_TEX);
		//ReadInTexture("Texture/result/point100.png", );
		//ReadInTexture("Texture/result/point300.png", );
		//ReadInTexture("Texture/result/point500.png", );
		ReadInTexture("Texture/result/bonus.png", RESULT_COMBO_TEX);
		ReadInTexture("Texture/result/SALE.png", RESULT_SALE_TEX);
		ReadInTexture("Texture/result/price.png",RESULT_NOMAL_TEX );

		for (int i = 0; i < 3; i++)
		{
			nomalSum += addPrice(i, 0);
			saleSale += addPrice(i, 1);
		}

		g_SoundSuccess = soundsManager.Start("LOAD", false) && g_SoundSuccess;

		isFirst = false;
	}
	resultControl();
	BeginSetTexture();
	switch (resultPage)
	{
	case PAGE1:
		resultRenderOne();
		break;
	case PAGE2:
		resultRenderOne();
		resultRenderTwo();
		break;
	case PAGE3:
		resultRenderOne();
		resultRenderTwo();
		resultRenderThree();
	}
	EndSetTexture();
}

void resultControl(void)
{
	apperResult();

	CheckKeyState(DIK_RETURN);
	CheckKeyState(DIK_NUMPADENTER);
	CheckKeyState(DIK_SPACE);
	CheckKeyState(DIK_W);
	CheckKeyState(DIK_S);

	if (KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease)
	{
		switch (resultPage)
		{
		case PAGE1:
			resultPage = PAGE2;
			break;
		case PAGE2:
			resultPage = PAGE3;
			break;
		case PAGE3:
			resultPage = PAGE1;
			if (cursorResult.y < 500) {
				g_gameScene = FLOAMOVE;
				g_scene = SCENE_MAIN;
			}
			else g_scene = SCENE_TITLE;
			break;
		}
	}
	if (KeyState[DIK_SPACE] == KeyRelease)
	{
		g_scene = SCENE_TITLE;
	}
	if (resultPage == PAGE3) {
		if (KeyState[DIK_W] == KeyRelease)
		{
			soundsManager.Stop("CURSOR");
			soundsManager.Start("CURSOR", false);
			cursorResult.y = 490;
		}
		if (KeyState[DIK_S] == KeyRelease)
		{
			soundsManager.Stop("CURSOR");
			soundsManager.Start("CURSOR", false);
			cursorResult.y = 560;

		}
	}
	GetControl(0);
	BottonCheck();
	if (PadState[ButtonA] == PadRelease) {
		g_scene = SCENE_TITLE;
	}
}

void resultRenderOne(void)
{

	EasyCreateSquareVertex(0, 0, WIDTH, 700, RESULT_BG_TEX);

	CUSTOMVERTEX resultBaseTex1[4];
	CUSTOMVERTEX resultBaseTex2[4];
	CUSTOMVERTEX resultBaseTex3[4];
	CUSTOMVERTEX resultSeleTex1[4];
	CUSTOMVERTEX resultSeleTex2[4];
	CUSTOMVERTEX resultSeleTex3[4];
	CUSTOMVERTEX resultComboTex[4];
	CUSTOMVERTEX saleTResultTex[4];
	CUSTOMVERTEX nomalTResultTex[4];
	CUSTOMVERTEX comboTResultTex[4];

	CENTRAL_STATE BaseTexCentral1{ 100,150,50,50 };
	CENTRAL_STATE BaseTexCentral2{ 100,250,50,50 };
	CENTRAL_STATE BaseTexCentral3{ 100,350,50,50 };
	CENTRAL_STATE SeleTexCentral1{ 850,150,50,50 };
	CENTRAL_STATE SeleTexCentral2{ 850,250,50,50 };
	CENTRAL_STATE SeleTexCentral3{ 850,350,50,50 };
	CENTRAL_STATE comboTexCentral{ 640,315,100,100 };
	CENTRAL_STATE saleTResult{ 200,30,100,25 };
	CENTRAL_STATE nomalTResult{ 1020,30,100,25 };
	CENTRAL_STATE comboTResult{ 640,30,100,25 };

	CreateSquareVertex(saleTResultTex, saleTResult);
	CreateSquareVertex(nomalTResultTex, nomalTResult);
	CreateSquareVertex(comboTResultTex, comboTResult);

	SetUpTexture(saleTResultTex, RESULT_SALE_TEX);
	SetUpTexture(nomalTResultTex, RESULT_NOMAL_TEX);
	SetUpTexture(comboTResultTex, RESULT_COMBO_TEX);

	CreateSquareVertex(resultBaseTex1, BaseTexCentral1);
	CreateSquareVertex(resultBaseTex2, BaseTexCentral2);
	CreateSquareVertex(resultBaseTex3, BaseTexCentral3);
	CreateSquareVertex(resultSeleTex1, SeleTexCentral1);
	CreateSquareVertex(resultSeleTex2, SeleTexCentral2);
	CreateSquareVertex(resultSeleTex3, SeleTexCentral3);
	CreateSquareVertex(resultComboTex, comboTexCentral);

	SetUpTexture(resultBaseTex1, foodGoods[selectedGoods[0]].textureID);
	SetUpTexture(resultBaseTex2, foodGoods[selectedGoods[1]].textureID);
	SetUpTexture(resultBaseTex3, foodGoods[selectedGoods[2]].textureID);
	SetUpTexture(resultSeleTex1, foodGoods[selectedGoods[0]].textureID);
	SetUpTexture(resultSeleTex2, foodGoods[selectedGoods[1]].textureID);
	SetUpTexture(resultSeleTex3, foodGoods[selectedGoods[2]].textureID);
	SetUpTexture(resultComboTex, foodCombo[comboSucceceCheck()].textureID);


	char resulttantValue[32];
	if (apperText[0]) {
		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[0]].nominalCost, foodGoods[selectedGoods[0]].haveValue, addPrice(0, 0));
		RECT resultBase1{ 200,125,600,275 };
		WriteWord(resulttantValue, resultBase1, DT_LEFT, BLACK, RESULT_FONT);
		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[0]].selePrice, foodGoods[selectedGoods[0]].haveValue, addPrice(0, 1));
		RECT resultSele1{ 950,125,1200,275 };
		WriteWord(resulttantValue, resultSele1, DT_LEFT, BLACK, RESULT_FONT);
	}
	if (apperText[1]) {
		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[1]].nominalCost, foodGoods[selectedGoods[1]].haveValue, addPrice(1, 0));
		RECT resultBase2{ 200,225,600,275 };
		WriteWord(resulttantValue, resultBase2, DT_LEFT, BLACK, RESULT_FONT);
		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[1]].selePrice, foodGoods[selectedGoods[1]].haveValue, addPrice(1, 1));
		RECT resultSele2{ 950,225,1200,275 };
		WriteWord(resulttantValue, resultSele2, DT_LEFT, BLACK, RESULT_FONT);
	}
	if (apperText[2]) {

		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[2]].nominalCost, foodGoods[selectedGoods[2]].haveValue, addPrice(2,0));
		RECT resultBase3{ 200,325,600,475};
		WriteWord(resulttantValue, resultBase3, DT_LEFT, BLACK, RESULT_FONT);
		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[2]].selePrice, foodGoods[selectedGoods[2]].haveValue, addPrice(2, 1));
		RECT resultSele3{ 950,325,1200,475 };
		WriteWord(resulttantValue, resultSele3, DT_LEFT, BLACK, RESULT_FONT);
	}
	if (apperText[3]) {

		sprintf_s(resulttantValue, 32, "���v%d�~", nomalSum);
		RECT resultBaseTotal{ 200,425,440,575 };
		WriteWord(resulttantValue, resultBaseTotal, DT_RIGHT, BLACK, RESULT_FONT);
		sprintf_s(resulttantValue, 32, "���v%d�~", saleSale);
		RECT resultSeleTotal{ 950,425,1200,575 };
		WriteWord(resulttantValue, resultSeleTotal, DT_RIGHT, BLACK, RESULT_FONT);

	}
	if (apperText[4]) {
		sprintf_s(resulttantValue, 32, "%d-%d=%d", nomalSum, saleSale, nomalSum - saleSale);
		RECT resultTotal{ 140,525,1140,700 };
		WriteWord(resulttantValue, resultTotal, DT_CENTER, BLACK, SCORE_FONT);
	}



}

void resultRenderTwo(void)
{
	EasyCreateSquareVertexColor(0, 0, WIDTH, HEIGHT, HARFCLEAR, BLANK);
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT,RESULT_POP_TEX);

	char resulttantValue[32];
	sprintf_s(resulttantValue, 32, "%d",nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus);
	RECT resultTotal{ 0,235,360,400 };
	WriteWord(resulttantValue, resultTotal, DT_RIGHT, BLACK, LAST_SCORE_FONT);

}

void resultRenderThree(void)
{
	CUSTOMVERTEX cursor[4];
	CreateSquareVertex(cursor, cursorResult);
	EasyCreateSquareVertex(50, 450, 500, 600, RESULT_END_TEX);
	SetUpTexture(cursor, TITLEICON_TEX);
}

int addPrice(int num, int nomalOrSale)
{
	switch(nomalOrSale)
	{
	case 0:
		return foodGoods[selectedGoods[num]].nominalCost * foodGoods[selectedGoods[num]].haveValue;
		break;
	case 1:
		return foodGoods[selectedGoods[num]].selePrice * foodGoods[selectedGoods[num]].haveValue;
		break;
	}
}

void apperResult(void)
{
	static int resultCounter = 0;
	resultCounter++;
	if (resultCounter == 30) {
		apperText[0] = true;
		soundsManager.Start("COIN1", false);
	}
	if (resultCounter == 60) {
		apperText[1] = true;
		soundsManager.Start("COIN2", false);
	}
	if (resultCounter == 90) {
		apperText[2] = true;
		soundsManager.Start("COIN3", false);
	}
	if (resultCounter == 120) {
		apperText[3] = true;
		soundsManager.Start("COIN4", false);
	}
	if (resultCounter == 150) {
		apperText[4] = true;
		soundsManager.Start("COIN5", false);
	}

}