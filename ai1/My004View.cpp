// My004View.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ai1.h"
#include "My004View.h"


// My004View

IMPLEMENT_DYNCREATE(My004View, CScrollView)

My004View::My004View()
{

}

My004View::~My004View()
{
}


BEGIN_MESSAGE_MAP(My004View, CScrollView)
	ON_WM_CREATE()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// My004View ��ͼ

void My004View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO:  �������ͼ�ĺϼƴ�С
	sizeTotal.cx = GolVec.size();
	sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void My004View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  �ڴ���ӻ��ƴ���
	CRect rec;
	GetClientRect(&rec);
	int HorPos = GetScrollPos(SB_HORZ);
	//���߿�
	CPen pen(PS_SOLID, 1, RGB(255, 200, 0));
	HGDIOBJ oldpen = pDC->SelectObject(&pen);
	pDC->MoveTo(0, 20);
	pDC->LineTo(GolVec.size(), 20);
	pDC->MoveTo(GolVec.size() - 20, 20);
	pDC->LineTo(GolVec.size() - 20, rec.Height() - 20);
	pDC->MoveTo(GolVec.size(), rec.Height() - 20);
	pDC->LineTo(0, rec.Height() - 20);
	pDC->MoveTo(20, rec.Height() - 20);
	pDC->LineTo(20, 20);
	pDC->SelectObject(oldpen);
	DeleteObject(pen);
	//������
	CPen pendot(PS_DOT, 1, RGB(255, 200, 0));
	HGDIOBJ oldpendot = pDC->SelectObject(&pendot);
	pDC->MoveTo(0 + 20, rec.Height() / 2);
	pDC->LineTo(GolVec.size() - 20, rec.Height() / 2);
	pDC->MoveTo(GolVec.size() / 2, 20);
	pDC->LineTo(GolVec.size() / 2, rec.Height() - 20);
	pDC->SelectObject(oldpendot);
	DeleteObject(pendot);
}


// My004View ���

#ifdef _DEBUG
void My004View::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void My004View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// My004View ��Ϣ�������


int My004View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void My004View::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void My004View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}
