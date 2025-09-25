typedef struct _DXVA2_VideoProcessorCaps {
  UINT    DeviceCaps;
  D3DPOOL InputPool;
  UINT    NumForwardRefSamples;
  UINT    NumBackwardRefSamples;
  UINT    Reserved;
  UINT    DeinterlaceTechnology;
  UINT    ProcAmpControlCaps;
  UINT    VideoProcessorOperations;
  UINT    NoiseFilterTechnology;
  UINT    DetailFilterTechnology;
} DXVA2_VideoProcessorCaps;