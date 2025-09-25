HRESULT ConvertToBmp(
  BYTE           *pSource,
  INT            iSourceSize,
  BYTE           **ppDest,
  INT            *piDestSize,
  BMP_IMAGE_INFO *pBmpImageInfo,
  SKIP_AMOUNT    iSkipAmt
);