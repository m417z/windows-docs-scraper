typedef struct _DD_GETBLTSTATUSDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSurface;
  DWORD                 dwFlags;
  HRESULT               ddRVal;
  VOID                  *GetBltStatus;
} *PDD_GETBLTSTATUSDATA, DD_GETBLTSTATUSDATA;