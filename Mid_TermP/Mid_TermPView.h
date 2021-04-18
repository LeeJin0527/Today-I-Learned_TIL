
// Mid_TermPView.h: CMidTermPView 클래스의 인터페이스
//

#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>

class CMidTermPView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMidTermPView() noexcept;
	DECLARE_DYNCREATE(CMidTermPView)

public:
//#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MID_TERMP_FORM };
	enum COLOR {RED, GREEN,BLUE};
	enum FIGURE { ELLIPSE, RECTANGLE};
//#endif

// 특성입니다.
public:
	CMidTermPDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMidTermPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int cx[1000];
	int cy[1000];
	int color[1000];
	int count;
	CRect rc;
	CListBox m_list;
	CListBox m_list2;
	afx_msg void OnBnClickedButton6();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnBnClickedRed();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedBlue();
	afx_msg void OnBnClickedRadio7();
	int figure[1000];
	afx_msg void OnBnClickedEllipse();
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedCheckBox();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButton check;
	afx_msg void OnBnClickedRandomFigure();
	afx_msg void OnBnClickedDelAll();
	afx_msg void OnBnClickedDelSome();
	afx_msg void OnBnClicked3Del();
	afx_msg void OnBnClickedErrorDel();
//	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedChangeFigure();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_dir;
	int x; 
	int y;
	afx_msg void OnBnClickedButton9();
	int m_flag;
	afx_msg void OnBnClickedButton10();
	CListBox m_list_c;
	CEdit m_Edit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnLbnSelchangeList3();
};

#ifndef _DEBUG  // Mid_TermPView.cpp의 디버그 버전
inline CMidTermPDoc* CMidTermPView::GetDocument() const
   { return reinterpret_cast<CMidTermPDoc*>(m_pDocument); }
#endif

