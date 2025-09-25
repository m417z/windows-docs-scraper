typedef struct _DXGKARG_SETPALETTE {
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] UINT                           FirstEntry;
  [in] UINT                           NumEntries;
  [in] D3DKMDT_PALETTEDATA            *pLookupTable;
} DXGKARG_SETPALETTE;