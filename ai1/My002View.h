#pragma once


// CMy002View ��ͼ

class CMy002View : public CView
{
	DECLARE_DYNCREATE(CMy002View)

protected:
	CMy002View();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMy002View();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


