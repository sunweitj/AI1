// My003View.cpp : 实现文件
//

#include "stdafx.h"
#include "ai1.h"
#include "My003View.h"


// CMy003View

IMPLEMENT_DYNCREATE(CMy003View, CView)

CMy003View::CMy003View()
{

}

CMy003View::~CMy003View()
{
}

BEGIN_MESSAGE_MAP(CMy003View, CView)
END_MESSAGE_MAP()


// CMy003View 绘图

void CMy003View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
}


// CMy003View 诊断

#ifdef _DEBUG
void CMy003View::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMy003View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMy003View 消息处理程序
