typedef struct _DD_SETEXCLUSIVEMODEDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  DWORD                 dwEnterExcl;
  DWORD                 dwReserved;
  HRESULT               ddRVal;
  VOID                  *SetExclusiveMode;
} *PDD_SETEXCLUSIVEMODEDATA, DD_SETEXCLUSIVEMODEDATA;