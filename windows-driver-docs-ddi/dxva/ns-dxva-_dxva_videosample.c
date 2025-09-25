typedef struct _DXVA_VideoSample {
  REFERENCE_TIME    rtStart;
  REFERENCE_TIME    rtEnd;
  DXVA_SampleFormat SampleFormat;
  VOID              *lpDDSSrcSurface;
} DXVA_VideoSample, *LPDXVA_VideoSample;