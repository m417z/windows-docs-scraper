typedef enum _MFVideoInterlaceMode {
  MFVideoInterlace_Unknown = 0,
  MFVideoInterlace_Progressive = 2,
  MFVideoInterlace_FieldInterleavedUpperFirst = 3,
  MFVideoInterlace_FieldInterleavedLowerFirst = 4,
  MFVideoInterlace_FieldSingleUpper = 5,
  MFVideoInterlace_FieldSingleLower = 6,
  MFVideoInterlace_MixedInterlaceOrProgressive = 7,
  MFVideoInterlace_Last,
  MFVideoInterlace_ForceDWORD = 0x7fffffff
} MFVideoInterlaceMode;