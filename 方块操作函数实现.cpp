void CRussia::Move(int direction)
{
	if (end) return;
	switch (direction)
	{
	case KEY_LEFT:
		if (Meet(Mow, KEY_LEFT, NowPosition))
		{
			break;
		}
		NowPosition.y--;
		break;
	case KEY_RIGHT:
		if (Meet(Mow, KEY_RIGHT, NowPosition))
		{
			break;
		}
		NowPosition.y++;
	case KEY_DOWN:
		if (Meet(Mow, KEY_DOWN, NowPosition))
		{
			LineDelete();
			break;
		}
		NowPosition.x++;
		break;
	case KEY_UP:
		Meet(Now, KEY_UP, NowPosition);
		break;
	default:
		break;
	}
}

bool CRussia::Change(int a[][4], CPoint p, int b[][100])
{
	int tmp[4][4];
	int i, j;
	int k = 4, l = 4;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			tmp[i][j] = a[j][3 - i];
			After[i][j] = 0;
		}
	}

for (i = 0; i < 4; i++)
{
	for (j = 0; j < 4; j++)
	{
		if (tmp[i][j] == 1)
		{
			if (k > i) k = i;
			if (l > j) l = j;
		}
	}
}
for (i = k; i < 4; i++)
{
	for (j = 0; j < 4; j++)
	{
		After[i - k][j - l] = tmp[i][j];
	}
}
for (i = 0; i < 4; i++)
{
	for (j = 0; j < 4; j++)
	{
		if (After[i][j] == 0)
		{
			continue;
		}
		if (((p.x + i) >= m_RowCount) || ((p.y + j) < 0) || ((p.y + j) >= m_ColCount))
		{
			return false;
		}
		if (b[p.x + i][p.y + j] == 1)
		{
			return false;
		}
	}
}
return true;
}