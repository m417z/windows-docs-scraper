typedef struct _DD_SETCOLORKEYDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSurface;
  DWORD                 dwFlags;
  DDCOLORKEY            ckNew;
  HRESULT               ddRVal;
  VOID                  *SetColorKey;
} *PDD_SETCOLORKEYDATA, DD_SETCOLORKEYDATA;