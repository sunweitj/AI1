
#pragma once



// My004View ��ͼ

class My004View : public CScrollView
{
	DECLARE_DYNCREATE(My004View)

protected:
	My004View();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~My004View();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
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
	afx_msg void OnPaint();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};


