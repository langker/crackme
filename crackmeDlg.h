// crackmeDlg.h : header file
//

#if !defined(AFX_CRACKMEDLG_H__02703211_1117_4163_BB49_FFAE68683944__INCLUDED_)
#define AFX_CRACKMEDLG_H__02703211_1117_4163_BB49_FFAE68683944__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCrackmeDlg dialog

class CCrackmeDlg : public CDialog
{
// Construction
public:
	CCrackmeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCrackmeDlg)
	enum { IDD = IDD_CRACKME_DIALOG };
	CIPAddressCtrl	m_ipaddress;
	CSliderCtrl	m_slider;
	int		m_cool;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrackmeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCrackmeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEdit1();
	afx_msg void OnButton3();
	afx_msg void OnChangeEdit5();
	afx_msg void OnButton4();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton5();
	afx_msg void OnButton7();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnButton6();
	afx_msg void OnChangeEdit3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRACKMEDLG_H__02703211_1117_4163_BB49_FFAE68683944__INCLUDED_)
