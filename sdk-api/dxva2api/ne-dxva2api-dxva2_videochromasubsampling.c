typedef enum _DXVA2_VideoChromaSubSampling {
  DXVA2_VideoChromaSubsamplingMask = 0xf,
  DXVA2_VideoChromaSubsampling_Unknown = 0,
  DXVA2_VideoChromaSubsampling_ProgressiveChroma = 0x8,
  DXVA2_VideoChromaSubsampling_Horizontally_Cosited = 0x4,
  DXVA2_VideoChromaSubsampling_Vertically_Cosited = 0x2,
  DXVA2_VideoChromaSubsampling_Vertically_AlignedChromaPlanes = 0x1,
  DXVA2_VideoChromaSubsampling_MPEG2,
  DXVA2_VideoChromaSubsampling_MPEG1,
  DXVA2_VideoChromaSubsampling_DV_PAL,
  DXVA2_VideoChromaSubsampling_Cosited
} DXVA2_VideoChromaSubSampling;