NDIS_TCP_OFFLOAD_RECEIVE_INDICATE NdisTcpOffloadReceiveIndicate;

NDIS_STATUS NdisTcpOffloadReceiveIndicate(
  [in]  IN NDIS_HANDLE NdisOffloadHandle,
  [in]  IN PNET_BUFFER_LIST NetBufferList,
  [in]  IN NDIS_STATUS Status,
  [out] OUT PULONG BytesConsumed
)
{...}