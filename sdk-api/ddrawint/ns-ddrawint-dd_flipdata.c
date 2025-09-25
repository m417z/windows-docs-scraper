typedef struct _DD_FLIPDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpSurfCurr;
  PDD_SURFACE_LOCAL     lpSurfTarg;
  DWORD                 dwFlags;
  HRESULT               ddRVal;
  VOID                  *Flip;
  PDD_SURFACE_LOCAL     lpSurfCurrLeft;
  PDD_SURFACE_LOCAL     lpSurfTargLeft;
} *PDD_FLIPDATA, DD_FLIPDATA;