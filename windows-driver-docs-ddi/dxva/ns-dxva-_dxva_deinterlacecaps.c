typedef struct _DXVA_DeinterlaceCaps {
  DWORD                 Size;
  DWORD                 NumPreviousOutputFrames;
  DWORD                 InputPool;
  DWORD                 NumForwardRefSamples;
  DWORD                 NumBackwardRefSamples;
  D3DFORMAT             d3dOutputFormat;
  DXVA_VideoProcessCaps VideoProcessingCaps;
  DXVA_DeinterlaceTech  DeinterlaceTechnology;
} DXVA_DeinterlaceCaps, *LPDXVA_DeinterlaceCaps;