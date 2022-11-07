#pragma once
#include "afxdialogex.h"


// MEllipse 对话框

class MEllipse : public CDialog
{
	DECLARE_DYNAMIC(MEllipse)

public:
	MEllipse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MEllipse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	long X;
	long Y;
	long a;
	long b;
};
