#pragma once


// CMy003View ��ͼ

class CMy003View : public CView
{
	DECLARE_DYNCREATE(CMy003View)

protected:
	CMy003View();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMy003View();

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


