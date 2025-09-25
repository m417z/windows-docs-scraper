typedef struct {
  BOOL fShowAllObjects : 1;
  BOOL fShowExtensions : 1;
  BOOL fNoConfirmRecycle : 1;
  BOOL fShowSysFiles : 1;
  BOOL fShowCompColor : 1;
  BOOL fDoubleClickInWebView : 1;
  BOOL fDesktopHTML : 1;
  BOOL fWin95Classic : 1;
  BOOL fDontPrettyPath : 1;
  BOOL fShowAttribCol : 1;
  BOOL fMapNetDrvBtn : 1;
  BOOL fShowInfoTip : 1;
  BOOL fHideIcons : 1;
  BOOL fAutoCheckSelect : 1;
  BOOL fIconsOnly : 1;
#if ...
  UINT fRestFlags : 1;
#else
  UINT fRestFlags : 3;
#endif
} SHELLFLAGSTATE, *LPSHELLFLAGSTATE;