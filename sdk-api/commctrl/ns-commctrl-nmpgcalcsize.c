typedef struct {
  NMHDR hdr;
  DWORD dwFlag;
  int   iWidth;
  int   iHeight;
} NMPGCALCSIZE, *LPNMPGCALCSIZE;