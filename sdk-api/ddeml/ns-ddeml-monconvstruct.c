typedef struct tagMONCONVSTRUCT {
  UINT   cb;
  BOOL   fConnect;
  DWORD  dwTime;
  HANDLE hTask;
  HSZ    hszSvc;
  HSZ    hszTopic;
  HCONV  hConvClient;
  HCONV  hConvServer;
} MONCONVSTRUCT, *PMONCONVSTRUCT;