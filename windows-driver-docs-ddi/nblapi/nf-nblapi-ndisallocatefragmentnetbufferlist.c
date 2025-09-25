NDIS_EXPORTED_ROUTINE NET_BUFFER_LIST * NdisAllocateFragmentNetBufferList(
  [in] NET_BUFFER_LIST *OriginalNetBufferList,
       NDIS_HANDLE     NetBufferListPool,
       NDIS_HANDLE     NetBufferPool,
  [in] ULONG           StartOffset,
  [in] ULONG           MaximumLength,
  [in] ULONG           DataOffsetDelta,
  [in] ULONG           DataBackFill,
  [in] ULONG           AllocateFragmentFlags
);