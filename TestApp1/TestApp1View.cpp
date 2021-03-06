
// TestApp1View.cpp : implementation of the CTestApp1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestApp1.h"
#endif

#include "TestApp1Doc.h"
#include "TestApp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestApp1View

IMPLEMENT_DYNCREATE(CTestApp1View, CView)

BEGIN_MESSAGE_MAP(CTestApp1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestApp1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestApp1View construction/destruction

CTestApp1View::CTestApp1View()
{
	// TODO: add construction code here

}

CTestApp1View::~CTestApp1View()
{
}

BOOL CTestApp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestApp1View drawing

void CTestApp1View::OnDraw(CDC* /*pDC*/)
{
	CTestApp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestApp1View printing


void CTestApp1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestApp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestApp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestApp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestApp1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestApp1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestApp1View diagnostics

#ifdef _DEBUG
void CTestApp1View::AssertValid() const
{
	CView::AssertValid();
}

void CTestApp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestApp1Doc* CTestApp1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestApp1Doc)));
	return (CTestApp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CTestApp1View message handlers
