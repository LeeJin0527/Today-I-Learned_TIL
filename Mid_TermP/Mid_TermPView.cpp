
// Mid_TermPView.cpp: CMidTermPView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Mid_TermP.h"
#endif

#include "Mid_TermPDoc.h"
#include "Mid_TermPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW        
#endif


// CMidTermPView

IMPLEMENT_DYNCREATE(CMidTermPView, CFormView)

BEGIN_MESSAGE_MAP(CMidTermPView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	
	ON_BN_CLICKED(IDC_BUTTON6, &CMidTermPView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_RADIO4, &CMidTermPView::OnBnClickedRed)
	ON_BN_CLICKED(IDC_RADIO5, &CMidTermPView::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMidTermPView::OnBnClickedBlue)
	ON_BN_CLICKED(IDC_RADIO7, &CMidTermPView::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO1, &CMidTermPView::OnBnClickedEllipse)
	ON_BN_CLICKED(IDC_RADIO2, &CMidTermPView::OnBnClickedRectangle)
	ON_BN_CLICKED(IDC_CHECK1, &CMidTermPView::OnBnClickedCheckBox)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RADIO3, &CMidTermPView::OnBnClickedRandomFigure)
	ON_BN_CLICKED(IDC_BUTTON7, &CMidTermPView::OnBnClickedDelAll)
	ON_BN_CLICKED(IDC_BUTTON8, &CMidTermPView::OnBnClickedDelSome)
	ON_BN_CLICKED(IDC_BUTTON4, &CMidTermPView::OnBnClicked3Del)
	ON_BN_CLICKED(IDC_BUTTON5, &CMidTermPView::OnBnClickedErrorDel)
	ON_BN_CLICKED(IDC_BUTTON3, &CMidTermPView::OnBnClickedChangeFigure)
	ON_BN_CLICKED(IDC_BUTTON9, &CMidTermPView::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMidTermPView::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, &CMidTermPView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON11, &CMidTermPView::OnBnClickedButton11)
	ON_LBN_SELCHANGE(IDC_LIST3, &CMidTermPView::OnLbnSelchangeList3)
END_MESSAGE_MAP()

// CMidTermPView 생성/소멸

CMidTermPView::CMidTermPView() noexcept
	: CFormView(IDD_MID_TERMP_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	count = 0;
	for (int i = 0; i < 1000; i++)
		color[i] = RED;
	for (int i = 0; i < 1000; i++)
		figure[i] = ELLIPSE;
	srand((unsigned)time(NULL));
	rc =CRect( 0,0, 787, 1100);
	m_dir = 1;
	x = 200; y = 200;
	m_flag = 0;
}

CMidTermPView::~CMidTermPView()
{
}

void CMidTermPView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_CHECK1, check);
	DDX_Control(pDX, IDC_LIST3, m_list_c);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}

BOOL CMidTermPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMidTermPView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMidTermPView 인쇄

BOOL CMidTermPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMidTermPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMidTermPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMidTermPView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CMidTermPView 진단

#ifdef _DEBUG
void CMidTermPView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMidTermPView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMidTermPDoc* CMidTermPView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMidTermPDoc)));
	return (CMidTermPDoc*)m_pDocument;
}
#endif //_DEBUG


// CMidTermPView 메시지 처리기


//void CMidTermPView::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//
//	CFormView::OnMButtonDown(nFlags, point);
//}


void CMidTermPView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int pos_x, pos_y, state;
	CString str;
	
	pos_x = point.x;
	pos_y = point.y;
	cx[count] = pos_x;
	cy[count] = pos_y;
	state = color[count];
	count++;

	//if ((pos_x >= 0 && pos_x <= 800) && (pos_y >= 0 && pos_y <= 600)) {
		str.Format(L"%d%04d%04d", state, pos_x, pos_y);
		m_list.AddString(str);
	//}
	Invalidate();

	CFormView::OnLButtonDown(nFlags, point);
}


