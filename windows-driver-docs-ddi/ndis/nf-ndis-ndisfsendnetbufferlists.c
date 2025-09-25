VOID NdisFSendNetBufferLists(
  [in] NDIS_HANDLE                       NdisFilterHandle,
       __drv_aliasesMem PNET_BUFFER_LIST NetBufferList,
  [in] NDIS_PORT_NUMBER                  PortNumber,
  [in] ULONG                             SendFlags
);