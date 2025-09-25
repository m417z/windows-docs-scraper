typedef struct _DD_COLORCONTROLDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSurface;
  LPDDCOLORCONTROL      lpColorData;
  DWORD                 dwFlags;
  HRESULT               ddRVal;
  VOID                  *ColorControl;
} *PDD_COLORCONTROLDATA, DD_COLORCONTROLDATA;