typedef struct tagMCGRIDINFO {
  UINT       cbSize;
  DWORD      dwPart;
  DWORD      dwFlags;
  int        iCalendar;
  int        iRow;
  int        iCol;
  BOOL       bSelected;
  SYSTEMTIME stStart;
  SYSTEMTIME stEnd;
  RECT       rc;
  PWSTR      pszName;
  size_t     cchName;
} MCGRIDINFO, *PMCGRIDINFO;