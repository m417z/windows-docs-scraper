MINIPORT_RETURN_NET_BUFFER_LISTS MiniportReturnNetBufferLists;

VOID MiniportReturnNetBufferLists(
  [in] NDIS_HANDLE MiniportAdapterContext,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] ULONG ReturnFlags
)
{...}