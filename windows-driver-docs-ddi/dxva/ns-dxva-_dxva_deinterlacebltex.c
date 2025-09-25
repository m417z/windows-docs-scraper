typedef struct _DXVA_DeinterlaceBltEx {
  DWORD             Size;
  DXVA_AYUVsample2  BackgroundColor;
  RECT              rcTarget;
  REFERENCE_TIME    rtTarget;
  DWORD             NumSourceSurfaces;
  FLOAT             Alpha;
  DXVA_VideoSample2 Source[MAX_DEINTERLACE_SURFACES];
  DWORD             DestinationFormat;
  DWORD             DestinationFlags;
} DXVA_DeinterlaceBltEx;