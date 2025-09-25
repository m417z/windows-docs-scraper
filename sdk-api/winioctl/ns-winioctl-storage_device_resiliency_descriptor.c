typedef struct _STORAGE_DEVICE_RESILIENCY_DESCRIPTOR {
  DWORD Version;
  DWORD Size;
  DWORD NameOffset;
  DWORD NumberOfLogicalCopies;
  DWORD NumberOfPhysicalCopies;
  DWORD PhysicalDiskRedundancy;
  DWORD NumberOfColumns;
  DWORD Interleave;
} STORAGE_DEVICE_RESILIENCY_DESCRIPTOR, *PSTORAGE_DEVICE_RESILIENCY_DESCRIPTOR;