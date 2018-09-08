#ifndef MAIN_H
#define MAIN_H


#include "DirectX_LIB/DirectX_LIB/TrialLib.h"



#ifdef _DEBUG
#include "SoundLib/Debug_x86/Include/SoundsManager.h"
#pragma comment(lib,"SoundLib/Debug_x86/Lib/SoundLib.lib")
#pragma comment(lib, "DirectX_LIB/Debug/DirectX_LIB.lib")
#else
#include "SoundLib/Release_x86/Include/SoundsManager.h"
#pragma comment(lib,"SoundLib/Release_x86/Lib/SoundLib.lib")
#pragma comment(lib, "DirectX_LIB/Release/DirectX_LIB.lib")
#endif //_DEBUG

#define WIDTH 1280
#define HEIGHT 720
#define RED 0xFFFF0000
#define BLACK 0xff000000
#define HARFCLEAR 0x8a000000

#define YASUKO_TU (350.f/2048.f)
#define YASUKO_TV (679.f/2048.f)
#define BOY_TU (487.f/2048.f)
#define BOY_TV (707.f/2048.f)
#define MOB_TU (430.f/2048.f)
#define MOB_TV (685.f/2048.f)
#define SALE_TU (480.f/2048.f)
#define SALE_TV (785.f/2048.f)

//ゲームパッドの状態
#define UP_BUTTON 0x0001
#define DOWN_BUTTON 0x0002
#define LEFT_BUTTON 0x0004
#define RIGHT_BUTTON 0x0008
#define START_BUTTOM 0x0010
#define BACK_BUTTON 0x0020
#define LEFT_STICK 0x0040
#define RIGHT_STICK 0x0080
#define LEFT_SHOULDER 0x0100
#define RIGHT_SHOULDER 0x0200
#define A_BUTTON 0x1000
#define B_BUTTON 0x2000
#define X_BUTTON 0x4000
#define Y_BUTTON 0x8000

//0秒
#define ZERO_SECOND 0

//1秒
#define ONE_SECOND 60

//2秒
#define TWO_SECOND 120

//3秒
#define THREE_SECOND 180

//4秒
#define FOUR_SECOND 240

//3分
#define THREE_MINUTE 10800

//3分で3周するRad
#define THREE_MINUTE_RADIAN 0.001745f

extern XINPUT_STATE g_Xinput;

//主婦のステータス
struct CHARACTER_STATE
{
	INT strength;
	FLOAT speed;
	DOUBLE skill;
};

enum TITLESCENE {
 TITLE,
 WISDOM
};
enum SCENEPAGE
{
	PAGE1,
	PAGE2,
	PAGE3
};

enum SCENE {
	SCENE_TEAMLOGO,
	SCENE_TITLE,
	SCENE_SERECTCHARANDSTAGE,
	SCENE_MAIN,
	SCENE_RESULT,
};

extern SoundLib::SoundsManager soundsManager;
extern bool g_SoundSuccess;
extern RECT testWord;
extern int g_titleScene;
extern int g_scene;

extern FLOAT g_PCSpeed;
extern DWORD g_cursolColor;
//ヤス子のステータス
extern CHARACTER_STATE g_yasukoSta;

//ミツ子のステータス
extern CHARACTER_STATE g_mitukoSta;

//イソ子のステータス
extern CHARACTER_STATE g_isokoSta;

extern int g_inCount;
extern int g_timerCount;

extern bool g_pause;
extern bool g_isGameStart;
extern bool g_isTimeUp;
extern bool g_isSound;
extern bool g_isNextSelect;
extern bool g_isLastCheck;

void setNowLoading();

#endif // !MAIN_H
