
// ai1Doc.h : Cai1Doc ��Ľӿ�
//


#pragma once


class Cai1Doc : public CDocument
{
protected: // �������л�����
	Cai1Doc();
	DECLARE_DYNCREATE(Cai1Doc)

// ����
public:
	CBitmap m_TmpMap;

	
	
	
// ����
public:
	void load();
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cai1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
//	afx_msg void OnButton32785();
//	afx_msg void OnButton32782();
//	afx_msg void OnButton32780();
};
