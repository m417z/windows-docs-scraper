typedef struct _DXGKARG_CANCELFLIPS {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  UINT                           PlaneCount;
  DXGK_CANCELFLIPS_PLANE         **ppPlanes;
} DXGKARG_CANCELFLIPS;