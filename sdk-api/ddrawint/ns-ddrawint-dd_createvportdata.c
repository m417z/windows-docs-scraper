typedef struct _DD_CREATEVPORTDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  LPDDVIDEOPORTDESC    lpDDVideoPortDesc;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  HRESULT              ddRVal;
  VOID                 *CreateVideoPort;
} *PDD_CREATEVPORTDATA, DD_CREATEVPORTDATA;