#include "stdafx.h"
#include "Tetris.h"
#include "RetrisDoc.h"
#include "TetrisView.h"
#include "HelpDlg.h"
#include "LevelSetupDlg.h"
#include "russia.h"

IMPLEMENT_DYNCREATE(CTetrisView,CView)

BEGIN_MESSAGE_MAP(CTetrisView,CView)
	ON_COMMAND(IDR_ABOUT,OnAbout)
	ON_COMMAND(IDR_LEVEL_SETUP, OnLevelSetup)
	ON_COMMAND(IDR_START_GAME, OnStartGame)
	ON_COMMAND(IDR_HELP, OnHelp)
	ON_COMMAND(IDR_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(IDR_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(IDR_FILE_PRINT_PREVIEW, OCView::OnFilePrintPreview)