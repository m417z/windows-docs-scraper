NDIS_EXPORTED_ROUTINE NET_BUFFER * NdisAllocateNetBuffer(
  [in]           NDIS_HANDLE PoolHandle,
  [in, optional] MDL         *MdlChain,
  [in]           ULONG       DataOffset,
  [in]           SIZE_T      DataLength
);