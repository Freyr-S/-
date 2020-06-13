#include "stdafx.h"
#include "Rule.h"

CRule::CRule()
{
}
CRule::~CRule()
{
}
void CRule::SetLevel(int nLevel)
{
	m_nLevel = nLevel;
}
int CRule::UpLevel(int nLevel)
{
	if (nLine / 30)
	{
		m_nLevel++;
	}
	return m_nLevel;
}
bool CRule::Win(int Now[4][4], int Russia[100][100], CPoint NowPosition)
{
	if (m_nLevel == 11)
	{
		return true;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Now[i][j] == 1)
			{
				if (Russia[i + NowPosition][j + NowPosition] == 1)
				{
					return true;
				}
			}
		}
	}
	return false;
}