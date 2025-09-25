VOID NdisMIndicateReceiveNetBufferLists(
  [in] NDIS_HANDLE      MiniportAdapterHandle,
       PNET_BUFFER_LIST NetBufferList,
  [in] NDIS_PORT_NUMBER PortNumber,
  [in] ULONG            NumberOfNetBufferLists,
  [in] ULONG            ReceiveFlags
);