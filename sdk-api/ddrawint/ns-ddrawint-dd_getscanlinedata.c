typedef struct _DD_GETSCANLINEDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  DWORD                 dwScanLine;
  HRESULT               ddRVal;
  VOID                  *GetScanLine;
} *PDD_GETSCANLINEDATA, DD_GETSCANLINEDATA;