#include<iostream>
using namespace std;
#include <graphics.h>
#include <ctime>
#include <conio.h>



void initEnvironment()
{
	// 窗口设置
	initgraph(1200, 540);

	HWND hwnd = GetHWnd();//窗口句柄
	SetWindowText(hwnd, L"我罗斯方块双人版");

	// 绘图模式设置
	setbkmode(TRANSPARENT);

}


void CRussia::DrawBK(CDC*pDC)
{
	// 创建绘图窗口
	initEnvironment();

	DWORD time_now = GetTickCount();
	//Russia obj;
	//srand(time(0));
	//obj.Count = rand() % 7;
	//obj.Count;

	DWORD time_tmp = GetTickCount();
	while (1) {
		BeginBatchDraw();
		for (int i = 0; i < 541; ++i)
		{
			setlinecolor(RGB(195, 200, 238 - i / 15));
			line(0, i, 240, i);
			setlinecolor(RGB(195, 200, 238 - i / 15));
			line(961, 540 - i, 1200, 540 - i);
		}

		setcolor(0x006400);
		settextstyle(25, 0, L"黑体");
		outtextxy(85, 10, L"下一个：");
		outtextxy(85, 220, L"Score：");
		outtextxy(85, 300, L"右移：A");
		outtextxy(85, 340, L"左移：D");
		outtextxy(85, 380, L"变形：W");
		outtextxy(85, 420, L"下落：S");

		outtextxy(960 + 85, 10, L"下一个：");
		outtextxy(960 + 85, 220, L"Score：");
		outtextxy(960 + 85, 300, L"左移：←");
		outtextxy(960 + 85, 340, L"右移：→");
		outtextxy(960 + 85, 380, L"变形：↑");
		outtextxy(960 + 85, 420, L"下落：↓");

		setlinecolor(0xFFFF00);
		rectangle(50, 50, 50 + 150, 50 + 150);
		rectangle(60, 60, 60 + 130, 60 + 130);
		rectangle(960 + 50, 50, 960 + 50 + 150, 50 + 150);
		rectangle(960 + 60, 60, 960 + 60 + 130, 60 + 130);

		for (int i = 0; i < 541; ++i)
		{
			//setlinecolor(RGB(90,160, 220-i/15));
			setlinecolor(RGB(135, 140, 210 - i / 10));
			line(241, i, 600, i);

			setlinecolor(RGB(135, 140, 210 - i / 10));
			line(601, 540 - i, 960, 540 - i);
		}

		int x, y, a;
		x = NowPosition.x;
		a = x;
		y = NowPosition.y;
		for (int i = 0; i < m_RowCount; i++)
		{
			for (int j = 0; j < m_ColCount; j++)
			{
				if (Russia[i][j] == 1)
				{
					setfillcolor(0xEE6363);
					fillrectangle(x, y, x + 36, y + 36);
					x += 36;
				}
				if (m == 3)
				{
					if (x != a)
						y += 36;
					x = a;
				}
			}
		}
		
	
		EndBatchDraw();
	}
}
void CRussia::DrawScore1(CDC* pDC)
{
	int nOldDC = pDC->SaveDC();
	CFont font;
	if (0 == font.CreatePointFont(300, "Comic Sans MS"))
	{
		AfxMessageBox("Can't Create Font");
	}
	pDC->SelectObject(&font);
	CString str;
	pDC->SetTextColor(RGB(255, 255, 0));
	str.Format("&d", m_Score);
	if (m_Score >= 0)
		pDC->TextOut(90, 260, str);

}
void CRussia::DrawScore2(CDC* pDC)
{
	int nOldDC = pDC->SaveDC();
	CFont font;
	if (0 == font.CreatePointFont(300, "Comic Sans MS"))
	{
		AfxMessageBox("Can't Create Font");
	}
	pDC->SelectObject(&font);
	CString str;
	pDC->SetTextColor(RGB(255, 255, 0));
	str.Format("&d", m_Score);
	if (m_Score >= 0)
		pDC->TextOut(960+90, 260, str);

}