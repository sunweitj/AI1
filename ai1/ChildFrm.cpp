
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
	CRect rect;
	GetClientRect(&rect);
	CSize size = rect.Size();
	size.cx /= 2;
	size.cy /= 2;

	if (!m_split.CreateStatic(this, 1, 2))

	{
		TRACE0("Failed to create first static splitter\n");

		return FALSE;

	}

	if (!m_split.CreateView(0, 0, RUNTIME_CLASS(CMy001View),//�����ұ���ͼ

		CSize(200, 100), pContext) ||

		!m_split.CreateView(0, 1, RUNTIME_CLASS(CMy002View),

		CSize(200, 100), pContext))

	{

		m_split.DestroyWindow();

		return FALSE;

	}



	m_split.DeleteView(0, 0);//ɾ���ոմ���

	if (!m_splitLeft.CreateStatic(&m_split, 2, 1, WS_CHILD | WS_VISIBLE,

		m_split.IdFromRowCol(0, 0)))

	{

		return FALSE;

	}

	if (!m_splitLeft.CreateView(0, 0, RUNTIME_CLASS(CMy001View),

		CSize(size.cx, 500), pContext) ||

		!m_splitLeft.CreateView(1, 0, RUNTIME_CLASS(CMy003View),

		CSize(size.cx,500), pContext))

	{

		m_splitLeft.DestroyWindow();

		return FALSE;

	}
	//HWND hwnd1 = m_split.GetSafeHwnd();
	//if (hwnd1 == NULL || IsWindow(hwnd1))
	//{
	//	return 0;
	//}
	int l = size.cx, w = size.cy;
	m_split.GetColumnInfo(0,l,w);


	return TRUE;   
/*	CRect rect;
	GetClientRect( &rect );
	CSize size = rect.Size();
	size.cx /= 2;		// Initial column size
	size.cy /= 2;		// Initial row size

	// 1 - Create first static splitter
	if( !m_split.CreateStatic( this, 1, 2 ) )	// 2 rows, 1 col
	{
		TRACE0( "Failed to create first static splitter\n" );
		return FALSE;
	}

	// 2 - Create top row view
	if( !m_split.CreateView( 0, 0,				// row 0, col 0
		RUNTIME_CLASS(CMy001View),
							size, pContext ) )
	{
		m_split.DestroyWindow();
		TRACE0( "Failed to create top view\n" );
		return FALSE;
	}
	m_split.DeleteView(0, 0);//ɾ���ոմ���
	// 3 - Create nested static splitter 
	if( !m_splitLeft.CreateStatic( &m_split, 2, 1,	// 1 row, 2 cols
							 WS_CHILD | WS_VISIBLE,
							 m_split.IdFromRowCol( 0, 1 ) ) )
	{
		TRACE0( "Failed to create nested static splitter\n" );
		return FALSE;
	}

	// 4 - Create bottom-left view
	if( !m_splitLeft.CreateView( 0, 0,			// row 0, col 0
		RUNTIME_CLASS(CMy002View),
							size, pContext ) )
	{
		TRACE0( "Failed to create bottom-left view\n" );
		return FALSE;
	}

	// 5 - Create bottom-right view
	if( !m_splitLeft.CreateView( 0, 1,			// row 0, col 1
		RUNTIME_CLASS(CMy003View),
							size, pContext ) )
	{
		TRACE0( "Failed to create bottom-right view\n" );
		return FALSE;
	}

	return TRUE;*/
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
