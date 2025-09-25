typedef struct _DXGKARG_SETPOINTERSHAPE {
  [in] DXGK_POINTERFLAGS              Flags;
  [in] UINT                           Width;
  [in] UINT                           Height;
  [in] UINT                           Pitch;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] const VOID                     *pPixels;
  [in] UINT                           XHot;
  [in] UINT                           YHot;
} DXGKARG_SETPOINTERSHAPE;