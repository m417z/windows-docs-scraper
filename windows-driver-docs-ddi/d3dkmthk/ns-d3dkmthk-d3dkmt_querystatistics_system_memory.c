typedef struct _D3DKMT_QUERYSTATISTICS_SYSTEM_MEMORY {
  D3DKMT_ALIGN64 ULONGLONG BytesAllocated;
  D3DKMT_ALIGN64 ULONGLONG BytesReserved;
  ULONG                    SmallAllocationBlocks;
  ULONG                    LargeAllocationBlocks;
  D3DKMT_ALIGN64 ULONGLONG WriteCombinedBytesAllocated;
  D3DKMT_ALIGN64 ULONGLONG WriteCombinedBytesReserved;
  D3DKMT_ALIGN64 ULONGLONG CachedBytesAllocated;
  D3DKMT_ALIGN64 ULONGLONG CachedBytesReserved;
  D3DKMT_ALIGN64 ULONGLONG SectionBytesAllocated;
  D3DKMT_ALIGN64 ULONGLONG SectionBytesReserved;
  D3DKMT_ALIGN64 ULONGLONG BytesZeroed;
  D3DKMT_ALIGN64 ULONGLONG Reserved;
} D3DKMT_QUERYSTATISTICS_SYSTEM_MEMORY;