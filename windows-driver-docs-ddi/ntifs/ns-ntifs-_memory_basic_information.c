typedef struct _MEMORY_BASIC_INFORMATION {
  PVOID  BaseAddress;
  PVOID  AllocationBase;
  ULONG  AllocationProtect;
  USHORT PartitionId;
  SIZE_T RegionSize;
  ULONG  State;
  ULONG  Protect;
  ULONG  Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;