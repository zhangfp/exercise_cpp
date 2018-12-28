
// app1View.cpp : Capp1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "app1.h"
#endif

#include "app1Doc.h"
#include "app1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Capp1View

IMPLEMENT_DYNCREATE(Capp1View, CView)

BEGIN_MESSAGE_MAP(Capp1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Capp1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Capp1View 构造/析构

Capp1View::Capp1View()
{
	// TODO:  在此处添加构造代码

}

Capp1View::~Capp1View()
{
}

BOOL Capp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Capp1View 绘制

void Capp1View::OnDraw(CDC* /*pDC*/)
{
	Capp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Capp1View 打印


void Capp1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Capp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Capp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Capp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void Capp1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Capp1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Capp1View 诊断

#ifdef _DEBUG
void Capp1View::AssertValid() const
{
	CView::AssertValid();
}

void Capp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Capp1Doc* Capp1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Capp1Doc)));
	return (Capp1Doc*)m_pDocument;
}
#endif //_DEBUG


// Capp1View 消息处理程序
