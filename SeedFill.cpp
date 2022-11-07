// SeedFill.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "SeedFill.h"


// SeedFill 对话框

IMPLEMENT_DYNAMIC(SeedFill, CDialog)

SeedFill::SeedFill(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG5, pParent)
	, a(0)
	, edge_R(0)
	, edge_G(0)
	, edge_B(0)
	, fill_R(0)
	, fill_G(0)
	, fill_B(0)
	, x(0)
	, y(0)
{

}

SeedFill::~SeedFill()
{
}

void SeedFill::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT3, edge_R);
	DDV_MinMaxLong(pDX, edge_R, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, edge_G);
	DDV_MinMaxLong(pDX, edge_G, 0, 255);
	DDX_Text(pDX, IDC_EDIT5, edge_B);
	DDV_MinMaxLong(pDX, edge_B, 0, 255);
	DDX_Text(pDX, IDC_EDIT6, fill_R);
	DDV_MinMaxLong(pDX, fill_R, 0, 255);
	DDX_Text(pDX, IDC_EDIT7, fill_G);
	DDV_MinMaxLong(pDX, fill_G, 0, 255);
	DDX_Text(pDX, IDC_EDIT8, fill_B);
	DDV_MinMaxLong(pDX, fill_B, 0, 255);
	DDX_Text(pDX, IDC_EDIT9, x);
	DDX_Text(pDX, IDC_EDIT10, y);
}


BEGIN_MESSAGE_MAP(SeedFill, CDialog)
	ON_BN_CLICKED(IDOK, &SeedFill::OnBnClickedOk)
END_MESSAGE_MAP()


// SeedFill 消息处理程序


void SeedFill::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialog::OnOK();
}
