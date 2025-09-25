typedef struct _DXVA_VideoSample32 {
  REFERENCE_TIME   rtStart;
  REFERENCE_TIME   rtEnd;
  DWORD            SampleFormat;
  DWORD            SampleFlags;
  DWORD            lpDDSSrcSurface;
  RECT             rcSrc;
  RECT             rcDst;
  DXVA_AYUVsample2 Palette[16];
} DXVA_VideoSample32;