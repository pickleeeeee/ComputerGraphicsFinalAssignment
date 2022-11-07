#pragma once
#include "afxdialogex.h"


// SeedFill 对话框

class SeedFill : public CDialog
{
	DECLARE_DYNAMIC(SeedFill)

public:
	SeedFill(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SeedFill();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long a;
//	long b;
	long edge_R;
	long edge_G;
	long edge_B;
	long fill_R;
	long fill_G;
	long fill_B;
	long x;
	long y;
	afx_msg void OnBnClickedOk();
};
