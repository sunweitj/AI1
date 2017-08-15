// My004View.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ai1.h"
#include "My004View.h"
#include "CMyTimer.h"
#include <time.h>
#include "CParams.h"
#include "CController.h"
#include "ai1Doc.h"

//these hold the dimensions of the client window area
int cxClient=600, cyClient=400;
bool bDone = FALSE;
bool pause = TRUE;
int wpos=1;
//used to create the back buffer

// My004View

IMPLEMENT_DYNCREATE(My004View, CScrollView)

My004View::My004View()
{

}

My004View::~My004View()
{
}


BEGIN_MESSAGE_MAP(My004View, CScrollView)
//	ON_WM_CREATE()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()

	ON_COMMAND(ID_BUTTON32780, &My004View::OnButton32780)
	ON_COMMAND(ID_BUTTON32782, &My004View::OnButton32782)
	ON_COMMAND(ID_BUTTON32785, &My004View::OnButton32785)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_KEYUP()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_ICONERASEBKGND()
	ON_WM_ICONERASEBKGND()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// My004View ��ͼ

void My004View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO:  �������ͼ�ĺϼƴ�С
	//sizeTotal.cx = GolVec.size();
	sizeTotal.cx = 5000;
	sizeTotal.cy = 200;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void My004View::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	Cai1Doc* pDoc = (Cai1Doc*)GetDocument();
	// TODO:  �ڴ���ӻ��ƴ���

	/*
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
	////////////////////////////////////////////
//	PAINTSTRUCT ps;



*/

	/*
	
	pDoc->m_TmpMap.LoadBitmapW(IDB_BITMAP1); //����λͼ��λͼ����
	
	 CDC dcBackBuffer; //����dc����
	 
//	 HDC hdcBackBuffer = dcBackBuffer.GetSafeHdc();
	 
	 dcBackBuffer.CreateCompatibleDC(pDC);//����͵�ǰdc����

	 CBitmap *poldbmp = (CBitmap*)dcBackBuffer.SelectObject(&pDoc->m_TmpMap);//��λͼ��dc

	
	
	 BITMAP bmpinfo;//����λͼ�ṹ����

	 pDoc->m_TmpMap.GetBitmap(&bmpinfo);//���λͼ�ṹ���������

	 int Bmpwidth, Bmpheigh;

	 Bmpwidth = bmpinfo.bmWidth;

	 Bmpheigh = bmpinfo.bmHeight;

	 CRect clientRC;

	 GetClientRect(clientRC);

	 pDC->StretchBlt(0, 0, clientRC.Width(), clientRC.Height(), &dcBackBuffer, 0, 0, Bmpwidth, Bmpheigh, SRCCOPY);
	  
//	BeginPaint(&ps);

	//now blit backbuffer to front
	//BitBlt(ps.hdc, 0, 0, cxClient, cyClient, dcBackBuffer, 0, 0, SRCCOPY);
	
	//fill our backbuffer with white
	//BitBlt(hdc, 0, 0, cxClient, cyClient, NULL, NULL, NULL, WHITENESS);
	//EndPaint(&ps);
	
	dcBackBuffer.SelectObject(poldbmp);
	//clean up our backbuffer objects
	dcBackBuffer.DeleteDC();
	pDoc->m_TmpMap.DeleteObject();
	
	*/
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







void My004View::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void My004View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPoint scrPos = this->GetScrollPosition();
	
		wpos = scrPos.x;
	
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}




void My004View::OnButton32780()//STOP
{
	// TODO:  �ڴ���������������
	bDone = TRUE;
	RECT rec;
	GetClientRect(&rec);
	InvalidateRect(&rec, 1);
	UpdateWindow();
}
                                                                     
