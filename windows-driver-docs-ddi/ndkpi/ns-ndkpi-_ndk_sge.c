typedef struct _NDK_SGE {
  union {
    PVOID               VirtualAddress;
    NDK_LOGICAL_ADDRESS LogicalAddress;
  };
  ULONG  Length;
  UINT32 MemoryRegionToken;
} NDK_SGE;