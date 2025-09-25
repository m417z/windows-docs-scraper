typedef struct _DD_GETVPORTFIELDDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  BOOL                 bField;
  HRESULT              ddRVal;
  VOID                 *GetVideoPortField;
} *PDD_GETVPORTFIELDDATA, DD_GETVPORTFIELDDATA;