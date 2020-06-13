void CRussia::LineDelete()
{
	int m = 0;
	bool flag = 0;
	for(int i=0;i<m_RowCount;i++)
	{ 
		flag = true;
	for (int j = 0; j < m_ColCount; j++)
	{
		if (Russia[i][j] == 0)
		{
			flag = false;
		}
	}
	if (flag == true)
	{
		m++;
		for (int k = i; k > 0; k--)
		{
			for (int l = 0; l < m_ColCount; l++)
			{
				Russia[k][l] = Russia[k - l][l];
			}
		}
		for (int l = 0; l < m_ColCount; l++)
		{
			Russia[0][l] = 0;
		}
	}
	}


DrawWill();
switch (m)
{
case 1:
	m_Score = m_Score + 10 + m_Level * 10;
	break;
case 2:
	m_Score = m_Score + 30 + m_Level * 10;
	break;
case 3:
	m_Score = m_Score + 50 + m_Level * 10;
	break;
case 4:
	m_Score = m_Score + 100 + m_Level * 10;
	break;
default:
	break;
}
m_CountLine += m;
m_Level = rule.UpLevel(m_CountLine);
end = rule.Win(Now, Russia, NowPosition);
m_Speed = 320 - m_Level * 20;
if (end)
{
	AfxMessageBox("ÓÎÏ·½éÉÜ£¡")£»
}
}