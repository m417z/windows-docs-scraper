typedef struct _D3DKMDT_SHAREDPRIMARYSURFACEDATA {
  [in] UINT                           Width;
  [in] UINT                           Height;
  [in] D3DDDIFORMAT                   Format;
  [in] D3DDDI_RATIONAL                RefreshRate;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
} D3DKMDT_SHAREDPRIMARYSURFACEDATA;