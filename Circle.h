#pragma once
#include "afxdialogex.h"


// Circle 对话框

class Circle : public CDialog
{
	DECLARE_DYNAMIC(Circle)

public:
	Circle(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Circle();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long X;
	long Y;
	long R;
	afx_msg void OnBnClickedOk();
};
