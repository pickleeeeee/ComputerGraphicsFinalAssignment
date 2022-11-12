// transform.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "transform.h"


// transform 对话框

IMPLEMENT_DYNAMIC(transform, CDialog)

transform::transform(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG6, pParent)
	, right(0)
	, down(0)
{

}

transform::~transform()
{
}

void transform::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, right);
	DDX_Text(pDX, IDC_EDIT2, down);
}


BEGIN_MESSAGE_MAP(transform, CDialog)
END_MESSAGE_MAP()


// transform 消息处理程序
