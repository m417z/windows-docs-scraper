typedef struct _DD_GETVPORTCONNECTDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  DWORD                dwPortId;
  LPDDVIDEOPORTCONNECT lpConnect;
  DWORD                dwNumEntries;
  HRESULT              ddRVal;
  VOID                 *GetVideoPortConnectInfo;
} *PDD_GETVPORTCONNECTDATA, DD_GETVPORTCONNECTDATA;