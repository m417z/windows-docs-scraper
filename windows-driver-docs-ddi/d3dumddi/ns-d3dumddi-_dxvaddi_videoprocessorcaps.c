typedef struct _DXVADDI_VIDEOPROCESSORCAPS {
  [out] D3DDDI_POOL  InputPool;
  [out] UINT         NumForwardRefSamples;
  [out] UINT         NumBackwardRefSamples;
  [out] D3DDDIFORMAT OutputFormat;
  [out] UINT         DeinterlaceTechnology;
  [out] UINT         ProcAmpControlCaps;
  [out] UINT         VideoProcessorOperations;
  [out] UINT         NoiseFilterTechnology;
  [out] UINT         DetailFilterTechnology;
} DXVADDI_VIDEOPROCESSORCAPS;