void CMidTermPView::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	int n = m_list.GetCount();
	int m = m_list2.GetCount();
	for (int i = n - 1; i >= 0; i--) {
		if (m_list.GetSel(i)) {
			m_list.GetText(i, str);
			m_list2.AddString(str);
			m_list.DeleteString(i);
			count--;
		}
	}
	for (int i = m - 1; i >= 0; i--) {
		if (m_list2.GetSel(i)) {
			m_list2.GetText(i, str);
			m_list.AddString(str);
			m_list2.DeleteString(i);
			count--;
		}
	}
}


void CMidTermPView::OnDraw(CDC* /*pDC*/)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CClientDC dc(this);
	//CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);
	GetDlgItem(IDC_LIST3)->ShowWindow(SW_HIDE);
	//dc.Rectangle(rc.right / 6.0 * 3.0, 0, rc.right, rc.bottom);
	//dc.Ellipse(x - 200, y - 200, x + 200, y + 200);
	dc.SetTextColor(RGB(255, 0, 0));
	for (int i = 0; i < count; i++) {
		if (color[i] == RED) {
			CBrush bs(RGB(255, 0, 0));
			dc.SelectObject(&bs);
			if (figure[i] == ELLIPSE) {
				dc.Ellipse(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
			}
			if (figure[i] == RECTANGLE) {
				dc.Rectangle(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
			}
		}
		if (color[i] == GREEN) {
			CBrush bs(RGB(0, 255, 0));
			dc.SelectObject(&bs);
			if (figure[i] == ELLIPSE) {
				dc.Ellipse(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
			}
			if (figure[i] == RECTANGLE) {
				dc.Rectangle(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
			}
		}
		if (color[i] == BLUE) {
			CBrush bs(RGB(0, 0, 255));
			dc.SelectObject(&bs);
			if (figure[i] == ELLIPSE) {
				dc.Ellipse(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
			}
			if (figure[i] == RECTANGLE) {
				dc.Rectangle(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
			}
		}
	}
}


void CMidTermPView::OnBnClickedRed()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = count; i < 1000; i++)
		color[i] = RED;
}


void CMidTermPView::OnBnClickedRadio5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = count; i < 1000; i++)
		color[i] = GREEN;
}


void CMidTermPView::OnBnClickedBlue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = count; i < 1000; i++)
		color[i] = BLUE;
}


void CMidTermPView::OnBnClickedRadio7()
//색
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int x = rand() % 3;
	for (int i = count; i < 1000; i++) {
		if (x == 0) {
			color[i] = RED;
		}
		if (x == 1) {
			color[i] = GREEN;
		}
		if (x == 2) {
			color[i] = BLUE;
		}
	}
		
}


void CMidTermPView::OnBnClickedEllipse()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = count; i < 1000; i++)
		figure[i] = ELLIPSE;
}


void CMidTermPView::OnBnClickedRectangle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = count; i < 1000; i++)
		figure[i] =RECTANGLE;
}


void CMidTermPView::OnBnClickedCheckBox()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(0, 200, NULL);
}


