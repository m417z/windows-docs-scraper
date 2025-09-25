typedef struct _DD_WAITFORVPORTSYNCDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  DWORD                dwFlags;
  DWORD                dwLine;
  DWORD                dwTimeOut;
  HRESULT              ddRVal;
  VOID                 *UpdateVideoPort;
} *PDD_WAITFORVPORTSYNCDATA, DD_WAITFORVPORTSYNCDATA;