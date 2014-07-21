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
		MessageBox("你丫的真狡猾，居然没被老衲骗？");
	else if(code=="fuckyouhappyme!!!")
	{
		MessageBox("哈哈，你失败了！");
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
	if(char1=="作者"&&char2=="真"&&char3=="TMD"&&char4=="帅"&&!m_cool)
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
		MessageBox("cool!再次破解成功!朕没看错人啊！");
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
		MessageBox("那个网上不了了吧？现在在给你一个！");
		MessageBox("恭喜你打倒罪恶的LANGKER，跟美丽的公主幸福的生活在了一起！");
		GetDlgItem(IDC_BUTTON7)->ShowWindow(SW_SHOW);
	}
}

void CCrackmeDlg::OnButton7() 
{
	MessageBox("langker个人作品，\n纯属恶搞，只为博君一笑。。。");
	if(MessageBox("去我博客看看？",NULL,MB_YESNO	)==IDYES)
	{
		ShellExecute(GetParent()->GetSafeHwnd(), _T("open"), 
			(CString)"http://hi.baidu.com/笑叹红尘破", NULL, NULL, SW_SHOW); 
	}
	
}

void CCrackmeDlg::OnCheck1() 
{
	MessageBox("有个性，我喜欢！");
	
}

void CCrackmeDlg::OnCheck2() 
{
	MessageBox("我还没结婚呢...");
	
}

void CCrackmeDlg::OnCheck3() 
{
	MessageBox("讨厌，人家还没准备好呢。。。");
	
}

void CCrackmeDlg::OnCheck4() 
{
	MessageBox("I LOVE FOREVER!");
	
}

void CCrackmeDlg::OnCheck5() 
{
	MessageBox("美女，我QQ179656046，嫁给我吧");
	
}

void CCrackmeDlg::OnCheck6() 
{
	MessageBox("你优点也太多了吗？肯定是恐龙！");
}

void CCrackmeDlg::OnButton6() 
{
		if(MessageBox("你真的是美女吗？",NULL,MB_YESNO	)==IDYES)
		{
			MessageBox("你过关了！");
			MessageBox("恭喜你，在打败大魔王后，你终于跟LANGKER王子快了的生活在了一起。。。");
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
		if(MessageBox("你是250吗？",NULL,MB_YESNO	)==IDYES)
			if(t==2030983434)
			{
				MessageBox("不错，自己也知道啊");
	            if(MessageBox("你猥琐吗？",NULL,MB_YESNO)==IDYES)
				{
					MessageBox("很好，你填的那个地址是国内最大的H网，没事上上有利于身体健康！");
					GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_SHOW);
				}
				else
					MessageBox("不猥琐？嘿嘿，不让你过关！");
			}
}
