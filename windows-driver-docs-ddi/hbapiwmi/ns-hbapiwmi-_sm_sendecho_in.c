typedef struct _SM_SendECHO_IN {
  UCHAR HbaPortWWN[8];
  UCHAR DestWWN[8];
  ULONG DestFCID;
  ULONG InRespBufferMaxSize;
  ULONG ReqBufferSize;
  UCHAR ReqBuffer[1];
} SM_SendECHO_IN, *PSM_SendECHO_IN;