typedef struct _DXVA_DeinterlaceBlt {
  DWORD            Size;
  DWORD            Reserved;
  REFERENCE_TIME   rtTarget;
  RECT             DstRect;
  RECT             SrcRect;
  DWORD            NumSourceSurfaces;
  FLOAT            Alpha;
  DXVA_VideoSample Source[MAX_DEINTERLACE_SURFACES];
} DXVA_DeinterlaceBlt;