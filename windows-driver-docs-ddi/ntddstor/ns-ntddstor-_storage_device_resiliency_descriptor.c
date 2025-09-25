typedef struct _STORAGE_DEVICE_RESILIENCY_DESCRIPTOR {
  ULONG Version;
  ULONG Size;
  ULONG NameOffset;
  ULONG NumberOfLogicalCopies;
  ULONG NumberOfPhysicalCopies;
  ULONG PhysicalDiskRedundancy;
  ULONG NumberOfColumns;
  ULONG Interleave;
} STORAGE_DEVICE_RESILIENCY_DESCRIPTOR, *PSTORAGE_DEVICE_RESILIENCY_DESCRIPTOR;