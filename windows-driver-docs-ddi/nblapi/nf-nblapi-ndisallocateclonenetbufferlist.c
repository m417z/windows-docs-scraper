NDIS_EXPORTED_ROUTINE NET_BUFFER_LIST * NdisAllocateCloneNetBufferList(
  [in]           NET_BUFFER_LIST *OriginalNetBufferList,
  [in, optional] NDIS_HANDLE     NetBufferListPoolHandle,
  [in, optional] NDIS_HANDLE     NetBufferPoolHandle,
  [in]           ULONG           AllocateCloneFlags
);