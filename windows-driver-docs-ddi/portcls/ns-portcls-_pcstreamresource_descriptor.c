typedef struct _PCSTREAMRESOURCE_DESCRIPTOR {
  ULONG                Size;
  ULONG                Flags;
  PDEVICE_OBJECT       Pdo;
  PcStreamResourceType Type;
  union {
    struct {
      ULONG Version;
      PVOID Generic;
    } Interrupt;
    PETHREAD Thread;
    PVOID    ResourceSet;
  } Resource;
} PCSTREAMRESOURCE_DESCRIPTOR, *PPCSTREAMRESOURCE_DESCRIPTOR;