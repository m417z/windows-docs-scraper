typedef struct _DD_GETVPORTFLIPSTATUSDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  FLATPTR              fpSurface;
  HRESULT              ddRVal;
  VOID                 *GetVideoPortFlipStatus;
} *PDD_GETVPORTFLIPSTATUSDATA, DD_GETVPORTFLIPSTATUSDATA;