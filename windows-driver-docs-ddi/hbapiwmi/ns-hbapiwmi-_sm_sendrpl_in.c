typedef struct _SM_SendRPL_IN {
  UCHAR HbaPortWWN[8];
  UCHAR AgentWWN[8];
  ULONG AgentDomain;
  ULONG PortIndex;
  ULONG InRespBufferMaxSize;
} SM_SendRPL_IN, *PSM_SendRPL_IN;