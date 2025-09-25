typedef struct _DD_UPDATENONLOCALHEAPDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  DWORD                 dwHeap;
  FLATPTR               fpGARTLin;
  FLATPTR               fpGARTDev;
  ULONG_PTR             ulPolicyMaxBytes;
  HRESULT               ddRVal;
  VOID                  *UpdateNonLocalHeap;
} *PDD_UPDATENONLOCALHEAPDATA, DD_UPDATENONLOCALHEAPDATA;