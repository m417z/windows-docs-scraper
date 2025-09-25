typedef enum _DXVA2_VideoTransferMatrix {
  DXVA2_VideoTransferMatrixMask = 0x7,
  DXVA2_VideoTransferMatrix_Unknown = 0,
  DXVA2_VideoTransferMatrix_BT709 = 1,
  DXVA2_VideoTransferMatrix_BT601 = 2,
  DXVA2_VideoTransferMatrix_SMPTE240M = 3
} DXVA2_VideoTransferMatrix;