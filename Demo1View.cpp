
// Demo1View.cpp: CDemo1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Demo1.h"
#endif

#include "Demo1Doc.h"
#include "Demo1View.h"
#include "DDADialog.h"
#include "Brasenham.h"
#include "BresenhamPlus.h"
#include "Circle.h"
#include "MEllipse.h"
#include <vector>
#include "SeedFill.h"
#include <queue>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemo1View

IMPLEMENT_DYNCREATE(CDemo1View, CView)

BEGIN_MESSAGE_MAP(CDemo1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDemo1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ALGORITHM_DDA, &CDemo1View::OnAlgorithmDda)
	ON_COMMAND(ID_ALGORITHM_BRESENHAM, &CDemo1View::OnAlgorithmBresenham)
	ON_COMMAND(ID_ALGORITHM_BRESENHAMPLUS, &CDemo1View::OnAlgorithmBresenhamplus)
	ON_COMMAND(ID_ALGORITHM_CIRCLE, &CDemo1View::OnAlgorithmCircle)
	ON_COMMAND(ID_ALGORITHM_ELLIPSE, &CDemo1View::OnAlgorithmEllipse)
	ON_COMMAND(ID_XSCAN_32777, &CDemo1View::OnXscan32777)
	ON_COMMAND(ID_XSCAN_32778, &CDemo1View::OnXscan32778)
	ON_COMMAND(ID_32780, &CDemo1View::On32780)
	ON_COMMAND(ID_32781, &CDemo1View::On32781)
END_MESSAGE_MAP()

// CDemo1View 构造/析构

CDemo1View::CDemo1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CDemo1View::~CDemo1View()
{
}

BOOL CDemo1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemo1View 绘图

