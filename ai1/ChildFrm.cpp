
// ChildFrm.cpp : CChildFrame ���ʵ��
//

#include "stdafx.h"
#include "ai1.h"

#include "ChildFrm.h"
#include"My001View.h"
#include"My002View.h"
#include"My003View.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	//return m_wndSplitter.Create(this,
	//	2, 2,			// TODO:  ��������������
	//	CSize(10, 10),	// TODO:  ������С�����С
	//	pContext);
	if (!m_split.CreateStatic(this, 1, 2))

	{

		return FALSE;

	}

	if (!m_split.CreateView(0, 0, RUNTIME_CLASS(CMy001View),

		CSize(200, 100), pContext) ||

		!m_split.CreateView(0, 1, RUNTIME_CLASS(CMy002View),

		CSize(200, 100), pContext))

	{

		m_split.DestroyWindow();

		return FALSE;

	}



	m_split.DeleteView(0, 0);

	if (!m_splitLeft.CreateStatic(&m_split, 2, 1, WS_CHILD | WS_VISIBLE,

		m_split.IdFromRowCol(0, 0)))

	{

		return FALSE;

	}

	if (!m_splitLeft.CreateView(0, 0, RUNTIME_CLASS(CMy001View),

		CSize(200, 100), pContext) ||

		!m_splitLeft.CreateView(1, 0, RUNTIME_CLASS(CMy003View),

		CSize(200, 100), pContext))

	{

		m_splitLeft.DestroyWindow();

		return FALSE;

	}



	return TRUE;
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame ��Ϣ�������
