// My001View.cpp : 实现文件
//

#include "stdafx.h"
#include "ai1.h"
#include "My001View.h"


// CMy001View

IMPLEMENT_DYNCREATE(CMy001View, CView)

CMy001View::CMy001View()
{

}

CMy001View::~CMy001View()
{
}

BEGIN_MESSAGE_MAP(CMy001View, CView)
END_MESSAGE_MAP()


// CMy001View 绘图

void CMy001View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CRect rec;
	GetClientRect(&rec);
	
	CPen pen(PS_SOLID, 1, RGB(255, 200, 0));
	HGDIOBJ oldpen = pDC->SelectObject(&pen);
	pDC->MoveTo(0,20);
	pDC->LineTo(rec.Width(), 20);
	pDC->MoveTo(rec.Width()-20, 20);
	pDC->LineTo(rec.Width()-20, rec.Height() - 20);
	pDC->MoveTo(rec.Width(), rec.Height()-20);
	pDC->LineTo(0,rec.Height()-20);
	pDC->MoveTo(20, rec.Height() - 20);
	pDC->LineTo(20, 20);
	pDC->SelectObject(oldpen);
	//DeleteObject(pen);
	

	// TODO:  在此添加绘制代码

}


// CMy001View 诊断

#ifdef _DEBUG
void CMy001View::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMy001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMy001View 消息处理程序
