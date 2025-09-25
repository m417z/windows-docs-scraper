typedef struct _DD_GETVPORTSIGNALDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  DWORD                dwStatus;
  HRESULT              ddRVal;
  VOID                 *GetVideoSignalStatus;
} *PDD_GETVPORTSIGNALDATA, DD_GETVPORTSIGNALDATA;