MINIPORT_CO_SEND_NET_BUFFER_LISTS MiniportCoSendNetBufferLists;

VOID MiniportCoSendNetBufferLists(
  [in] NDIS_HANDLE MiniportVcContext,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] ULONG SendFlags
)
{...}