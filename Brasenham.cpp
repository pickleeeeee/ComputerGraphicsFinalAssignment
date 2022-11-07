// Brasenham.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "Brasenham.h"


// Brasenham 对话框

IMPLEMENT_DYNAMIC(Brasenham, CDialog)

Brasenham::Brasenham(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_Edit1(0)
	, m_Edit2(0)
	, m_Edit3(0)
	, m_Edit4(0)
{

}

Brasenham::~Brasenham()
{
}

void Brasenham::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
	DDX_Text(pDX, IDC_EDIT3, m_Edit3);
	DDX_Text(pDX, IDC_EDIT4, m_Edit4);
}


BEGIN_MESSAGE_MAP(Brasenham, CDialog)
	ON_BN_CLICKED(IDOK, &Brasenham::OnBnClickedOk)
END_MESSAGE_MAP()


// Brasenham 消息处理程序


void Brasenham::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialog::OnOK();
}


