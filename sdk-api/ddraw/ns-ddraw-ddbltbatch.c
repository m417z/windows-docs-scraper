typedef struct _DDBLTBATCH {
  LPRECT              lprDest;
  LPDIRECTDRAWSURFACE lpDDSSrc;
  LPRECT              lprSrc;
  DWORD               dwFlags;
  LPDDBLTFX           lpDDBltFx;
} DDBLTBATCH;