typedef struct _D3DKMDT_VIDEO_SIGNAL_INFO {
  D3DKMDT_VIDEO_SIGNAL_STANDARD VideoStandard;
  D3DKMDT_2DREGION              TotalSize;
  D3DKMDT_2DREGION              ActiveSize;
  D3DDDI_RATIONAL               VSyncFreq;
  D3DDDI_RATIONAL               HSyncFreq;
  SIZE_T                        PixelRate;
  union {
    struct {
      D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING ScanLineOrdering : 3;
      UINT                                  VSyncFreqDivider : 6;
      UINT                                  Reserved : 23;
    } AdditionalSignalInfo;
    D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING ScanLineOrdering;
  };
} D3DKMDT_VIDEO_SIGNAL_INFO;