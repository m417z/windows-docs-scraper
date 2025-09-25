VOID NdisFIndicateReceiveNetBufferLists(
  [in] NDIS_HANDLE      NdisFilterHandle,
  [in] PNET_BUFFER_LIST NetBufferLists,
  [in] NDIS_PORT_NUMBER PortNumber,
  [in] ULONG            NumberOfNetBufferLists,
  [in] ULONG            ReceiveFlags
);