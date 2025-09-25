typedef struct _DXVA_SliceInfo {
  WORD  wHorizontalPosition;
  WORD  wVerticalPosition;
  DWORD dwSliceBitsInBuffer;
  DWORD dwSliceDataLocation;
  BYTE  bStartCodeBitOffset;
  BYTE  bReservedBits;
  WORD  wMBbitOffset;
  WORD  wNumberMBsInSlice;
  WORD  wQuantizerScaleCode;
  WORD  wBadSliceChopping;
} DXVA_SliceInfo, *LPDXVA_SliceInfo;