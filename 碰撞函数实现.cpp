bool CRussia::Meet(int a[][4], int direction, CPoint p)
{
	int i, j;
	for (i=0;i<4;i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 1)
			{
				Russia[p.x + i][p.y + j] = 0;//Çå¿ÕÊý¾Ý
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 1)
			{
				switch (direction)
				{
				case KEY_LEFT:
					if ((p.y + j - 1) < 0) goto exit;
					if (Russia[p.x + i][p.y + j - 1] == 1) goto exit;
					break;
				case KEY_RIGHT:
					if ((p.y + j + 1) >=m_ColCount) goto exit;
					if (Russia[p.x + i][p.y + j + 1] == 1) goto exit;
					break;
				case KEY_DOWN:
					if ((p.x + i + 1) >=m_RowCount) goto exit;
					if (Russia[p.x + i+1][p.y + j ] == 1) goto exit;
					break;
				case KEY_up:
					if (!(Change(a,p,Ruassia)) goto exit;
						for (i = 0; i < 4; i++)
						{
							for (j = 0; j < 4; j++)
							{
								Now[i][j]=After[i][j];
								a[i][j]=Now[i][j];
							}
					    }
					return false;
					break;
				}
			}
		}
	}
	int x, y;
	x = p.x;
	y = p.y;
	switch (direction)
	{
	case 1:
		y--; break;
	case 2:
		y++; break;
	case 3:
		x++; break;
	case 4:
		break;
	}
	for(i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 1)
			{
				Russia[x + i][y + j] = 1;
			}
		}
	}
	return false;
exit:
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 1)
			{
				Russia[p.x + i][p.y + j] = 1;
			}
		}
	}
	return true;
}