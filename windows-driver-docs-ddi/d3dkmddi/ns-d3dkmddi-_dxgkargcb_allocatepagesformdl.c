typedef struct _DXGKARGCB_ALLOCATEPAGESFORMDL {
  [in]  PHYSICAL_ADDRESS         LowAddress;
  [in]  PHYSICAL_ADDRESS         HighAddress;
  [in]  PHYSICAL_ADDRESS         SkipBytes;
  [in]  SIZE_T                   TotalBytes;
  [in]  DXGK_MEMORY_CACHING_TYPE CacheType;
  [in]  ULONG                    Flags;
  [out] HANDLE                   hMemoryHandle;
  [out] PMDL                     pMdl;
} DXGKARGCB_ALLOCATEPAGESFORMDL;