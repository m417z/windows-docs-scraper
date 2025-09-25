typedef struct _DD_GETVPORTBANDWIDTHDATA {
  PDD_DIRECTDRAW_LOCAL   lpDD;
  PDD_VIDEOPORT_LOCAL    lpVideoPort;
  LPDDPIXELFORMAT        lpddpfFormat;
  DWORD                  dwWidth;
  DWORD                  dwHeight;
  DWORD                  dwFlags;
  LPDDVIDEOPORTBANDWIDTH lpBandwidth;
  HRESULT                ddRVal;
  VOID                   *GetVideoPortBandwidth;
} *PDD_GETVPORTBANDWIDTHDATA, DD_GETVPORTBANDWIDTHDATA;