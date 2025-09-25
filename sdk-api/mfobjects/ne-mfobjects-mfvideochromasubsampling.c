typedef enum _MFVideoChromaSubsampling {
  MFVideoChromaSubsampling_Unknown = 0,
  MFVideoChromaSubsampling_ProgressiveChroma = 0x8,
  MFVideoChromaSubsampling_Horizontally_Cosited = 0x4,
  MFVideoChromaSubsampling_Vertically_Cosited = 0x2,
  MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes = 0x1,
  MFVideoChromaSubsampling_MPEG2,
  MFVideoChromaSubsampling_MPEG1,
  MFVideoChromaSubsampling_DV_PAL,
  MFVideoChromaSubsampling_Cosited,
  MFVideoChromaSubsampling_Last,
  MFVideoChromaSubsampling_ForceDWORD = 0x7fffffff
} MFVideoChromaSubsampling;