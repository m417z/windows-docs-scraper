typedef struct _D3DKMT_GETSCANLINE {
  [in]  D3DKMT_HANDLE                  hAdapter;
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [out] BOOLEAN                        InVerticalBlank;
  [out] UINT                           ScanLine;
} D3DKMT_GETSCANLINE;