void CMidTermPView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!check.GetCheck())
		KillTimer(0);
	if (nIDEvent == 0) {
		int pos_x, pos_y, state, mini, maxi;
		CString str;

		pos_x = rand() % 1601;
		pos_y = rand() % 601;
		cx[count] = pos_x;
		cy[count] = pos_y;
		state = color[count];
		count++;
		str.Format(L"%d%04d%04d", state, pos_x, pos_y);
		m_list.AddString(str);
		Invalidate();
	}
	
	if (nIDEvent == 1) {
		switch (m_dir) {
		case 0:
			y--;
			break;
		case 1:
			x++;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
		}
		Invalidate();
	}

	if (nIDEvent == 2)
	{
		CString str;
		CClientDC dc(this);
		CRect rt;
		GetClientRect(&rt);
		int data;
		int x;
		int y;

		int temp;
		int m;
		int tr;

		for (int i = 0; i < m_list.GetCount(); i++)
		{
			m_list.GetText(i, str);
			data = _ttoi(str);
			unsigned int state = data / 100000000;
			x = (data / 10000) % 10000;
			y = (data / 10000) ;
			m_list.GetText(i, str);
			temp = _ttoi(str);
			//m = temp % 10;
			switch (state)
			{
			case 0:	cy[i] += 5; cx[i] += 5; break;
			case 1:	cy[i] += 5; cx[i] -= 5; break;
			case 2:	cy[i] -= 5; cx[i] -= 5; break;
			case 3: cy[i] -= 5; cx[i] += 5; break;
			}
			str.Format(_T("%4d%04d"), x, y);
			m_list.DeleteString(i);
			m_list.InsertString(i, str);
			str.Format(_T("%d"), x);
			//m_list_c.SetItem(i, 1, LVIF_TEXT, str, 0, 0, 0, NULL);
			str.Format(_T("%d"), y);
			//m_list_c.SetItem(i, 2, LVIF_TEXT, str, 0, 0, 0, NULL);
			

		}

		for (int i = m_list.GetCount() - 1; i >= 0; i--)
		{
			m_list.GetText(i, str);
			data = _ttoi(str);
			y = data % 10000;
			x = data / 10000;

			m_list.GetText(i, str);
			temp = _ttoi(str);
			m = temp % 10;
			tr = temp / 10;
			if (x > rt.right - tr)
				if (m == 0)
					m = 1;
				else
					m = 2;
			if (x < 310 + tr)
				if (m == 2)
					m = 3;
				else
					m = 0;
			if (y > rt.bottom - tr)
				if (m == 0)
					m = 3;
				else
					m = 2;
			if (y < tr)
				if (m == 3)
					m = 0;
				else
					m = 1;

			str.Format(_T("%d%d"), tr, m);
			m_list.DeleteString(i);
			m_list.InsertString(i, str);
		}
		Invalidate();
	}
	
	

	if (nIDEvent == 3) {
		
		int pos_x, pos_y, state, mini, maxi;
		int val;
		CString str;

		val = GetDlgItemInt(IDC_EDIT1);
		//SetDlgItemText(IDC_STATIC1, str);

		if (count == val-1)
			KillTimer(3);

	
		pos_x = rand() % 600 + 800;
		pos_y = rand() % 800 + 150;
		cx[count] = pos_x;
		cy[count] = pos_y;
		state = color[count];

		count++;
			
		
		str.Format(L"%d%04d%04d", state, pos_x, pos_y);
		m_list.AddString(str);
		Invalidate();
	}
	
	
	


	CFormView::OnTimer(nIDEvent);
}


void CMidTermPView::OnBnClickedRandomFigure()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int x = rand() % 2;
	for (int i = count; i < 1000; i++) {
		if (x == 0) {
			figure[i] = ELLIPSE;
		}
		if (x == 1) {
			figure[i] = RECTANGLE;
		}
	}
		
}


void CMidTermPView::OnBnClickedDelAll()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_list.ResetContent();
	m_list2.ResetContent();
	count = 0;
	Invalidate();

}


void CMidTermPView::OnBnClickedDelSome()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int n = m_list.GetCount();
	int m = m_list2.GetCount();
	for (int i = n - 1; i >= 0; i--) {
		if (m_list.GetSel(i)) {
			
			m_list.DeleteString(i);
			count--;
		}
	}
	for (int i = m - 1; i >= 0; i--) {
		if (m_list2.GetSel(i)) {

			m_list2.DeleteString(i);
			count--;
		}
	}
	Invalidate();
}


void CMidTermPView::OnBnClicked3Del()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int n = m_list.GetCount();
	int m = m_list2.GetCount();
	for (int i = n - 1; i >= 0; i--) {
		if (m_list.GetSel(i)) {

			m_list.DeleteString(i);
			count--;
		}
	}
	for (int i = m - 1; i >= 0; i--) {
		if (m_list2.GetSel(i)) {

			m_list2.DeleteString(i);
			count--;
		}
	}
	Invalidate();
}


