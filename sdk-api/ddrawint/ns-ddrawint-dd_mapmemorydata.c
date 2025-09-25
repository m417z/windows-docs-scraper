typedef struct _DD_MAPMEMORYDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  BOOL                  bMap;
  HANDLE                hProcess;
  FLATPTR               fpProcess;
  HRESULT               ddRVal;
} *PDD_MAPMEMORYDATA, DD_MAPMEMORYDATA;