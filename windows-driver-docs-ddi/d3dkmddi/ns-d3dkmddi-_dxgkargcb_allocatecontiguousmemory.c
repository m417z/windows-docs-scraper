typedef struct _DXGKARGCB_ALLOCATECONTIGUOUSMEMORY {
  [in]  SIZE_T                   NumberOfBytes;
  [in]  PHYSICAL_ADDRESS         LowestAcceptableAddress;
  [in]  PHYSICAL_ADDRESS         HighestAcceptableAddress;
  [in]  PHYSICAL_ADDRESS         BoundaryAddressMultiple;
  [in]  DXGK_MEMORY_CACHING_TYPE CacheType;
  [out] HANDLE                   hMemoryHandle;
  [out] PVOID                    pMemory;
} DXGKARGCB_ALLOCATECONTIGUOUSMEMORY;