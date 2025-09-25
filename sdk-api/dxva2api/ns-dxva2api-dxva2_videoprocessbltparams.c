typedef struct _DXVA2_VideoProcessBltParams {
  REFERENCE_TIME       TargetFrame;
  RECT                 TargetRect;
  SIZE                 ConstrictionSize;
  UINT                 StreamingFlags;
  DXVA2_AYUVSample16   BackgroundColor;
  DXVA2_ExtendedFormat DestFormat;
  DXVA2_ProcAmpValues  ProcAmpValues;
  DXVA2_Fixed32        Alpha;
  DXVA2_FilterValues   NoiseFilterLuma;
  DXVA2_FilterValues   NoiseFilterChroma;
  DXVA2_FilterValues   DetailFilterLuma;
  DXVA2_FilterValues   DetailFilterChroma;
  DWORD                DestData;
} DXVA2_VideoProcessBltParams;