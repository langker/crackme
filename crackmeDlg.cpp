// crackmeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "crackme.h"
#include "crackmeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCrackmeDlg dialog

CCrackmeDlg::CCrackmeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCrackmeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCrackmeDlg)
	m_cool = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCrackmeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCrackmeDlg)
	DDX_Control(pDX, IDC_IPADDRESS1, m_ipaddress);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Radio(pDX, IDC_RADIOcool, m_cool);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCrackmeDlg, CDialog)
	//{{AFX_MSG_MAP(CCrackmeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_EN_CHANGE(IDC_EDIT5, OnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_WM_HSCROLL()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCrackmeDlg message handlers

BOOL CCrackmeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	SetWindowPos(NULL,0,0,212,130,SWP_HIDEWINDOW);
	m_slider.SetRange(0, 1000);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCrackmeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCrackmeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCrackmeDlg::OnChangeEdit1() 
{
	CString name;
	GetDlgItem(IDC_EDIT1)->GetWindowText(name);
	if(name=="langker")
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);
}

void CCrackmeDlg::OnButton3() 
{
	CString code;
	GetDlgItem(IDC_EDIT2)->GetWindowText(code);
	if(code.GetLength()<=15)
		MessageBox("��Ѿ����ƻ�����Ȼû������ƭ��");
	else if(code=="fuckyouhappyme!!!")
	{
		MessageBox("��������ʧ���ˣ�");
		SetWindowPos(NULL,0,0,212,280,SWP_SHOWWINDOW);
	}
}

void CCrackmeDlg::OnChangeEdit5() 
{
	UpdateData(TRUE);
	CString char1,char2,char3,char4;
	GetDlgItem(IDC_EDIT8)->GetWindowText(char1);
	GetDlgItem(IDC_EDIT7)->GetWindowText(char2);
	GetDlgItem(IDC_EDIT6)->GetWindowText(char3);
	GetDlgItem(IDC_EDIT4)->GetWindowText(char4);
	if(char1=="����"&&char2=="��"&&char3=="TMD"&&char4=="˧"&&!m_cool)
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);
}

void CCrackmeDlg::OnButton4() 
{
	UpdateData(TRUE);
	CString code;
	int namelen=0;
	GetDlgItem(IDC_EDIT5)->GetWindowText(code);
	if(code.GetLength()!=10)
		return;
	for(int i=0;i<10;i++)
		namelen=namelen+code[i];
	if(namelen==1000&&m_cool)
	{
		MessageBox("cool!�ٴ��ƽ�ɹ�!��û�����˰���");
		SetWindowPos(NULL,0,0,413,280,SWP_SHOWWINDOW);
	}
}

void CCrackmeDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int a=m_slider.GetPos();
	CString text;
	text.Format("%d",a);
    GetDlgItem(IDC_EDIT3)->SetWindowText(text);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CCrackmeDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	*pResult = 0;
}

void CCrackmeDlg::OnButton5() 
{
	unsigned long t=0;
	if(m_slider.GetPos()==38&&m_ipaddress.GetAddress(t)==3549464762)
	{
		MessageBox("�Ǹ����ϲ����˰ɣ������ڸ���һ����");
		MessageBox("��ϲ�������LANGKER���������Ĺ����Ҹ�����������һ��");
		GetDlgItem(IDC_BUTTON7)->ShowWindow(SW_SHOW);
	}
}

void CCrackmeDlg::OnButton7() 
{
	MessageBox("langker������Ʒ��\n������㣬ֻΪ����һЦ������");
	if(MessageBox("ȥ�Ҳ��Ϳ�����",NULL,MB_YESNO	)==IDYES)
	{
		ShellExecute(GetParent()->GetSafeHwnd(), _T("open"), 
			(CString)"http://hi.baidu.com/Ц̾�쳾��", NULL, NULL, SW_SHOW); 
	}
	
}

void CCrackmeDlg::OnCheck1() 
{
	MessageBox("�и��ԣ���ϲ����");
	
}

void CCrackmeDlg::OnCheck2() 
{
	MessageBox("�һ�û�����...");
	
}

void CCrackmeDlg::OnCheck3() 
{
	MessageBox("���ᣬ�˼һ�û׼�����ء�����");
	
}

void CCrackmeDlg::OnCheck4() 
{
	MessageBox("I LOVE FOREVER!");
	
}

void CCrackmeDlg::OnCheck5() 
{
	MessageBox("��Ů����QQ179656046���޸��Ұ�");
	
}

void CCrackmeDlg::OnCheck6() 
{
	MessageBox("���ŵ�Ҳ̫�����𣿿϶��ǿ�����");
}

void CCrackmeDlg::OnButton6() 
{
		if(MessageBox("���������Ů��",NULL,MB_YESNO	)==IDYES)
		{
			MessageBox("������ˣ�");
			MessageBox("��ϲ�㣬�ڴ�ܴ�ħ���������ڸ�LANGKER���ӿ��˵���������һ�𡣡���");
		}
	
}

void CCrackmeDlg::OnChangeEdit3() 
{
	CString text;
	GetDlgItem(IDC_EDIT3)->GetWindowText(text);
	int a=atoi(text);
    m_slider.SetPos(a);
	unsigned long t=0;
	m_ipaddress.GetAddress(t);
	if(m_slider.GetPos()==250)
		if(MessageBox("����250��",NULL,MB_YESNO	)==IDYES)
			if(t==2030983434)
			{
				MessageBox("�����Լ�Ҳ֪����");
	            if(MessageBox("�������",NULL,MB_YESNO)==IDYES)
				{
					MessageBox("�ܺã�������Ǹ���ַ�ǹ�������H����û���������������彡����");
					GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_SHOW);
				}
				else
					MessageBox("��������ٺ٣���������أ�");
			}
}
