typedef struct _SM_SendLIRR_OUT {
  ULONG HBAStatus;
  ULONG TotalRespBufferSize;
  ULONG OutRespBufferSize;
  UCHAR RespBuffer[1];
} SM_SendLIRR_OUT, *PSM_SendLIRR_OUT;