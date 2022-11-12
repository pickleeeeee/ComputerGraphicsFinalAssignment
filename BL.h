#pragma once
#include "afxdialogex.h"


// BL 对话框

class BL : public CDialog
{
	DECLARE_DYNAMIC(BL)

public:
	BL(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BL();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long x;
	long y;
};
