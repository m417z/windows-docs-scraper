typedef struct tagCONVINFO {
  DWORD       cb;
  DWORD_PTR   hUser;
  HCONV       hConvPartner;
  HSZ         hszSvcPartner;
  HSZ         hszServiceReq;
  HSZ         hszTopic;
  HSZ         hszItem;
  UINT        wFmt;
  UINT        wType;
  UINT        wStatus;
  UINT        wConvst;
  UINT        wLastError;
  HCONVLIST   hConvList;
  CONVCONTEXT ConvCtxt;
  HWND        hwnd;
  HWND        hwndPartner;
} CONVINFO, *PCONVINFO;