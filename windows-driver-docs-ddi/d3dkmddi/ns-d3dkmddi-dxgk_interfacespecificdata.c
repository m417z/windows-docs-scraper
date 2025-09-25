typedef struct _DXGK_INTERFACESPECIFICDATA {
  HANDLE                     hAdapter;
  DXGKCB_GETHANDLEDATA       pfnGetHandleDataCb;
  DXGKCB_GETHANDLEPARENT     pfnGetHandleParentCb;
  DXGKCB_ENUMHANDLECHILDREN  pfnEnumHandleChildrenCb;
  DXGKCB_NOTIFY_INTERRUPT    pfnNotifyInterruptCb;
  DXGKCB_NOTIFY_DPC          pfnNotifyDpcCb;
  DXGKCB_QUERYVIDPNINTERFACE pfnQueryVidPnInterfaceCb;
  DXGKCB_GETCAPTUREADDRESS   pfnGetCaptureAddressCb;
} DXGK_INTERFACESPECIFICDATA;