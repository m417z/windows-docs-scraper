VOID NdisMCoIndicateReceiveNetBufferLists(
  [in] IN NDIS_HANDLE      NdisVcHandle,
  [in] IN PNET_BUFFER_LIST NetBufferLists,
  [in] IN ULONG            NumberOfNetBufferLists,
  [in] IN ULONG            CoReceiveFlags
);