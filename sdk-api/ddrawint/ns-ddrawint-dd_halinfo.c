typedef struct _DD_HALINFO {
  DWORD               dwSize;
  VIDEOMEMORYINFO     vmiData;
  DDNTCORECAPS        ddCaps;
  PDD_GETDRIVERINFO   GetDriverInfo;
  DWORD               dwFlags;
  LPVOID              lpD3DGlobalDriverData;
  LPVOID              lpD3DHALCallbacks;
  PDD_D3DBUFCALLBACKS lpD3DBufCallbacks;
} DD_HALINFO, *PDD_HALINFO;