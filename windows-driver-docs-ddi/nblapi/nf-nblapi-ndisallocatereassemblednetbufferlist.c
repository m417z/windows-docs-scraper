NDIS_EXPORTED_ROUTINE NET_BUFFER_LIST * NdisAllocateReassembledNetBufferList(
                 NET_BUFFER_LIST *FragmentNetBufferList,
  [in, optional] NDIS_HANDLE     NetBufferAndNetBufferListPoolHandle,
  [in]           ULONG           StartOffset,
  [in]           ULONG           DataOffsetDelta,
  [in]           ULONG           DataBackFill,
  [in]           ULONG           AllocateReassembleFlags
);