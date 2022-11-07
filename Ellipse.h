#pragma once
#include "afxdialogex.h"


// Ellipse 对话框

class Ellipse : public CDialog
{
	DECLARE_DYNAMIC(Ellipse)

public:
	Ellipse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Ellipse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long X;
	long Y;
	long a;
	long b;
	afx_msg void OnBnClickedOk();
};
