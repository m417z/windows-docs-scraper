FILTER_SEND_NET_BUFFER_LISTS FilterSendNetBufferLists;

VOID FilterSendNetBufferLists(
  [in] NDIS_HANDLE FilterModuleContext,
       PNET_BUFFER_LIST NetBufferList,
  [in] NDIS_PORT_NUMBER PortNumber,
  [in] ULONG SendFlags
)
{...}