void My004View::OnButton32782()  //STAR
{
	// TODO:  �ڴ���������������
	
	pause = 1;
	RECT rect;

	GetClientRect(&rect);

	Cai1Doc* pDoc = (Cai1Doc*)GetDocument();

	CDC *pdc = GetDC();

	CDC dcBackBuffer;
	
	CDC dccopy;
	
	CBitmap bitmapcopy;
	
	bitmapcopy.LoadBitmapW(IDB_BITMAP1);
	
	dcBackBuffer.CreateCompatibleDC(NULL);

	dccopy.CreateCompatibleDC(&dcBackBuffer);

	//OnPrepareDC(&dcBackBuffer, 0);

//	pDoc->m_TmpMap.DeleteObject();

	//pDoc->m_TmpMap.CreateCompatibleBitmap(pdc, 5000, 200);
	
	pDoc->m_TmpMap.LoadBitmap(IDB_BITMAP1);

	BITMAP bitinfo;

	pDoc->m_TmpMap.GetBitmap(&bitinfo);
	
//	if (pDoc->m_TmpMap.LoadBitmap(IDB_BITMAP1))
//	{
//		CString str1(_T("not load"));
//		AfxMessageBox(str1);
//	}

	CBitmap * poldbmp = (CBitmap*)dcBackBuffer.SelectObject(&pDoc->m_TmpMap);

	CBitmap * poldbmp1 = (CBitmap*)dccopy.SelectObject(&bitmapcopy);
	
	HDC  hdcBackBuffer =dcBackBuffer.GetSafeHdc();
		
	HWND hwnd = this->m_hWnd;
	
	if (!g_Params.Initialize())
	{
		AfxMessageBox(_T("not find params file"), NULL);
	}
	//setup the controller
	g_pController = new CController(hwnd, cxClient, cyClient);
	//seed the random number generator
	srand((unsigned)time(NULL));
	//create a surface for us to render to(backbuffer)
//	hdcBackBuffer = CreateCompatibleDC(NULL);

//	hBitmap = CreateCompatibleBitmap(hdc,
//		cxClient,
//		cyClient);
//	ReleaseDC(pdc);

//	hOldBitmap = (HBITMAP)SelectObject(hdcBackBuffer, hBitmap);
	

	/////////////////////////////////
	
	///////////////////////////////
	
	timer.Start();
	
	// Enter the message loop
	MSG msg;
	

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

		if ((timer.ReadyForNextFrame() || g_pController->FastRender())&&pause)
		{
			dcBackBuffer.BitBlt (0, 0, rect.right, rect.bottom, &dccopy, 0, 0, MERGECOPY);
			//render the sweepers
			g_pController->Render(hdcBackBuffer);
			if (!g_pController->Update())
			{
				//we have a problem, end app
				bDone = TRUE;
			}
			pdc->BitBlt(0, 0, rect.right, rect.bottom, &dcBackBuffer, wpos, 0, SRCCOPY);
			//this will call WM_PAINT which will render our scene
			
			

			InvalidateRect(&rect, TRUE);
			UpdateWindow();
			
		}
		
		
	}//end while


	// Clean up everything and exit the app
	
	
	dcBackBuffer.SelectObject(poldbmp);

	dcBackBuffer.DeleteDC();


}


void My004View::OnButton32785()//PAUSE
{
	// TODO:  �ڴ���������������1
	start_stop_paus = 2;
	pause = 0;

}





//int My004View::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	
//	if (CScrollView::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	
//}


void My004View::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar)
	{

	case VK_ESCAPE:
	{
					  PostQuitMessage(0);
	}

		break;

	case 'F':
	{
				g_pController->FastRenderToggle();//ֻ��Ϊ�л���־
	}

		break;

	case 'B':
	{
				g_pController->RenderBestToggle();
	}

		break;

	case 'R':
	{
				HWND hwnd = this->m_hWnd;
				if (g_pController)
				{
					delete g_pController;
				}

				//setup the new controller
				g_pController = new CController(hwnd, cxClient, cyClient);
//////////////////////����ķ���view2��
				//give the info window's handle to the controller
//				g_pController->PassInfoHandle(g_hwndInfo);

				//clear info window
				RECT rec;
				GetClientRect(&rec);
				InvalidateRect(&rec, TRUE);
				UpdateWindow();
	}

		break;

	case '1':
	{
				g_pController->ViewBest(1);
	}

		break;

	case '2':
	{
				g_pController->ViewBest(2);
	}

		break;

	case '3':
	{
				g_pController->ViewBest(3);
	}

		break;

	case '4':
	{
				g_pController->ViewBest(4);
	}

		break;




	}//end WM_KEYUP switch

	CScrollView::OnKeyUp(nChar, nRepCnt, nFlags);
}




void My004View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	
	
	// ��Ϊ��ͼ��Ϣ���� CScrollView::OnPaint()
	OnDraw(&dc);
}












void My004View::OnIconEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CScrollView::OnIconEraseBkgnd(pDC);
}


//BOOL My004View::PreCreateWindow(CREATESTRUCT& cs)
//{
//	// TODO:  �ڴ����ר�ô����/����û���
//
//
//	return CScrollView::PreCreateWindow(cs);
//}


BOOL My004View::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return FALSE;
	//return CScrollView::OnEraseBkgnd(pDC);
}
