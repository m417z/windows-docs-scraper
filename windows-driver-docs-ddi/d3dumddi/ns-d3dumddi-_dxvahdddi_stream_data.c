typedef struct _DXVAHDDDI_STREAM_DATA {
  [in] BOOL              Enable;
  [in] UINT              OutputIndex;
  [in] UINT              InputFrameOrField;
  [in] UINT              PastFrames;
  [in] UINT              FutureFrames;
  [in] DXVAHDDDI_SURFACE *pPastSurfaces;
  [in] DXVAHDDDI_SURFACE InputSurface;
  [in] DXVAHDDDI_SURFACE *pFutureSurfaces;
} DXVAHDDDI_STREAM_DATA;