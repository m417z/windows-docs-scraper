NTSTATUS AllocateAudioBuffer(
  ULONG               RequestedSize,
  PMDL                *AudioBufferMdl,
  ULONG               *ActualSize,
  ULONG               *OffsetFromFirstPage,
  MEMORY_CACHING_TYPE *CacheType
);