typedef struct _SM_SendSRL_OUT {
  ULONG HBAStatus;
  ULONG TotalRespBufferSize;
  ULONG OutRespBufferSize;
  UCHAR RespBuffer[1];
} SM_SendSRL_OUT, *PSM_SendSRL_OUT;