FILTER_RETURN_NET_BUFFER_LISTS FilterReturnNetBufferLists;

VOID FilterReturnNetBufferLists(
  [in] NDIS_HANDLE FilterModuleContext,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] ULONG ReturnFlags
)
{...}