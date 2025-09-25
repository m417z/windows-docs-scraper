typedef struct _SM_SendRNID_OUT {
  ULONG HBAStatus;
  ULONG TotalRespBufferSize;
  ULONG OutRespBufferSize;
  UCHAR RespBuffer[1];
} SM_SendRNID_OUT, *PSM_SendRNID_OUT;