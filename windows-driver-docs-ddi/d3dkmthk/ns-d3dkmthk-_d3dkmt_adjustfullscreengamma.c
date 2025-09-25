typedef struct _D3DKMT_ADJUSTFULLSCREENGAMMA {
  D3DKMT_HANDLE                  hAdapter;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  D3DDDI_DXGI_RGB                Scale;
  D3DDDI_DXGI_RGB                Offset;
} D3DKMT_ADJUSTFULLSCREENGAMMA;