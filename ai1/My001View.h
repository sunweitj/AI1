#pragma once


// CMy001View ��ͼ

class CMy001View : public CView
{
	DECLARE_DYNCREATE(CMy001View)

protected:
	CMy001View();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMy001View();

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


