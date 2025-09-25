typedef enum _DXVA2_VideoTransferFunction {
  DXVA2_VideoTransFuncMask = 0x1f,
  DXVA2_VideoTransFunc_Unknown = 0,
  DXVA2_VideoTransFunc_10 = 1,
  DXVA2_VideoTransFunc_18 = 2,
  DXVA2_VideoTransFunc_20 = 3,
  DXVA2_VideoTransFunc_22 = 4,
  DXVA2_VideoTransFunc_709 = 5,
  DXVA2_VideoTransFunc_240M = 6,
  DXVA2_VideoTransFunc_sRGB = 7,
  DXVA2_VideoTransFunc_28 = 8
} DXVA2_VideoTransferFunction;