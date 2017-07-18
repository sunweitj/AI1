
// ChildFrm.cpp : CChildFrame 类的实现
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

// CChildFrame 构造/析构

CChildFrame::CChildFrame()
{
	// TODO:  在此添加成员初始化代码
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	//return m_wndSplitter.Create(this,
	//	2, 2,			// TODO:  调整行数和列数
	//	CSize(10, 10),	// TODO:  调整最小窗格大小
	//	pContext);
	

	if (!m_split.CreateStatic(this, 1, 2))

	{
		TRACE0("Failed to create first static splitter\n");

		return FALSE;

	}

	if (!m_split.CreateView(0, 0, RUNTIME_CLASS(CMy001View),//创建右边视图

		CSize(200, 100), pContext) ||

		!m_split.CreateView(0, 1, RUNTIME_CLASS(CMy002View),

		CSize(200, 100), pContext))

	{

		m_split.DestroyWindow();

		return FALSE;

	}



	m_split.DeleteView(0, 0);//删除刚刚创建

	if (!m_splitLeft.CreateStatic(&m_split, 2, 1, WS_CHILD | WS_VISIBLE,

		m_split.IdFromRowCol(0, 0)))

	{

		return FALSE;

	}

	if (!m_splitLeft.CreateView(0, 0, RUNTIME_CLASS(CMy001View),//左上

		CSize(0, 500), pContext) ||

		!m_splitLeft.CreateView(1, 0, RUNTIME_CLASS(CMy003View),//左下

		CSize(0,500), pContext))

	{

		m_splitLeft.DestroyWindow();

		return FALSE;

	}
	CRect rect;
	GetClientRect(&rect);
	CSize size = rect.Size();
	//size.cx /= 2;
	//size.cy /= 2;
	
	m_split.SetColumnInfo(0, size.cx/3*2, 100);
	m_splitLeft.SetColumnInfo(0, size.cx - size.cx / 3*2, 100);
	m_splitLeft.SetRowInfo(1, size.cy/2, 100);
	m_split.RecalcLayout();
	m_split.SetActivePane(0, 0);



	return TRUE;   

}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame 诊断

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

// CChildFrame 消息处理程序
