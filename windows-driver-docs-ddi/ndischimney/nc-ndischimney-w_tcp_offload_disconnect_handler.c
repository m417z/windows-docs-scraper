W_TCP_OFFLOAD_DISCONNECT_HANDLER WTcpOffloadDisconnectHandler;

NDIS_STATUS WTcpOffloadDisconnectHandler(
  [in] IN NDIS_HANDLE MiniportAdapterContext,
  [in] IN PVOID MiniportOffloadContext,
  [in] IN PNET_BUFFER_LIST NetBufferList,
  [in] IN ULONG Flags
)
{...}