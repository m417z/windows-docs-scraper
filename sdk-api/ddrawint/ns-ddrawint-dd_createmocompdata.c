typedef struct _DD_CREATEMOCOMPDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_MOTIONCOMP_LOCAL lpMoComp;
  GUID                 *lpGuid;
  DWORD                dwUncompWidth;
  DWORD                dwUncompHeight;
  DDPIXELFORMAT        ddUncompPixelFormat;
  LPVOID               lpData;
  DWORD                dwDataSize;
  HRESULT              ddRVal;
} *PDD_CREATEMOCOMPDATA, DD_CREATEMOCOMPDATA;