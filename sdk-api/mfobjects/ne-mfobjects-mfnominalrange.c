typedef enum _MFNominalRange {
  MFNominalRange_Unknown = 0,
  MFNominalRange_Normal = 1,
  MFNominalRange_Wide = 2,
  MFNominalRange_0_255 = 1,
  MFNominalRange_16_235 = 2,
  MFNominalRange_48_208 = 3,
  MFNominalRange_64_127 = 4,
  MFNominalRange_Last,
  MFNominalRange_ForceDWORD = 0x7fffffff
} MFNominalRange;