typedef struct _DD_GETMOCOMPCOMPBUFFDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  GUID                 *lpGuid;
  DWORD                dwWidth;
  DWORD                dwHeight;
  DDPIXELFORMAT        ddPixelFormat;
  DWORD                dwNumTypesCompBuffs;
  LPDDCOMPBUFFERINFO   lpCompBuffInfo;
  HRESULT              ddRVal;
} *PDD_GETMOCOMPCOMPBUFFDATA, DD_GETMOCOMPCOMPBUFFDATA;