void CDemo1View::OnDraw(CDC* /*pDC*/)
{
	CDemo1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDemo1View 打印


void CDemo1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDemo1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemo1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemo1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDemo1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDemo1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDemo1View 诊断

#ifdef _DEBUG
void CDemo1View::AssertValid() const
{
	CView::AssertValid();
}

void CDemo1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemo1Doc* CDemo1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemo1Doc)));
	return (CDemo1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemo1View 消息处理程序




/*
* DDA算法实现
*/
void CDemo1View::OnAlgorithmDda()
{
	// TODO: 在此添加命令处理程序代码
	DDADialog dlg; //生成对话框对象
	dlg.DoModal();//显示对话框
	CClientDC dc(this);//生成设备环境对象，获取设备环境

	CPoint p1(dlg.m_Edit1, dlg.m_Edit2);		
	CPoint p2(dlg.m_Edit3, dlg.m_Edit4);

	COLORREF color(RGB(255,0,0));

	CPoint start = p1;
	CPoint end = p2;

	double k = (double)(end.y - start.y) / (end.x - start.x);

	//垂直直线
	if (start.x == end.x) {
		if (start.y > end.y) {
			start = p2;
			end = p1;
		}
		while (start.y <= end.y) {
			dc.SetPixel(start, color);
			start.y++;
		}
	}
	//水平直线
	else if (start.y == end.y) {
		if (start.x > end.x) {
			start = p2;
			end = p1;
		}
		while (start.x <= end.x) {
			dc.SetPixel(start, color);
			start.x++;
		}
	}
	//斜率绝对值小于1时的直线扫描
	/*
	* 选择x为步进方向，由两个点中较小的为起点，x+1，y+k
	*/
	else if (k<1 && k>-1) {
		if (start.x > end.x) {
			start = p2;
			end = p1;
		}
		double y = start.y;
		while (start.x <= end.x) {
			dc.SetPixel(start, color);
			start.x++;
			y += k;
			start.y = y + 0.5;
		}
	}
	//斜率绝对值大于一的情况
	else {
		if (start.y > end.y) {
			start = p2;
			end = p1;
		}
		double x = start.x;
		while (start.y <= end.y) {
			dc.SetPixel(start, color);
			start.y++;
			x += 1 / k;
			start.x = x + 0.5;
		}
	}
	return;
}

/*
* 中点Bresenham算法实现
*/
void CDemo1View::OnAlgorithmBresenham()
{
	// TODO: 在此添加命令处理程序代码
	Brasenham br;
	br.DoModal();

	CClientDC dc(this);//生成设备环境对象，获取设备环境

	CPoint p1(br.m_Edit1, br.m_Edit2);
	CPoint p2(br.m_Edit3, br.m_Edit4);

	COLORREF color(RGB(255, 0, 0));

	CPoint start = p1;
	CPoint end = p2;

	//求出斜率
	double k = (double)(end.y - start.y) / (end.x - start.x);

	//垂直直线
	if (start.x == end.x) {
		if (start.y > end.y) {
			start = p2;
			end = p1;
		}
		while (start.y <= end.y) {
			dc.SetPixel(start, color);
			start.y++;
		}
	}
	//水平直线
	else if (start.y == end.y) {
		if (start.x > end.x) {
			start = p2;
			end = p1;
		}
		while (start.x <= end.x) {
			dc.SetPixel(start, color);
			start.x++;
		}
	}

	//左面移动到右面
	if (start.x > end.x) {
		start = p2;
		end = p1;
	}
	//判断k的大小
	if (k >= -1 && k <= 1) {
		if (k > 0) {
			int dx = end.x - start.x;
			int dy = end.y - start.y;
			int d = 2 * dy - dx;
			int incrNE = 2 * dy - 2 * dx;
			int incrE = 2 * dy;
			while (start.x < end.x) {
				dc.SetPixel(start, RGB(255, 0, 0));
				start.x++;
				if (d > 0) {
					start.y++;
					d += incrNE;
				}
				else {
					d += incrE;
				}
			}
		}
		else {
			//-1<k<0
			//y取反
			if (k < 0) {
				start.y = -1 * start.y;
				end.y = -1 * end.y;
				int dx = end.x - start.x;
				int dy = end.y - start.y;
				int d = 2 * dy - dx;
				int incrNE = 2 * dy - 2 * dx;
				int incrE = 2 * dy;
				while (start.x < end.x) {
					start.y *= -1;
					dc.SetPixel(start, RGB(255, 0, 0));
					start.y *= -1;
					start.x++;
					if (d > 0) {
						start.y++;
						d += incrNE;
					}
					else {
						d += incrE;
					}
				}
			}
		}
	}
	else {
		if (k > 1) {
			//调换xy但是打印的时候不调换
			int dy = end.x - start.x;
			int dx = end.y - start.y;
			int d = 2 * dy - dx;
			int incrNE = 2 * dy - 2 * dx;
			int incrE = 2 * dy;
			while (start.y < end.y) {
				dc.SetPixel(start, RGB(255, 0, 0));
				start.y++;
				if (d > 0) {
					start.x++;
					d += incrNE;
				}
				else {
					d += incrE;
				}
			}
		}
		else {
			//xy互换并且y取反
			if (k < -1) {
				start.y = -1 * start.y;
				end.y = -1 * end.y;
				int dy = end.x - start.x;
				int dx = end.y - start.y;
				int d = 2 * dy - dx;
				int incrNE = 2 * dy - 2 * dx;
				int incrE = 2 * dy;
				while (start.y < end.y) {
					start.y *= -1;
					dc.SetPixel(start, RGB(255, 0, 0));
					start.y *= -1;
					start.y++;
					if (d > 0) {
						start.x++;
						d += incrNE;
					}
					else {
						d += incrE;
					}
				}
			}
		}
	}
}

/*
* 改进Bresenham算法
*/
void CDemo1View::OnAlgorithmBresenhamplus()
{
	// TODO: 在此添加命令处理程序代码
	BresenhamPlus bp;
	bp.DoModal();

	CClientDC dc(this);//生成设备环境对象，获取设备环境

	CPoint p1(bp.m_Edit1, bp.m_Edit2);
	CPoint p2(bp.m_Edit3, bp.m_Edit4);

	COLORREF color(RGB(255, 0, 0));

	CPoint start = p1;
	CPoint end = p2;

	//求出斜率
	double k = (double)(end.y - start.y) / (end.x - start.x);


	//垂直直线
	if (start.x == end.x) {
		if (start.y > end.y) {
			start = p2;
			end = p1;
		}
		while (start.y <= end.y) {
			dc.SetPixel(start, color);
			start.y++;
		}
	}
	//水平直线
	else if (start.y == end.y) {
		if (start.x > end.x) {
			start = p2;
			end = p1;
		}
		while (start.x <= end.x) {
			dc.SetPixel(start, color);
			start.x++;
		}
	}

	//左面移动到右面
	if (start.x > end.x) {
		start = p2;
		end = p1;
	}
	


	//判断k的大小
	if (k >= -1 && k <= 1) {
		if (k > 0) {
			int dx = end.x - start.x;
			int dy = end.y - start.y;
			int e = -dx;
			while (start.x < end.x) {
				start.x++;
				e += 2*dy;
				if (e > 0) {
					start.y++;
					e -= 2 * dx;
				}
				dc.SetPixel(start, RGB(255, 0, 0));
			}
		}
		else {
			//-1<k<0
			//y取反
			if (k < 0) {
				start.y = -1 * start.y;
				end.y = -1 * end.y;
				int dx = end.x - start.x;
				int dy = end.y - start.y;
				int e = -dx;
				while (start.x < end.x) {
					start.x++;
					e += 2 * dy;
					if (e > 0) {
						start.y++;
						e -= 2 * dx;
					}
					start.y *= -1;
					dc.SetPixel(start, RGB(255, 0, 0));
					start.y *= -1;
				}
			}
		}
	}
	else {
		if (k > 1) {
			//调换xy但是打印的时候不调换
			int dy = end.x - start.x;
			int dx = end.y - start.y;
			int e = -dx;
			while (start.y < end.y) {
				start.y++;
				e += 2 * dy;
				if (e > 0) {
					start.x++;
					e -= 2 * dx;
				}
				dc.SetPixel(start, RGB(255, 0, 0));
			}
		}
		else {
			//xy互换并且y取反
			if (k < -1) {
				start.y = -1 * start.y;
				end.y = -1 * end.y;
				int dy = end.x - start.x;
				int dx = end.y - start.y;
				int e = -dx;
				while (start.y < end.y) {
					e += 2 * dy;
					start.y++;
					if (e > 0) {
						start.x++;
						e -= 2 * dx;
					}
					start.y *= -1;
					dc.SetPixel(start, RGB(255, 0, 0));
					start.y *= -1;
				}
			}
		}
	}

}

/*
* 八分法画圆
*/
void MidBresenhamCircle(CClientDC& dc, COLORREF color,int r,CPoint center) {
	int x, y, e;
	//这里的e相当于d-0.25
	//d<0 相当于 e<-0.25 但是e开始是整数，加减运算也是整数运算所以<-0.25相当于<0,二者在e恒为整数的时候等价
	x = 0; y = r; e = 1 - r;
	while (x <= y) {
		dc.SetPixel(x + center.x, y + center.y, color);
		dc.SetPixel(-x + center.x, y + center.y, color);
		dc.SetPixel(x + center.x, -y + center.y, color);
		dc.SetPixel(-x + center.x, -y + center.y, color);
		dc.SetPixel(y + center.x, x + center.y, color);
		dc.SetPixel(-y + center.x, x + center.y, color);
		dc.SetPixel(y + center.x, -x + center.y, color);
		dc.SetPixel(-y + center.x, -x + center.y, color);

		if (e < 0) {
			e += 2 * x + 3;
		}
		else {
			e += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}
void CDemo1View::OnAlgorithmCircle()
{
	// TODO: 在此添加命令处理程序代码
	Circle circle;
	circle.DoModal();
	
	CClientDC dc(this);

	CPoint center(circle.X, circle.Y);

	COLORREF color(RGB(255, 0, 0));

	MidBresenhamCircle(dc, color, circle.R, center);
}

/*
* 中点Bresenham画椭圆
*/
void MidBresenhamEllipse(CClientDC& dc,int a, int b, int color,CPoint center) {
	int x, y;
	float d1, d2;
	x = 0; y = b;
	d1 = b * b + a * a * (-b + 0.25);
	while (b * b * (x + 1) < a * a* (y - 0.5)) {
		if (d1 <= 0) {
			d1 += b * b * (2 * x + 3);
			x++;
		}
		else {
			d1 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);		
			x++, y--;
		}
		dc.SetPixel(x + center.x,y + center.y,color);
		dc.SetPixel(x + center.x, -y + center.y, color);
		dc.SetPixel(-x + center.x, y + center.y, color);
		dc.SetPixel(-x + center.x, -y + center.y, color);
		
	}
	d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
	while (y > 0) {
		if (d2 <= 0) {
			d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
			x++; y--;
		}
		else {
			d2 += a * a * (-2 * y + 3);
			y--;
		}
		dc.SetPixel(x + center.x, y + center.y, color);
		dc.SetPixel(x + center.x, -y + center.y, color);
		dc.SetPixel(-x + center.x, y + center.y, color);
		dc.SetPixel(-x + center.x, -y + center.y, color);
	}

}
void CDemo1View::OnAlgorithmEllipse()
{
	// TODO: 在此添加命令处理程序代码
	MEllipse mp;
	mp.DoModal();
	CClientDC dc(this);
	COLORREF color(RGB(255, 0, 0));
	CPoint p1(mp.X, mp.Y);
	int a = mp.a;
	int b = mp.b;
	MidBresenhamEllipse(dc, a, b, color, p1);
}


/*
* x-scan 
*/
const int windowHeight = 1800;
const int windowWidth = 1200;
class Edge {
public:
	int ymax;
	float x;
	float dx;	//y+1 x每次的增量
	Edge* next;
};
//边表
Edge* ET[windowHeight];
//活动边表
Edge* AET;
//Demo4 箭头
std::vector<CPoint> vertices_jt = { CPoint(395/2, 887/2), CPoint(479/2, 998/2), CPoint(1199/2, 433/2), CPoint(1101/2, 867/2), CPoint(1294/2, 715/2), CPoint(1417/2, 171/2), CPoint(857/2, 163/2), CPoint(668/2, 314/2), CPoint(1111/2, 321/2) };
//Demo5 闪电
std::vector<CPoint> vertices_sd = { CPoint(117.4852*2,81.25429 * 2), CPoint(92.85692 * 2,104.5632 * 2), CPoint(117.04541 * 2,160.41662 * 2), CPoint(158.38573 * 2,134.46897 * 2), CPoint(164.5428 * 2,176.24908 * 2), CPoint(190.05067 * 2,165.25432 * 2), CPoint(207.2025 * 2,205.71506 * 2), CPoint(205.44334 * 2,145.02394 * 2), CPoint(182.13443 * 2,153.81976 * 2), CPoint(174.2182 * 2,95.76738 * 2), CPoint(134.19725 * 2,123.4742 * 2) };
void polygonScan(CClientDC& dc, COLORREF color, std::vector <CPoint> vertices) {

	//计算最高点的y坐标
	int maxY = 0;
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].y > maxY) {
			maxY = vertices[i].y;
		}
	}

	//初始化ET和AET
	Edge* pET[windowHeight];
	for (int i = 0; i < maxY; i++) {
		pET[i] = new Edge();
		pET[i]->next = nullptr;
	}
	AET = new Edge();
	AET->next = nullptr;

	//建立边表ET
	for (int i = 0; i < vertices.size(); i++) {
		//取出当前点前后相邻的四个点（假设当前点是1，取0123） 点1到点2作为本次加入的边，点0和点3用于计算奇点
		int x0 = vertices[(i - 1 + vertices.size()) % vertices.size()].x;
		int y0 = vertices[(i - 1 + vertices.size()) % vertices.size()].y;
		int x1 = vertices[i].x;
		int y1 = vertices[i].y;
		int x2 = vertices[(i + 1) % vertices.size()].x;
		int y2 = vertices[(i + 1) % vertices.size()].y;
		int x3 = vertices[(i + 2) % vertices.size()].x;
		int y3 = vertices[(i + 2) % vertices.size()].y;
		//水平线舍弃
		if (y1 == y2) {
			continue;
		}
		int ymin = y1 > y2 ? y2 : y1;
		int ymax = y1 > y2 ? y1 : y2;
		float x = y1 > y2 ? x2 : x1;
		float dx = (x1 - x2) * 1.0f / (y1 - y2);//x每次的增量
		//处理边的两端
		//奇点处理，若2->1->0的y坐标单调递减则y1为奇点，若点1->2->3y的坐标单调递减则y2为奇点
		if (((y1<y2) && (y1>y0))||((y2<y1) && (y2>y3))){
			ymin++;
			x += dx;
		}
		//创建新边
		Edge* p = new Edge();
		p->ymax = ymax;
		p->x = x;
		p->dx = dx;
		//头插法
		p->next = pET[ymin]->next;
		pET[ymin]->next = p;
	}

	//扫描线从下往上扫描，y坐标每次加1
	for (int i = 0; i < maxY; i++) {

		//用ET中的值按一定顺序加入AET中

		while (pET[i]->next) {
			//取出ET表中当前扫描行表头位置的边
			Edge* pInsert = pET[i]->next;

			//p 作为AET的移动索引
			Edge* p = AET;
			//在AET中搜索合适的插入位置,AET中的边的顺序按照x从小到大的顺序排序，如果x相等按照dx从小到大
			while (p->next) {
				if (pInsert->x > p->next->x) {
					p = p->next;
					continue;
				}
				if (pInsert->x == p->next->x && pInsert->dx > p->next->dx) {
					p = p->next;
					continue;
				}
				break;
			}
			//将pInsert从ET中删除，并且插入AET的当前位置
			//删除
			pET[i]->next = pInsert->next;
			//添加
			pInsert->next = p->next;
			p->next = pInsert;
		}
		//AET中的边两两配对并填色
		Edge* p = AET;
		while (p->next && p->next->next) {
			for (int x = p->next->x; x < p->next->next->x; x++) {
				//i表示当前是第i行
				dc.SetPixel(CPoint(x,i),color);
			}
			p = p->next->next;
		}
		//删除AET中满足y=ymax的边
		p = AET;
		while (p->next) {
			if (p->next->ymax == i) {
				Edge* pDelete = p->next;
				p->next = pDelete->next;
				pDelete->next = nullptr;
				delete pDelete;
			}
			else {
				p = p->next;
			}
		}
		//更新AET中边的X值，进入下一循环
		p = AET;
		while (p->next) {
			p->next->x += p->next->dx;
			p = p->next;
		}
	}
}
//x-scan 箭头
void CDemo1View::OnXscan32777()
{
	CClientDC dc(this);
	COLORREF color(RGB(255, 0, 150));
	polygonScan(dc, color, vertices_jt);
}
//x-scan 闪电
void CDemo1View::OnXscan32778()
{
	CClientDC dc(this);
	COLORREF color(RGB(255, 0, 150));
	polygonScan(dc, color, vertices_sd);
}


