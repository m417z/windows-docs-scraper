typedef struct _SM_SendRPL_OUT {
  ULONG HBAStatus;
  ULONG TotalRespBufferSize;
  ULONG OutRespBufferSize;
  UCHAR RespBuffer[1];
} SM_SendRPL_OUT, *PSM_SendRPL_OUT;