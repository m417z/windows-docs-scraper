typedef struct _DD_GETINTERNALMOCOMPDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  GUID                 *lpGuid;
  DWORD                dwWidth;
  DWORD                dwHeight;
  DDPIXELFORMAT        ddPixelFormat;
  DWORD                dwScratchMemAlloc;
  HRESULT              ddRVal;
} *PDD_GETINTERNALMOCOMPDATA, DD_GETINTERNALMOCOMPDATA;