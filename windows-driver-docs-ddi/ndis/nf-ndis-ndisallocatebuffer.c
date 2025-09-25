VOID NdisAllocateBuffer(
  [out]          PNDIS_STATUS Status,
  [out]          PNDIS_BUFFER *Buffer,
  [in, optional] NDIS_HANDLE  PoolHandle,
  [in]           PVOID        VirtualAddress,
  [in]           UINT         Length
);