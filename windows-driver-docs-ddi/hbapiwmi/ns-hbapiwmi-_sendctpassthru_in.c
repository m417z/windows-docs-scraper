typedef struct _SendCTPassThru_IN {
  UCHAR PortWWN[8];
  ULONG RequestBufferCount;
  UCHAR RequestBuffer[1];
} SendCTPassThru_IN, *PSendCTPassThru_IN;