typedef struct _DXVA2_VideoDesc {
  UINT                 SampleWidth;
  UINT                 SampleHeight;
  DXVA2_ExtendedFormat SampleFormat;
  D3DFORMAT            Format;
  DXVA2_Frequency      InputSampleFreq;
  DXVA2_Frequency      OutputFrameFreq;
  UINT                 UABProtectionLevel;
  UINT                 Reserved;
} DXVA2_VideoDesc;