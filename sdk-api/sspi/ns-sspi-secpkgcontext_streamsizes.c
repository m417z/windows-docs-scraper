typedef struct _SecPkgContext_StreamSizes {
  unsigned long cbHeader;
  unsigned long cbTrailer;
  unsigned long cbMaximumMessage;
  unsigned long cBuffers;
  unsigned long cbBlockSize;
} SecPkgContext_StreamSizes, *PSecPkgContext_StreamSizes;