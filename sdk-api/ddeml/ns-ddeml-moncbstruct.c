typedef struct tagMONCBSTRUCT {
  UINT        cb;
  DWORD       dwTime;
  HANDLE      hTask;
  DWORD       dwRet;
  UINT        wType;
  UINT        wFmt;
  HCONV       hConv;
  HSZ         hsz1;
  HSZ         hsz2;
  HDDEDATA    hData;
  ULONG_PTR   dwData1;
  ULONG_PTR   dwData2;
  CONVCONTEXT cc;
  DWORD       cbData;
  DWORD       Data[8];
} MONCBSTRUCT, *PMONCBSTRUCT;