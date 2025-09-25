typedef struct {
  UINT      cbSize;
  DWORD     dwMask;
  int       idCommand;
  int       iImage;
  BYTE      fsState;
  BYTE      fsStyle;
  WORD      cx;
  DWORD_PTR lParam;
  LPWSTR    pszText;
  int       cchText;
} TBBUTTONINFOW, *LPTBBUTTONINFOW;