void CMidTermPView::OnBnClickedErrorDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PAINTSTRUCT ps = { 0, };
	HDC hDC = NULL;

	CClientDC dc(this);
	for (int i = 0; i < count; i++) {
		if (cx[i] <= rc.right/ 6.0 * 3.0 || cx[i] >= rc.right || cy[i] <= 120 || cy[i] >= rc.bottom) {
			count = count - i ;
			count--;
			
		}

	}

	InvalidateRect(rc, true);
	

}
//LRESULT CMidTermPView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
//{
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//	PAINTSTRUCT ps;
//	HDC hdc;
//
//	switch (iMessagInvae)
//	{
//	case WM_PAINT:
//	{
//		hdc = BeginPaint(hWnd, &ps);
//		Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
//		EndPaint(hWnd, &ps);
//	}
//	break;
//
//	case WM_KEYDOWN:
//		switch (wParam)
//		{
//		case VK_LEFT:
//		{
//			_rc.left -= 5;
//			_rc.right -= 5;
//			InvalidateRect(hWnd, NULL, true);
//			break;
//		}
//		case VK_RIGHT:
//		{
//			_rc.left += 5;
//			_rc.right += 5;
//			InvalidateRect(hWnd, NULL, true);
//			break;
//		}
//		}
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return CFormView::WindowProc(message, wParam, lParam);
//}


void CMidTermPView::OnBnClickedChangeFigure()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);

	int n = m_list.GetCount();
	int m = m_list2.GetCount();
	for (int i = n - 1; i >= 0; i--) {
		if (m_list.GetSel(i)) {

			if (color[i] == GREEN) {
				CBrush bs(RGB(0, 255, 0));
				dc.SelectObject(&bs);
				if (figure[i] == ELLIPSE) {
					dc.Rectangle(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
				}
				if (figure[i] == RECTANGLE) {
					dc.Ellipse(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
				}
			}
			if (color[i] ==RED) {
				CBrush bs(RGB(255, 0, 0));
				dc.SelectObject(&bs);
				if (figure[i] == ELLIPSE) {
					dc.Rectangle(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
				}
				if (figure[i] == RECTANGLE) {
					dc.Ellipse(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
				}
			}
			if (color[i] == BLUE) {
				CBrush bs(RGB(0, 0, 255));
				dc.SelectObject(&bs);
				if (figure[i] == ELLIPSE) {
					dc.Rectangle(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
				}
				if (figure[i] == RECTANGLE) {
					dc.Ellipse(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
				}
			}
			count--;
		}
	}
	for (int i = m - 1; i >= 0; i--) {
		if (m_list2.GetSel(i)) {

			if (figure[i] == RECTANGLE) {
				dc.Ellipse(cx[i] - 20, cy[i] - 20, cx[i] + 20, cy[i] + 20);
			}
			count--;
		}
	}
}


BOOL CMidTermPView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->wParam) {
	case VK_UP:	m_dir = 0; Invalidate(); break;
	case VK_RIGHT: m_dir = 1; Invalidate(); break;
	case VK_DOWN: m_dir = 2;  Invalidate(); break;
	case VK_LEFT: m_dir = 3; Invalidate(); break;
	case VK_TAB:

		//GetDlgItem(IDC_BUTTON2)->SetWindowTextW(L"중   지");
		SetDlgItemText(IDC_BUTTON2, L"중 지");
		UpdateData(false);
	}
	return false;
	//return CFormView::PreTranslateMessage(pMsg);
}


void CMidTermPView::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(1, 100, NULL);
}


void CMidTermPView::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_flag = !m_flag;
	SetTimer(2, 100, NULL);
}


void CMidTermPView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	SetTimer(3, 100, NULL);
}


void CMidTermPView::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(2);
}


void CMidTermPView::OnLbnSelchangeList3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_LIST3)->ShowWindow(SW_HIDE);
}
