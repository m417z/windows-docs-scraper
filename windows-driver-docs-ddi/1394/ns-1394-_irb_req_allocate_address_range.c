typedef struct _IRB_REQ_ALLOCATE_ADDRESS_RANGE {
  PMDL           Mdl;
  ULONG          fulFlags;
  ULONG          nLength;
  ULONG          MaxSegmentSize;
  ULONG          fulAccessType;
  ULONG          fulNotificationOptions;
  PVOID          Callback;
  PVOID          Context;
  ADDRESS_OFFSET Required1394Offset;
  PSLIST_HEADER  FifoSListHead;
  PKSPIN_LOCK    FifoSpinLock;
  ULONG          AddressesReturned;
  PADDRESS_RANGE p1394AddressRange;
  HANDLE         hAddressRange;
  PVOID          DeviceExtension;
} IRB_REQ_ALLOCATE_ADDRESS_RANGE;