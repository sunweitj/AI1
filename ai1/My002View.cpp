// My002View.cpp : 实现文件
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


// CMy002View 绘图

void CMy002View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	
	// TODO:  在此添加绘制代码
	CRect rec;
	
	GetClientRect(rec);

	//设置映射模式为MM_ANISOTROPIC
	pDC->SetMapMode(MM_ANISOTROPIC);
	//坐标比例
	int Cx = GolVec.size();
	    
}


// CMy002View 诊断

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


// CMy002View 消息处理程序
