W_TERMINATE_OFFLOAD_HANDLER WTerminateOffloadHandler;

VOID WTerminateOffloadHandler(
  [in]      IN NDIS_HANDLE MiniportAdapterContext,
  [in, out] IN OUT PNDIS_MINIPORT_OFFLOAD_BLOCK_LIST OffloadBlockList
)
{...}