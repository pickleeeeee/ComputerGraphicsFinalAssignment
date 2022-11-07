// MEllipse.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "MEllipse.h"


// MEllipse 对话框

IMPLEMENT_DYNAMIC(MEllipse, CDialog)

MEllipse::MEllipse(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, X(0)
	, Y(0)
	, a(0)
	, b(0)
{

}

MEllipse::~MEllipse()
{
}

void MEllipse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, X);
	DDX_Text(pDX, IDC_EDIT2, Y);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Text(pDX, IDC_EDIT4, b);
}


BEGIN_MESSAGE_MAP(MEllipse, CDialog)
	ON_BN_CLICKED(IDOK, &MEllipse::OnBnClickedOk)
END_MESSAGE_MAP()


// MEllipse 消息处理程序


void MEllipse::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialog::OnOK();
}
