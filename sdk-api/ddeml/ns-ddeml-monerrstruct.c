typedef struct tagMONERRSTRUCT {
  UINT   cb;
  UINT   wLastError;
  DWORD  dwTime;
  HANDLE hTask;
} MONERRSTRUCT, *PMONERRSTRUCT;