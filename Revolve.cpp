// Revolve.cpp: 实现文件
//

#include "pch.h"
#include "Demo1.h"
#include "afxdialogex.h"
#include "Revolve.h"


// Revolve 对话框

IMPLEMENT_DYNAMIC(Revolve, CDialog)

Revolve::Revolve(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG8, pParent)
	, theta(0)
{

}

Revolve::~Revolve()
{
}

void Revolve::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, theta);
}


BEGIN_MESSAGE_MAP(Revolve, CDialog)
END_MESSAGE_MAP()


// Revolve 消息处理程序
