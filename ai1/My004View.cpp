// My004View.cpp : 实现文件
//

#include "stdafx.h"
#include "ai1.h"
#include "My004View.h"
#include "CMyTimer.h"
#include <time.h>
#include "CParams.h"




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

	ON_COMMAND(ID_BUTTON32780, &My004View::OnButton32780)
	ON_COMMAND(ID_BUTTON32782, &My004View::OnButton32782)
	ON_COMMAND(ID_BUTTON32785, &My004View::OnButton32785)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// My004View 绘图

void My004View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO:  计算此视图的合计大小
	//sizeTotal.cx = GolVec.size();
	sizeTotal.cx = 50000;
	sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void My004View::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
	CRect rec;
	GetClientRect(&rec);
	int HorPos = GetScrollPos(SB_HORZ);
	//画边框
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
	//画坐标
	CPen pendot(PS_DOT, 1, RGB(255, 200, 0));
	HGDIOBJ oldpendot = pDC->SelectObject(&pendot);
	pDC->MoveTo(0 + 20, rec.Height() / 2);
	pDC->LineTo(GolVec.size() - 20, rec.Height() / 2);
	pDC->MoveTo(GolVec.size() / 2, 20);
	pDC->LineTo(GolVec.size() / 2, rec.Height() - 20);
	pDC->SelectObject(oldpendot);
	DeleteObject(pendot);

	
	}




// My004View 诊断

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


// My004View 消息处理程序


int My004View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码


	return 0;
}


void My004View::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void My004View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	

	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}




void My004View::OnButton32780()//STOP
{
	// TODO:  在此添加命令处理程序代码
	RECT rec;
	GetClientRect(&rec);
	InvalidateRect(&rec, 1);
	UpdateWindow();
}
                                                                     
void My004View::OnButton32782()  //STAR
{
	// TODO:  在此添加命令处理程序代码
	
	timer.Start();
	RECT rec;
	GetClientRect(&rec);
	// Enter the message loop
	MSG msg;
	bool bDone = FALSE;

	while (!bDone)
	{

		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				// Stop loop if it's a quit message
				bDone = TRUE;
			}

			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		if (timer.ReadyForNextFrame() || g_pController->FastRender())
		{
			if (!g_pController->Update())
			{
				//we have a problem, end app
				bDone = TRUE;
			}

			//this will call WM_PAINT which will render our scene
			InvalidateRect(&rec, TRUE);
			UpdateWindow();
		}

	}//end while


	// Clean up everything and exit the app
	
	


}


void My004View::OnButton32785()//PAUSE
{
	// TODO:  在此添加命令处理程序代码
	start_stop_paus = 2;

}


void My004View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CScrollView::OnPaint()
	OnDraw(&dc);
}


LRESULT My004View::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO:  在此添加专用代码和/或调用基类

	return CScrollView::WindowProc(message, wParam, lParam);
}
