VOID NdisMCoSendNetBufferListsComplete(
  [in] IN NDIS_HANDLE      NdisVcHandle,
  [in] IN PNET_BUFFER_LIST NetBufferLists,
  [in] IN ULONG            SendCompleteFlags
);