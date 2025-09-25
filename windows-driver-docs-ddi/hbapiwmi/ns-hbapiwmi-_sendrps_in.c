typedef struct _SendRPS_IN {
  UCHAR PortWWN[8];
  UCHAR AgentWWN[8];
  UCHAR ObjectWWN[8];
  ULONG AgentDomain;
  ULONG ObjectPortNumber;
} SendRPS_IN, *PSendRPS_IN;