VOID NdisAllocatePacketPoolEx(
  [out] PNDIS_STATUS Status,
  [out] PNDIS_HANDLE PoolHandle,
  [in]  UINT         NumberOfDescriptors,
  [in]  UINT         NumberOfOverflowDescriptors,
  [in]  UINT         ProtocolReservedLength
);