typedef struct _DD_GETAVAILDRIVERMEMORYDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  DDSCAPS               DDSCaps;
  DWORD                 dwTotal;
  DWORD                 dwFree;
  HRESULT               ddRVal;
  VOID                  *GetAvailDriverMemory;
} *PDD_GETAVAILDRIVERMEMORYDATA, DD_GETAVAILDRIVERMEMORYDATA;