typedef struct _SendCTPassThru_OUT {
  ULONG HBAStatus;
  ULONG TotalResponseBufferCount;
  ULONG ActualResponseBufferCount;
  UCHAR ResponseBuffer[1];
} SendCTPassThru_OUT, *PSendCTPassThru_OUT;