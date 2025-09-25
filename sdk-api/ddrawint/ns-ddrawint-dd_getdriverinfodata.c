typedef struct _DD_GETDRIVERINFODATA {
  VOID    *dhpdev;
  DWORD   dwSize;
  DWORD   dwFlags;
  GUID    guidInfo;
  DWORD   dwExpectedSize;
  PVOID   lpvData;
  DWORD   dwActualSize;
  HRESULT ddRVal;
} *PDD_GETDRIVERINFODATA, DD_GETDRIVERINFODATA;