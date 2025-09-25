TCP_OFFLOAD_RECEIVE_INDICATE_HANDLER TcpOffloadReceiveIndicateHandler;

NDIS_STATUS TcpOffloadReceiveIndicateHandler(
  [in]  IN PVOID OffloadContext,
  [in]  IN PNET_BUFFER_LIST NetBufferList,
  [in]  IN NDIS_STATUS Status,
  [out] OUT PULONG BytesConsumed
)
{...}