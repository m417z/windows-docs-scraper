typedef struct _STOR_ADDR_NVME {
  USHORT Type;
  USHORT Port;
  ULONG  AddressLength;
  PVOID  Controller;
  ULONG  NamespaceId;
  ULONG  Reserved;
} STOR_ADDR_NVME, *PSTOR_ADDR_NVME;