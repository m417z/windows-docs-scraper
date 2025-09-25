typedef struct _SOCKADDR_BTH {
  USHORT   addressFamily;
  BTH_ADDR btAddr;
  GUID     serviceClassId;
  ULONG    port;
} SOCKADDR_BTH, *PSOCKADDR_BTH;