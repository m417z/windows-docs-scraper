NTSTATUS AllocateBufferWithNotification(
  [in]  ULONG               NotificationCount,
  [in]  ULONG               RequestedSize,
  [out] PMDL                *AudioBufferMdl,
  [out] ULONG               *ActualSize,
  [out] ULONG               *OffsetFromFirstPage,
  [out] MEMORY_CACHING_TYPE *CacheType
);