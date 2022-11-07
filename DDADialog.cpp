// DDADialog.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "DDADialog.h"


// DDADialog 对话框

IMPLEMENT_DYNAMIC(DDADialog, CDialog)

DDADialog::DDADialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DDA, pParent)
	, m_Edit1(0)
	, m_Edit2(0)
	, m_Edit3(0)
	, m_Edit4(0)
{

}

DDADialog::~DDADialog()
{
}

void DDADialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
	DDX_Text(pDX, IDC_EDIT3, m_Edit3);
	DDX_Text(pDX, IDC_EDIT4, m_Edit4);
}


BEGIN_MESSAGE_MAP(DDADialog, CDialog)
	ON_BN_CLICKED(IDOK, &DDADialog::OnBnClickedOk)
END_MESSAGE_MAP()


// DDADialog 消息处理程序


void DDADialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialog::OnOK();
}

