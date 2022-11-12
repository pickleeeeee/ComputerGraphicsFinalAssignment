#pragma once
#include "afxdialogex.h"


// transform 对话框

class transform : public CDialog
{
	DECLARE_DYNAMIC(transform)

public:
	transform(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~transform();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long right;
	long down;
};
