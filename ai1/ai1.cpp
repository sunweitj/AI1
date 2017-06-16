
// ai1.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "ai1.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "ai1Doc.h"
#include "ai1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cai1App

BEGIN_MESSAGE_MAP(Cai1App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &Cai1App::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
//	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_FILE_OPEN, &Cai1App::OnFileOpen)
END_MESSAGE_MAP()


// Cai1App ����

Cai1App::Cai1App()
{
	m_bHiColorIcons = TRUE;

	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ai1.AppID.NoVersion"));

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� Cai1App ����

Cai1App theApp;


// Cai1App ��ʼ��

BOOL Cai1App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	//CMultiDocTemplate* pDocTemplate;  //���˶���ŵ�pulic��λ��20170613
	pDocTemplate = new CMultiDocTemplate(IDR_ai1TYPE,//
		RUNTIME_CLASS(Cai1Doc),						//#define RUNTIME_CLASS(class_name) (class_name::GetThisClass())
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(Cai1View));
	if (!pDocTemplate)
		return FALSE;

	AddDocTemplate(pDocTemplate);
	//pDocTemplate->OpenDocumentFile(_T("C:\\Users\\DELL-660\\Desktop\\SH#999999SL.txt"), 1);
	//�����ڶ�������2017613



	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;//20170614����Ĭ�Ͽ��ĵ�
	ParseCommandLine(cmdInfo);//



	// ��������������ָ�������  ���
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	//20170610//����release
/*	CFile file;
	file.Open(_T("C:\\Users\\DELL-660\\Desktop\\SH#999999SL.txt"), CFile::modeRead);
	
	CString tmp= file.GetFileName();
	
		AfxMessageBox(tmp);
	if (file.m_hFile != CFile::hFileNull)
		   {
		         file.Close();
		     }
	    else
		     {
		         printf("File Already Close \n");
		     }
	CPerson myperson;
	CArchive ar(&file, CArchive::store);
	
	myperson.Serialize(ar);
	
	*/
	
	// �������ѳ�ʼ���������ʾ����������и���
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	//POSITION p = pDocTemplate->GetFirstDocPosition;
	
	pDocTemplate->OpenDocumentFile(_T("C:\\Users\\DELL-660\\Desktop\\SH#999999SL.txt"), 1);
	return TRUE;
}

int Cai1App::ExitInstance()
{
	//TODO:  �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// Cai1App ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void Cai1App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Cai1App �Զ������/���淽��

void Cai1App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void Cai1App::LoadCustomState()
{
}

void Cai1App::SaveCustomState()
{
}

// Cai1App ��Ϣ�������



list Gollist;//ȫ�ֵĽṹ���ڴ洢ʱ�䣬���̣���ߣ�������̳ɽ����ɽ���
g_list GolVec;//ȫ�ֵ�vector����list�ṹ



//20170610

//void Cai1App::OnFileOpen()
//{
//	// TODO:  �ڴ���������������
//	pDocTemplate->OpenDocumentFile(_T("C:\\Users\\DELL-660\\Desktop\\SH#999999SL.txt"), 1);
//	
//}
