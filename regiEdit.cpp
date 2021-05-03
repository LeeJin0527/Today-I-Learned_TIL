
// MFCApplication6View.cpp: CMFCApplication6View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication6.h"
#endif

#include "MFCApplication6Doc.h"
#include "MFCApplication6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication6View

IMPLEMENT_DYNCREATE(CMFCApplication6View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication6View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication6View 생성/소멸

CMFCApplication6View::CMFCApplication6View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication6View::~CMFCApplication6View()
{
}

BOOL CMFCApplication6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication6View 그리기

void CMFCApplication6View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCApplication6View 인쇄

BOOL CMFCApplication6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication6View 진단

#ifdef _DEBUG
void CMFCApplication6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication6Doc* CMFCApplication6View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication6Doc)));
	return (CMFCApplication6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication6View 메시지 처리기
#include <string>

void CMFCApplication6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	HKEY hkSub;
	DWORD dwDisposition;
	int key_num = 0;

	// 해당 경로의 레지스트리를 open 한다.
	// 레지스트리를 성공적으로 open 하였다면 ERROR_SUCCESS값이 WAREOreg 에 저장된다.
	LONG lRes = RegOpenKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\GNU", 0L, KEY_WRITE, &hkSub);
	if (ERROR_SUCCESS != lRes) {
		// 레지스트리를 열지 못했다면 새로 생성한다.
		lRes = RegCreateKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\GNU", 0, L"", 0,
			KEY_READ | KEY_WRITE, NULL, &hkSub, &dwDisposition);
		if (ERROR_SUCCESS != lRes) return;
	}

	// 키 값을 입력한다.
	
		lRes = RegSetValueEx(hkSub, L"AAA", 0, REG_DWORD, (BYTE*)&key_num, sizeof(int));
		if (lRes == ERROR_SUCCESS) MessageBox(L"등록 성공");
		else MessageBox(L"등록 실패");
	
	RegCloseKey(hkSub);



	CView::OnLButtonDown(nFlags, point);
}
