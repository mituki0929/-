#ifndef GAMEMAIN_H
#define GAMEMAIN_H


struct SoundEffect {
	const char SE1[20];
	const char SE2[20];
	const char SE3[20];
	const char SE4[20];
	const char SE5[20];
	const char SE6[20];
	const char SE7[20];
	const char SE8[20];
	const char SE9[20];
	const char SE10[20];

};

enum GAMESCENE {
	FLOAMOVE,
	CHOSEGOODS,
	PUSHENEMY,
	PICKGOODS,
};


extern int comandInput[5];
extern int comandPresentment[5];
extern int comandCount;
extern int checkedComand;
extern int rushButtonShow;

extern bool g_isFirst;
extern int texturePC;
extern int g_gameScene;
extern int g_effectCount;
extern int g_turn;
extern float mobRad;
extern int mobTexNum;

extern CUSTOMVERTEX playerHit[4];
extern CENTRAL_STATE playerCentralHit;
//���u�̉摜���_
extern CUSTOMVERTEX mobFloa[4];
extern CENTRAL_STATE mobCentralFloa[3];
extern CENTRAL_STATE mobCentralBlowOff[5];

extern CENTRAL_STATE g_PCSta;
extern CENTRAL_STATE g_startCountSta;
extern CENTRAL_STATE g_startSta;

extern SoundEffect Button;
extern SoundEffect Button;
extern SoundEffect Pick;

void gameMain();
void goodsScoreShow();
void buttonSE(SoundEffect Button, int SoundNumber);

#endif