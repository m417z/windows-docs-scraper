typedef struct _DD_FLIPVPORTDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  PDD_SURFACE_LOCAL    lpSurfCurr;
  PDD_SURFACE_LOCAL    lpSurfTarg;
  HRESULT              ddRVal;
  VOID                 *FlipVideoPort;
} *PDD_FLIPVPORTDATA, DD_FLIPVPORTDATA;