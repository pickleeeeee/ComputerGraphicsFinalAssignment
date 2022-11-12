
// Demo1View.h: CDemo1View 类的接口
//

#pragma once

#define AA 40
#define BB 200


class CDemo1View : public CView
{
protected: // 仅从序列化创建
	CDemo1View() noexcept;
	DECLARE_DYNCREATE(CDemo1View)

// 特性
public:
	CDemo1Doc* GetDocument() const;
	double points[4][3];

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDemo1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAlgorithmDda();
	afx_msg void OnAlgorithmBresenham();
	afx_msg void OnAlgorithmBresenhamplus();
	afx_msg void OnAlgorithmCircle();
	afx_msg void OnAlgorithmEllipse();
	afx_msg void OnXscan32777();
	afx_msg void OnXscan32778();
	afx_msg void On32780();
	afx_msg void On32781();
	afx_msg void On32783();
	afx_msg void On32784();
	afx_msg void On32785();
	afx_msg void On32786();
	afx_msg void On32787();
};

#ifndef _DEBUG  // Demo1View.cpp 中的调试版本
inline CDemo1Doc* CDemo1View::GetDocument() const
   { return reinterpret_cast<CDemo1Doc*>(m_pDocument); }
#endif

