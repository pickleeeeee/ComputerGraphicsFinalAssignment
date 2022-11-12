#pragma once
#include "afxdialogex.h"


// Revolve 对话框

class Revolve : public CDialog
{
	DECLARE_DYNAMIC(Revolve)

public:
	Revolve(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Revolve();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long theta;
};
