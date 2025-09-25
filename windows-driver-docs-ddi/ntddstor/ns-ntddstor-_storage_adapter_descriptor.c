typedef struct _STORAGE_ADAPTER_DESCRIPTOR {
  ULONG   Version;
  ULONG   Size;
  ULONG   MaximumTransferLength;
  ULONG   MaximumPhysicalPages;
  ULONG   AlignmentMask;
  BOOLEAN AdapterUsesPio;
  BOOLEAN AdapterScansDown;
  BOOLEAN CommandQueueing;
  BOOLEAN AcceleratedTransfer;
#if ...
  BOOLEAN BusType;
#else
  UCHAR   BusType;
#endif
  USHORT  BusMajorVersion;
  USHORT  BusMinorVersion;
  UCHAR   SrbType;
  UCHAR   AddressType;
} STORAGE_ADAPTER_DESCRIPTOR, *PSTORAGE_ADAPTER_DESCRIPTOR;