
// ai1.h : ai1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
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
extern list Gollist;//ȫ�ֵĽṹ���ڴ洢ʱ�䣬���̣���ߣ�������̳ɽ����ɽ���
extern g_list GolVec;//ȫ�ֵ�vector����list�ṹ
// Cai1App:
// �йش����ʵ�֣������ ai1.cpp
//

class Cai1App : public CWinAppEx
{
public:
	Cai1App();
	CMultiDocTemplate* pDocTemplate;

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
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