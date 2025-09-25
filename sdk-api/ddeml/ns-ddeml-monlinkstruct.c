typedef struct tagMONLINKSTRUCT {
  UINT   cb;
  DWORD  dwTime;
  HANDLE hTask;
  BOOL   fEstablished;
  BOOL   fNoData;
  HSZ    hszSvc;
  HSZ    hszTopic;
  HSZ    hszItem;
  UINT   wFmt;
  BOOL   fServer;
  HCONV  hConvServer;
  HCONV  hConvClient;
} MONLINKSTRUCT, *PMONLINKSTRUCT;