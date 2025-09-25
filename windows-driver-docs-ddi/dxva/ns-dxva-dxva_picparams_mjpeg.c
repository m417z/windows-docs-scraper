typedef struct _DXVA_PicParams_MJPEG {
  UINT   width;
  UINT   height;
  UCHAR  numComponents;
  UCHAR  bitDepth;
  USHORT reserved16Bits;
  UCHAR  quantizationTableSelector[4];
  UINT   scanOffset[4];
  UINT   scanSize[4];
  UCHAR  componentIdentifier[4];
  USHORT restartInterval;
  USHORT reserved16Bits2;
  UINT   reserved32Bits;
  UINT   statusReportFeedbackNumber;
} DXVA_PicParams_MJPEG, *LPDXVA_PicParams_MJPEG;