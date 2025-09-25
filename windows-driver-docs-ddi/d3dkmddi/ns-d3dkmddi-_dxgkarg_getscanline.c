typedef struct _DXGKARG_GETSCANLINE {
  [in]  D3DDDI_VIDEO_PRESENT_TARGET_ID VidPnTargetId;
  [out] BOOLEAN                        InVerticalBlank;
  [out] UINT                           ScanLine;
} DXGKARG_GETSCANLINE;