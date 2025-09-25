FILTER_SEND_NET_BUFFER_LISTS_COMPLETE FilterSendNetBufferListsComplete;

VOID FilterSendNetBufferListsComplete(
  [in] NDIS_HANDLE FilterModuleContext,
       PNET_BUFFER_LIST NetBufferList,
  [in] ULONG SendCompleteFlags
)
{...}