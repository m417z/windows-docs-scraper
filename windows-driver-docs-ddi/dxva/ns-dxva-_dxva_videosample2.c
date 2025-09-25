typedef struct _DXVA_VideoSample2 {
  DWORD            Size;
  DWORD            Reserved;
  REFERENCE_TIME   rtStart;
  REFERENCE_TIME   rtEnd;
  DWORD            SampleFormat;
  DWORD            SampleFlags;
  VOID             *lpDDSSrcSurface;
  RECT             rcSrc;
  RECT             rcDst;
  DXVA_AYUVsample2 Palette[16];
} DXVA_VideoSample2, *LPDXVA_VideoSample2;