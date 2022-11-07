// Circle.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "Circle.h"


// Circle 对话框

IMPLEMENT_DYNAMIC(Circle, CDialog)

Circle::Circle(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, X(0)
	, Y(0)
	, R(0)
{

}

Circle::~Circle()
{
}

void Circle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, X);
	DDX_Text(pDX, IDC_EDIT2, Y);
	DDX_Text(pDX, IDC_EDIT3, R);
}


BEGIN_MESSAGE_MAP(Circle, CDialog)
	ON_BN_CLICKED(IDOK, &Circle::OnBnClickedOk)
END_MESSAGE_MAP()


// Circle 消息处理程序


void Circle::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialog::OnOK();
}
