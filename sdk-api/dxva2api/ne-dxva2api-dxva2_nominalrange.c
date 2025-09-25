typedef enum _DXVA2_NominalRange {
  DXVA2_NominalRangeMask = 0x7,
  DXVA2_NominalRange_Unknown = 0,
  DXVA2_NominalRange_Normal = 1,
  DXVA2_NominalRange_Wide = 2,
  DXVA2_NominalRange_0_255 = 1,
  DXVA2_NominalRange_16_235 = 2,
  DXVA2_NominalRange_48_208 = 3
} DXVA2_NominalRange;