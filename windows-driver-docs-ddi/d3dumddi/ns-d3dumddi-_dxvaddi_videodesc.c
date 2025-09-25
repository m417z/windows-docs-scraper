typedef struct _DXVADDI_VIDEODESC {
  [in] UINT                   SampleWidth;
  [in] UINT                   SampleHeight;
  [in] DXVADDI_EXTENDEDFORMAT SampleFormat;
  [in] D3DDDIFORMAT           Format;
  [in] DXVADDI_FREQUENCY      InputSampleFreq;
  [in] DXVADDI_FREQUENCY      OutputFrameFreq;
  [in] UINT                   UABProtectionLevel;
  [in] UINT                   Reserved;
} DXVADDI_VIDEODESC;