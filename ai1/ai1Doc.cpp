
// ai1Doc.cpp : Cai1Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ai1.h"
#endif

#include "ai1Doc.h"

#include <propkey.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cai1Doc

IMPLEMENT_DYNCREATE(Cai1Doc, CDocument)

BEGIN_MESSAGE_MAP(Cai1Doc, CDocument)
	
//	ON_COMMAND(ID_BUTTON32785, &Cai1Doc::OnButton32785)
//	ON_COMMAND(ID_BUTTON32782, &Cai1Doc::OnButton32782)
//	ON_COMMAND(ID_BUTTON32780, &Cai1Doc::OnButton32780)
END_MESSAGE_MAP()


// Cai1Doc ����/����

Cai1Doc::Cai1Doc()
{
	// TODO:  �ڴ����һ���Թ������

}

Cai1Doc::~Cai1Doc()
{
}

BOOL Cai1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// Cai1Doc ���л�

void Cai1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		
		CString filename = ar.m_strFileName;       //�ļ�·��
	//	AfxMessageBox(filename);
		char tmp_byte[1] = { 0 };	//������ʱ�ֽ�
		CString str_word;			//������
		CString str_line;			//������
		int count = 1;				//vector�ṹ�ڲ�����
		while (ar.Read(tmp_byte, 1))
		{
			if (tmp_byte[0] == 0) break;
			else if ((tmp_byte[0] != '\t') && (tmp_byte[0] != '\n') && (tmp_byte[0] != '\r'))
			{
				str_word.Format(_T("%s"), tmp_byte);
				str_line += str_word;
			}
			if (tmp_byte[0] == '\t' || tmp_byte[0] == '\r')
			{
				if (count <= 8)  count; else count = 1;
				switch (count)
				{
				case 1:Gollist.tim = str_line, str_line.Empty(); break;
				case 2:Gollist.dat = str_line, str_line.Empty(); break;
				case 3:Gollist.open = _ttof(str_line), str_line.Empty(); break;
				case 4:Gollist.high= _ttof(str_line), str_line.Empty(); break;
				case 5:Gollist.low = _ttof(str_line), str_line.Empty(); break;
				case 6:Gollist.clos = _ttof(str_line), str_line.Empty(); break;
				case 7:Gollist.vol = _ttof(str_line), str_line.Empty(); break;
				case 8:Gollist.p= _ttof(str_line), str_line.Empty(); break;
				default:break;
				}
				if (tmp_byte[0] == '\r')
				{
					GolVec.push_back(Gollist);
					
				}
				count++;



			}

		}

	}
}
#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void Cai1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void Cai1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void Cai1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cai1Doc ���

#ifdef _DEBUG
void Cai1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cai1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cai1Doc ����


//void Cai1Doc::OnButton32785()
//{
//	// TODO:  �ڴ���������������
//	AfxMessageBox(_T("h"));
//}


//void Cai1Doc::OnButton32782()
//{
//	// TODO:  �ڴ���������������
//}


//void Cai1Doc::OnButton32780()
//{
//	// TODO:  �ڴ���������������
//}
