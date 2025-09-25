typedef struct _BDA_BUFFER {
  PBDARESULT lResult;
  ULONG      ulBufferSize;
  BYTE       argbBuffer[MIN_DIMENSION];
} BDA_BUFFER, *PBDA_BUFFER;