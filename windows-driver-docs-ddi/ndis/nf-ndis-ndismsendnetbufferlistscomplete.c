VOID NdisMSendNetBufferListsComplete(
  [in] NDIS_HANDLE      MiniportAdapterHandle,
       PNET_BUFFER_LIST NetBufferList,
  [in] ULONG            SendCompleteFlags
);