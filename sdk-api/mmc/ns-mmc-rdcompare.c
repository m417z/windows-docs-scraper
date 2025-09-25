typedef struct _RDCOMPARE {
  DWORD     cbSize;
  DWORD     dwFlags;
  int       nColumn;
  LPARAM    lUserParam;
  RDITEMHDR *prdch1;
  RDITEMHDR *prdch2;
} RDCOMPARE;