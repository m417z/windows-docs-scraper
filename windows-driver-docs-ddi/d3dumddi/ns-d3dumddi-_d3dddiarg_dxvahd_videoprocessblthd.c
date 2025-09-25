typedef struct _D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD {
  [in] HANDLE                      hVideoProcessor;
  [in] DXVAHDDDI_SURFACE           OutputSurface;
  [in] UINT                        OutputFrame;
  [in] UINT                        StreamCount;
  [in] const DXVAHDDDI_STREAM_DATA *pStreams;
} D3DDDIARG_DXVAHD_VIDEOPROCESSBLTHD;