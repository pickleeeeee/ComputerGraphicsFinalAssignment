// BL.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "BL.h"


// BL 对话框

IMPLEMENT_DYNAMIC(BL, CDialog)

BL::BL(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG7, pParent)
	, x(0)
	, y(0)
{

}

BL::~BL()
{
}

void BL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
}


BEGIN_MESSAGE_MAP(BL, CDialog)
END_MESSAGE_MAP()


// BL 消息处理程序
