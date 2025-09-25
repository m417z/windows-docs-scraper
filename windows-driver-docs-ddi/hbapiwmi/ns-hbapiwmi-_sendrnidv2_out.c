typedef struct _SendRNIDV2_OUT {
  ULONG HBAStatus;
  ULONG TotalRspBufferSize;
  ULONG ActualRspBufferSize;
  UCHAR RspBuffer[1];
} SendRNIDV2_OUT, *PSendRNIDV2_OUT;