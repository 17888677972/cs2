#pragma once
//ȫ�ֻƽ���
#define g_initV (float)5.0316
//��ඨ��
#define NOP 0X90
#define XOR 0X32
#define AL_AL 0xC0
//����ַ�����ʽ
#define RSS_DEFAULT 0
#define RSS_MIXSYNBOLS 2
#define RSS_CHINESE 4 
//�Զ���ֵ
#define MaxNum_PeopleOnline 20
#define �������� 1
#define �رձ��� 0
#define	LENGTH_GameStatusInfo 50
#define	WM_VERSION_UNUSEFUL 0x888
//��Ϸ��Ϣ���壺��Ϸģʽ
#define	UNKNOWN 404
#define	Competitive 1
#define Wingman 2
#define Casual 3
#define Deathmatch 4
#define ArmsRace 5
//��ͼ
enum class MAP {
	UNKNOW,
	DustII,
	Mirage,
	Vertigo,
	Ancient, 
	Inferno,
	Nuke,
	Anubis,
	Overpass,
	Thera,
	Mills,
	Office,
	Italy,
	Assembly,
	Memento,
	Baggage,
	Shoots, 
	PoolDay
};
//����ģʽ
//����
#define AimAtTheEnemy 1
#define AimAtTheAll 2
#define AimAtTheAlly 3
#define ��װ���� 4
//��ʽ
#define AimByDistance 4
#define AimByAngle 5
#define AimByHP 6