
// ai1Doc.cpp : Cai1Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// Cai1Doc 构造/析构

Cai1Doc::Cai1Doc()
{
	// TODO:  在此添加一次性构造代码

}

Cai1Doc::~Cai1Doc()
{
}

BOOL Cai1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// Cai1Doc 序列化

void Cai1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		
		CString filename = ar.m_strFileName;       //文件路径
	//	AfxMessageBox(filename);
		char tmp_byte[1] = { 0 };	//保存临时字节
		CString str_word;			//保存字
		CString str_line;			//保存行
		int count = 1;				//vector结构内部计数
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

// 缩略图的支持
void Cai1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void Cai1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// Cai1Doc 诊断

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


// Cai1Doc 命令


//void Cai1Doc::OnButton32785()
//{
//	// TODO:  在此添加命令处理程序代码
//	AfxMessageBox(_T("h"));
//}


//void Cai1Doc::OnButton32782()
//{
//	// TODO:  在此添加命令处理程序代码
//}


//void Cai1Doc::OnButton32780()
//{
//	// TODO:  在此添加命令处理程序代码
//}
