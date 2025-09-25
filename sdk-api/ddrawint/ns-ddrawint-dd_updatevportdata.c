typedef struct _DD_UPDATEVPORTDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_VIDEOPORT_LOCAL  lpVideoPort;
  PDD_SURFACE_INT      *lplpDDSurface;
  PDD_SURFACE_INT      *lplpDDVBISurface;
  PDD_VIDEOPORTINFO    lpVideoInfo;
  DWORD                dwFlags;
  DWORD                dwNumAutoflip;
  DWORD                dwNumVBIAutoflip;
  HRESULT              ddRVal;
  VOID                 *UpdateVideoPort;
} *PDD_UPDATEVPORTDATA, DD_UPDATEVPORTDATA;