typedef struct _DD_SYNCVIDEOPORTDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  DWORD                dwOriginOffset;
  DWORD                dwHeight;
  DWORD                dwVBIHeight;
  ULONG                dwDriverReserved1;
  ULONG                dwDriverReserved2;
  ULONG                dwDriverReserved3;
  HRESULT              ddRVal;
} *PDD_SYNCVIDEOPORTDATA, DD_SYNCVIDEOPORTDATA;