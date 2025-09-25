typedef struct tagNC_ADDRESS {
  struct NET_ADDRESS_INFO_ *pAddrInfo;
  USHORT                   PortNumber;
  BYTE                     PrefixLength;
} NC_ADDRESS, *PNC_ADDRESS;