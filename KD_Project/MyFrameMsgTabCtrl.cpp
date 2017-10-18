// MyFrameMsgTabCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "KD_Project.h"
#include "MyFrameMsgTabCtrl.h"


// CMyFrameMsgTabCtrl

IMPLEMENT_DYNAMIC(CMyFrameMsgTabCtrl, CTabCtrl)

CMyFrameMsgTabCtrl::CMyFrameMsgTabCtrl()
{

}

CMyFrameMsgTabCtrl::~CMyFrameMsgTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyFrameMsgTabCtrl, CTabCtrl)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CMyFrameMsgTabCtrl 消息处理程序




int CMyFrameMsgTabCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTabCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CRect rectDummy , rt;
	rectDummy.SetRectEmpty(); 
	m_ctrlMssage.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_OWNERDRAWFIXED,rectDummy,this,IDC_LISTXINXI);
	m_ctrlMssage.InsertColumn(0,_T("时间"),LVCFMT_LEFT,160);
	m_ctrlMssage.InsertColumn(1,_T("信息"),LVCFMT_LEFT,600);
	m_ctrlMssage.InsertColumn(2,_T("结果"),LVCFMT_CENTER,80);
	m_ctrlMssage.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ctrlMssage.m_nChooseList = 0;

	m_ctrlFrame.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_OWNERDRAWFIXED,rectDummy,this,IDC_LISTXINXI);
	m_ctrlFrame.GetWindowRect(rt);
	m_ctrlFrame.InsertColumn(0,_T("时间"),LVCFMT_LEFT,160);
	m_ctrlFrame.InsertColumn(1,_T("收发"),LVCFMT_LEFT,50);
	m_ctrlFrame.InsertColumn(2,_T("报文"),LVCFMT_LEFT,1200);
	m_ctrlFrame.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ctrlFrame.ShowWindow(SW_HIDE);
	m_ctrlFrame.m_nChooseList = 1;
	return 0;
}


void CMyFrameMsgTabCtrl::OnSize(UINT nType, int cx, int cy)
{
	CTabCtrl::OnSize(nType, cx, cy);
	CRect rectClient;
	GetClientRect(rectClient); 
	m_ctrlMssage.SetWindowPos(NULL, rectClient.left + 1, rectClient.top  + 25, rectClient.Width() - 2, rectClient.Height()  - 25, SWP_NOACTIVATE | SWP_NOZORDER);
	m_ctrlFrame.SetWindowPos(NULL, rectClient.left + 1, rectClient.top  + 25, rectClient.Width() - 2, rectClient.Height()  - 25, SWP_NOACTIVATE | SWP_NOZORDER);

	// TODO: 在此处添加消息处理程序代码
}
void CMyFrameMsgTabCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(GetCurSel())
	{
	case 0:
		m_ctrlMssage.ShowWindow(SW_SHOW);
		m_ctrlFrame.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_ctrlMssage.ShowWindow(SW_HIDE);
		m_ctrlFrame.ShowWindow(SW_SHOW);
		break;
	}
	CTabCtrl::OnLButtonUp(nFlags, point);
}
