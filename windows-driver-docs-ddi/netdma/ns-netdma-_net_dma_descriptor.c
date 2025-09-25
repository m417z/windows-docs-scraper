typedef struct _NET_DMA_DESCRIPTOR {
  union {
    ULONG TransferSize;
    struct {
      ULONG DCAContext : 32;
    } DCAContext32;
    struct {
      ULONG DCAContext : 16;
      ULONG Reserved : 16;
    } DCAContext16;
    struct {
      ULONG DCAContext : 8;
      ULONG Reserved : 24;
    } DCAContext8;
  };
  ULONG            ControlFlags;
  PHYSICAL_ADDRESS SourceAddress;
  PHYSICAL_ADDRESS DestinationAddress;
  PHYSICAL_ADDRESS NextDescriptor;
  union {
    ULONG64          Reserved1;
    PHYSICAL_ADDRESS NextSourceAddress;
  };
  union {
    ULONG64          Reserved2;
    PHYSICAL_ADDRESS NextDestinationAddress;
  };
  ULONG64          UserContext1;
  ULONG64          UserContext2;
} NET_DMA_DESCRIPTOR, *PNET_DMA_DESCRIPTOR;