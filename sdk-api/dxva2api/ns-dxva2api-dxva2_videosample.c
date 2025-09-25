typedef struct _DXVA2_VideoSample {
  REFERENCE_TIME       Start;
  REFERENCE_TIME       End;
  DXVA2_ExtendedFormat SampleFormat;
  IDirect3DSurface9    *SrcSurface;
  RECT                 SrcRect;
  RECT                 DstRect;
  DXVA2_AYUVSample8    Pal[16];
  DXVA2_Fixed32        PlanarAlpha;
  DWORD                SampleData;
} DXVA2_VideoSample;