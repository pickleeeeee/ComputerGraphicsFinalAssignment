// Ellipse.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "Ellipse.h"


// Ellipse 对话框

IMPLEMENT_DYNAMIC(Ellipse, CDialog)

Ellipse::Ellipse(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, X(0)
	, Y(0)
	, a(0)
	, b(0)
{

}

Ellipse::~Ellipse()
{
}

void Ellipse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, X);
	DDX_Text(pDX, IDC_EDIT5, Y);
	DDX_Text(pDX, IDC_EDIT6, a);
	DDX_Text(pDX, IDC_EDIT7, b);
}


BEGIN_MESSAGE_MAP(Ellipse, CDialog)
	ON_BN_CLICKED(IDOK, &Ellipse::OnBnClickedOk)
END_MESSAGE_MAP()




void Ellipse::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialog::OnOK();
}
