
#pragma once
#include "CMyTimer.h"


// My004View 视图

class My004View : public CScrollView
{
	DECLARE_DYNCREATE(My004View)

protected:
	My004View();           // 动态创建所使用的受保护的构造函数
	virtual ~My004View();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
	virtual void OnInitialUpdate();     // 构造后的第一次
	
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:
//	afx_msg LRESULT OnStart(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnPaus(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnEnd(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnButton32780();
	afx_msg void OnButton32782();
	afx_msg void OnButton32785();
private:
	CMyTimer timer;
	
public:
//	afx_msg void OnPaint();
//	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg void OnPaint();
//	afx_msg void OnDestroy();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnIconEraseBkgnd(CDC* pDC);
	afx_msg void OnIconEraseBkgnd(CDC* pDC);
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


