#pragma once
#include "afxdialogex.h"


// DDADialog 对话框

class DDADialog : public CDialog
{
	DECLARE_DYNAMIC(DDADialog)

public:
	DDADialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DDADialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DDA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long m_Edit1;
	long m_Edit2;
	long m_Edit3;
	long m_Edit4;
	afx_msg void OnBnClickedOk();
};
