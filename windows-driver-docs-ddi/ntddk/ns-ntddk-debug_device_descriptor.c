typedef struct _DEBUG_DEVICE_DESCRIPTOR {
  ULONG                     Bus;
  ULONG                     Slot;
  USHORT                    Segment;
  USHORT                    VendorID;
  USHORT                    DeviceID;
  UCHAR                     BaseClass;
  UCHAR                     SubClass;
  UCHAR                     ProgIf;
  union {
    UCHAR Flags;
    struct {
      UCHAR DbgHalScratchAllocated : 1;
      UCHAR DbgBarsMapped : 1;
      UCHAR DbgScratchAllocated : 1;
      UCHAR DbgUncachedMemory : 1;
      UCHAR DbgSynthetic : 1;
    };
  };
  BOOLEAN                   Initialized;
  BOOLEAN                   Configured;
  DEBUG_DEVICE_ADDRESS      BaseAddress[MAXIMUM_DEBUG_BARS];
  DEBUG_MEMORY_REQUIREMENTS Memory;
  ULONG                     Dbg2TableIndex;
  USHORT                    PortType;
  USHORT                    PortSubtype;
  PVOID                     OemData;
  ULONG                     OemDataLength;
  KD_NAMESPACE_ENUM         NameSpace;
  PWCHAR                    NameSpacePath;
  ULONG                     NameSpacePathLength;
  ULONG                     TransportType;
  DEBUG_TRANSPORT_DATA      TransportData;
  DEBUG_EFI_IOMMU_DATA      EfiIoMmuData;
} DEBUG_DEVICE_DESCRIPTOR, *PDEBUG_DEVICE_DESCRIPTOR;