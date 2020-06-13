#ifndef __RULE_H__
#define __RULE_H__

class CRule
{
public:
	CRule();
	~CRule();
	void SetLevel(int nLevel);
	int UpLevel(int nLine);
	bool Win(int Now[4][4], int Russia[100][100], CPoint NowPosition);
private:
	int m_nLevel;
};
#endif