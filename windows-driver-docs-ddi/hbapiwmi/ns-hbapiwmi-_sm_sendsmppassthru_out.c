typedef struct _SM_SendSMPPassThru_OUT {
  ULONG HBAStatus;
  ULONG TotalRespBufferSize;
  ULONG OutRespBufferSize;
  UCHAR RespBuffer[1];
} SM_SendSMPPassThru_OUT, *PSM_SendSMPPassThru_OUT;