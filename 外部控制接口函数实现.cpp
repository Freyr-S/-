void CRussia::GameStart()
{
	end = false;
	m_Score = 0;
	m_RowCount = 18;//行数
	m_ColCount = 12;//列数
	Count = 7;//方块种类
	m_CountLine = 0;//合计消除行数
	char pszTmp[128] = { 0 };
	GetPrivateProfileString("SETUP", "level", "l", pszTmp, 127, ".\\setup.ini");
	m_Level = atoi(pszTmp);
	m_Speed = 320 - m_Level * 20;
	rule.SetLevel(m_Level);

	for (int i = 0; i < m_RowCount; i++)
	{
		for (int j = 0; j < m_ColCount; j++)
		{
			Russia[i][j] = 0;
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			Now[i][j] = 0;
			Will[i][j] = 0;
		}
	}
	DrawWill();
	DrawWill();
}