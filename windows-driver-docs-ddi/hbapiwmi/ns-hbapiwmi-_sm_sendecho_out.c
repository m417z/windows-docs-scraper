typedef struct _SM_SendECHO_OUT {
  ULONG HBAStatus;
  ULONG OutRespBufferSize;
  UCHAR RespBuffer[1];
} SM_SendECHO_OUT, *PSM_SendECHO_OUT;