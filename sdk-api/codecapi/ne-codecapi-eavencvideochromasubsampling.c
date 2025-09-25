typedef enum eAVEncVideoChromaSubsampling {
  eAVEncVideoChromaSubsamplingFormat_SameAsSource = 0,
  eAVEncVideoChromaSubsamplingFormat_ProgressiveChroma = 0x8,
  eAVEncVideoChromaSubsamplingFormat_Horizontally_Cosited = 0x4,
  eAVEncVideoChromaSubsamplingFormat_Vertically_Cosited = 0x2,
  eAVEncVideoChromaSubsamplingFormat_Vertically_AlignedChromaPlanes = 0x1
} ;