typedef struct _DD_GETVPORTLINEDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  DWORD                dwLine;
  HRESULT              ddRVal;
  VOID                 *GetVideoPortLine;
} *PDD_GETVPORTLINEDATA, DD_GETVPORTLINEDATA;