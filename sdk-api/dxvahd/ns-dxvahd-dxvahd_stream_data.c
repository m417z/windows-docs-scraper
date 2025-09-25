typedef struct _DXVAHD_STREAM_DATA {
  BOOL              Enable;
  UINT              OutputIndex;
  UINT              InputFrameOrField;
  UINT              PastFrames;
  UINT              FutureFrames;
  IDirect3DSurface9 **ppPastSurfaces;
  IDirect3DSurface9 *pInputSurface;
  IDirect3DSurface9 **ppFutureSurfaces;
} DXVAHD_STREAM_DATA;