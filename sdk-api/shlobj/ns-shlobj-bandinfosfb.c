typedef struct {
  DWORD            dwMask;
  DWORD            dwStateMask;
  DWORD            dwState;
  COLORREF         crBkgnd;
  COLORREF         crBtnLt;
  COLORREF         crBtnDk;
  WORD             wViewMode;
  WORD             wAlign;
  IShellFolder     *psf;
  PIDLIST_ABSOLUTE pidl;
} BANDINFOSFB, *PBANDINFOSFB;