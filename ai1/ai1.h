
// ai1.h : ai1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include <vector>

struct list
{
	CString dat;
	CString tim;
	float open;
	float high;
	float low;
	float clos;
	float vol;
	float p;
};
typedef std::vector<list> g_list;
extern list Gollist;//全局的结构用于存储时间，开盘，最高，最低收盘成交量成交额
extern g_list GolVec;//全局的vector保存list结构
// Cai1App:
// 有关此类的实现，请参阅 ai1.cpp
//

class Cai1App : public CWinAppEx
{
public:
	Cai1App();
	CMultiDocTemplate* pDocTemplate;

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
//	afx_msg void OnFileOpen();
};

extern Cai1App theApp;


//20170601
class CPerson : public CObject  
{
public:
	DECLARE_SERIAL(CPerson) 
	// empty constructor is necessary
	CPerson(){}; 

		CString m_name;
	WORD   m_number;

	void Serialize(CArchive& archive); 

		// rest of class declaration
};