typedef struct _SM_SendRPS_OUT {
  ULONG HBAStatus;
  ULONG TotalRespBufferSize;
  ULONG OutRespBufferSize;
  UCHAR RespBuffer[1];
} SM_SendRPS_OUT, *PSM_SendRPS_OUT;