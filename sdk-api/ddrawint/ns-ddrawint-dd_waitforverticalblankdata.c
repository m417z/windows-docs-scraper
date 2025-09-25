typedef struct _DD_WAITFORVERTICALBLANKDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  DWORD                 dwFlags;
  DWORD                 bIsInVB;
  ULONG_PTR             hEvent;
  HRESULT               ddRVal;
  VOID                  *WaitForVerticalBlank;
} *PDD_WAITFORVERTICALBLANKDATA, DD_WAITFORVERTICALBLANKDATA;