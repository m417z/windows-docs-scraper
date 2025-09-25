typedef struct _D3DKMT_OPENADAPTERFROMHDC {
  [in]  HDC                            hDc;
  [out] D3DKMT_HANDLE                  hAdapter;
  [out] LUID                           AdapterLuid;
  [out] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
} D3DKMT_OPENADAPTERFROMHDC;