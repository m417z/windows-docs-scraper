typedef struct _D3DDDIARG_VIDEOPROCESSBLT {
  [in] REFERENCE_TIME               TargetFrame;
  [in] HANDLE                       hVideoProcess;
  [in] RECT                         TargetRect;
  [in] SIZE                         ConstrictionSize;
  [in] UINT                         StreamingFlags;
  [in] DXVADDI_AYUVSAMPLE16         BackgroundColor;
  [in] DXVADDI_EXTENDEDFORMAT       DestFormat;
  [in] DXVADDI_VIDEOPROCESSBLTFLAGS DestFlags;
  [in] DXVADDI_PROCAMPVALUES        ProcAmpValues;
  [in] DXVADDI_FIXED32              Alpha;
  [in] DXVADDI_FILTERVALUES         NoiseFilterLuma;
  [in] DXVADDI_FILTERVALUES         NoiseFilterChroma;
  [in] DXVADDI_FILTERVALUES         DetailFilterLuma;
  [in] DXVADDI_FILTERVALUES         DetailFilterChroma;
  [in] DXVADDI_VIDEOSAMPLE          *pSrcSurfaces;
  [in] UINT                         NumSrcSurfaces;
} D3DDDIARG_VIDEOPROCESSBLT;