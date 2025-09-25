typedef struct tagMONHSZSTRUCTA {
  UINT   cb;
  BOOL   fsAction;
  DWORD  dwTime;
  HSZ    hsz;
  HANDLE hTask;
  CHAR   str[1];
} MONHSZSTRUCTA, *PMONHSZSTRUCTA;