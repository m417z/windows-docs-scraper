typedef struct _SendRPL_IN {
  UCHAR PortWWN[8];
  UCHAR AgentWWN[8];
  ULONG agent_domain;
  ULONG portIndex;
} SendRPL_IN, *PSendRPL_IN;