typedef struct _DD_GETMOCOMPGUIDSDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  DWORD                dwNumGuids;
  GUID                 *lpGuids;
  HRESULT              ddRVal;
} *PDD_GETMOCOMPGUIDSDATA, DD_GETMOCOMPGUIDSDATA;