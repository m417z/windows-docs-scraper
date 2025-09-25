typedef struct tagPXE_ADDRESS {
  ULONG  uFlags;
  union {
    BYTE  bAddress[PXE_MAX_ADDRESS];
    ULONG uIpAddress;
  };
  ULONG  uAddrLen;
  USHORT uPort;
} PXE_ADDRESS, *PPXE_ADDRESS;