typedef struct _SendLIRR_OUT {
  ULONG HBAStatus;
  ULONG TotalRspBufferSize;
  ULONG ActualRspBufferSize;
  UCHAR RspBuffer[1];
} SendLIRR_OUT, *PSendLIRR_OUT;