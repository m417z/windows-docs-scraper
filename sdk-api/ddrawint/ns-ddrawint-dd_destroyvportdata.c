typedef struct _DD_DESTROYVPORTDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  HRESULT              ddRVal;
  VOID                 *DestroyVideoPort;
} *PDD_DESTROYVPORTDATA, DD_DESTROYVPORTDATA;