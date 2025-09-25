NTSTATUS FwpsAllocateDeepCloneNetBufferList0(
  [in, out]      NET_BUFFER_LIST *originalNetBufferList,
  [in, optional] NDIS_HANDLE     netBufferListPoolHandle,
  [in, optional] NDIS_HANDLE     netBufferPoolHandle,
  [out]          NET_BUFFER_LIST **netBufferList
);