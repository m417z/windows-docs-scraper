typedef struct _DXVADDI_VIDEOSAMPLE {
  [in] REFERENCE_TIME           Start;
  [in] REFERENCE_TIME           End;
  [in] DXVADDI_EXTENDEDFORMAT   SampleFormat;
  [in] DXVADDI_VIDEOSAMPLEFLAGS SampleFlags;
  [in] HANDLE                   SrcResource;
  [in] UINT                     SrcSubResourceIndex;
  [in] RECT                     SrcRect;
  [in] RECT                     DstRect;
       DXVADDI_AYUVSAMPLE8      Pal[16];
  [in] DXVADDI_FIXED32          PlanarAlpha;
} DXVADDI_VIDEOSAMPLE;