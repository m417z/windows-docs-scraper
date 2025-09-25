NTSTATUS FwpsAllocateCloneNetBufferList0(
  [in, out]      NET_BUFFER_LIST *originalNetBufferList,
  [in, optional] NDIS_HANDLE     netBufferListPoolHandle,
  [in, optional] NDIS_HANDLE     netBufferPoolHandle,
  [in]           ULONG           allocateCloneFlags,
  [out]          NET_BUFFER_LIST **netBufferList
);