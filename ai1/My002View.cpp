// My002View.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ai1.h"
#include "My002View.h"


// CMy002View

IMPLEMENT_DYNCREATE(CMy002View, CView)

CMy002View::CMy002View()
{

}

CMy002View::~CMy002View()
{
}

BEGIN_MESSAGE_MAP(CMy002View, CView)
END_MESSAGE_MAP()


// CMy002View ��ͼ

void CMy002View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	
	// TODO:  �ڴ���ӻ��ƴ���
	CRect rec;
	
	GetClientRect(rec);

	//����ӳ��ģʽΪMM_ANISOTROPIC
	pDC->SetMapMode(MM_ANISOTROPIC);
	//�������
	int Cx = GolVec.size();
	    
}


// CMy002View ���

#ifdef _DEBUG
void CMy002View::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMy002View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMy002View ��Ϣ�������
