typedef struct _NVCACHE_REQUEST_BLOCK {
  ULONG     NRBSize;
  USHORT    Function;
  ULONG     NRBFlags;
  ULONG     NRBStatus;
  ULONG     Count;
  ULONGLONG LBA;
  ULONG     DataBufSize;
  ULONG     NVCacheStatus;
  ULONG     NVCacheSubStatus;
} NVCACHE_REQUEST_BLOCK, *PNVCACHE_REQUEST_BLOCK;