/*
* 四邻域-边界表示种子填充算法
*/
void seed_filling4(CClientDC& dc,int x, int y, COLORREF fill_color, COLORREF edge_color) {
	std::queue<std::pair<int, int>>qpt;
	qpt.push(std::pair<int, int>(x, y));
	while (!qpt.empty()) {
		std::pair<int, int> pnow;
		pnow = qpt.front();
		qpt.pop();
		COLORREF color = dc.GetPixel(pnow.first, pnow.second);
		if ((color != edge_color) && (color != fill_color)) {
			dc.SetPixel(pnow.first, pnow.second, fill_color);
			qpt.push(std::pair<int, int>(pnow.first - 1,pnow.second));
			qpt.push(std::pair<int, int>(pnow.first, pnow.second + 1));
			qpt.push(std::pair<int, int>(pnow.first + 1, pnow.second));
			qpt.push(std::pair<int, int>(pnow.first, pnow.second-1));
		}

	}
}

/*
* 八邻域-边界表示种子填充算法
*/
void seed_filling8(CClientDC& dc, int x, int y, COLORREF fill_color, COLORREF edge_color) {
	std::queue<std::pair<int, int>>qpt;
	qpt.push(std::pair<int, int>(x, y));
	while (!qpt.empty()) {
		std::pair<int, int> pnow;
		pnow = qpt.front();
		qpt.pop();
		COLORREF color = dc.GetPixel(pnow.first, pnow.second);
		if ((color != edge_color) && (color != fill_color)) {
			dc.SetPixel(pnow.first, pnow.second, fill_color);
			qpt.push(std::pair<int, int>(pnow.first - 1, pnow.second));//left
			qpt.push(std::pair<int, int>(pnow.first, pnow.second + 1));//top
			qpt.push(std::pair<int, int>(pnow.first + 1, pnow.second));//right
			qpt.push(std::pair<int, int>(pnow.first, pnow.second - 1));//bottom
			qpt.push(std::pair<int, int>(pnow.first - 1, pnow.second + 1));//left+top
			qpt.push(std::pair<int, int>(pnow.first + 1, pnow.second + 1));//right+top
			qpt.push(std::pair<int, int>(pnow.first + 1, pnow.second - 1));//right+bottom
			qpt.push(std::pair<int, int>(pnow.first - 1, pnow.second - 1));//bottom=left
		}

	}
}
void CDemo1View::On32780()
{
	SeedFill sf;
	sf.DoModal();
	CClientDC dc(this);
	int a = sf.a;
	CPoint center(sf.x, sf.y);
	COLORREF edge_color(RGB(sf.edge_R, sf.edge_G, sf.edge_B));
	COLORREF fill_color(RGB(sf.fill_R, sf.fill_G, sf.fill_B));
	MidBresenhamCircle(dc,edge_color,a,center);
	seed_filling4(dc,sf.x, sf.y, fill_color, edge_color);
}


void CDemo1View::On32781()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CPen pen(PS_SOLID,10, RGB(255,0,0));
	dc.Rectangle(100, 100, 200, 200);
	seed_filling8(dc, 150, 150, RGB(0,255,0), RGB(255, 0, 0));
}
