typedef struct _STORAGE_ADAPTER_DESCRIPTOR {
  DWORD   Version;
  DWORD   Size;
  DWORD   MaximumTransferLength;
  DWORD   MaximumPhysicalPages;
  DWORD   AlignmentMask;
  BOOLEAN AdapterUsesPio;
  BOOLEAN AdapterScansDown;
  BOOLEAN CommandQueueing;
  BOOLEAN AcceleratedTransfer;
#if ...
  BOOLEAN BusType;
#else
  BYTE    BusType;
#endif
  WORD    BusMajorVersion;
  WORD    BusMinorVersion;
  BYTE    SrbType;
  BYTE    AddressType;
} STORAGE_ADAPTER_DESCRIPTOR, *PSTORAGE_ADAPTER_DESCRIPTOR;