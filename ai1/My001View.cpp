// My001View.cpp : ʵ���ļ�
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


// CMy001View ��ͼ

void CMy001View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  �ڴ���ӻ��ƴ���

}


// CMy001View ���

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


// CMy001View ��Ϣ�������
