typedef struct _PingIPAddress_IN {
  ULONG            RequestCount;
  ULONG            RequestSize;
  ULONG            Timeout;
  ISCSI_IP_Address Address;
} PingIPAddress_IN, *PPingIPAddress_IN;