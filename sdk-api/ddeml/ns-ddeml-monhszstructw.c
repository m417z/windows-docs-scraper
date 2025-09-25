typedef struct tagMONHSZSTRUCTW {
  UINT   cb;
  BOOL   fsAction;
  DWORD  dwTime;
  HSZ    hsz;
  HANDLE hTask;
  WCHAR  str[1];
} MONHSZSTRUCTW, *PMONHSZSTRUCTW;