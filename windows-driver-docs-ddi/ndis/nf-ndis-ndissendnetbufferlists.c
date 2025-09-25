VOID NdisSendNetBufferLists(
  [in] NDIS_HANDLE                       NdisBindingHandle,
  [in] __drv_aliasesMem PNET_BUFFER_LIST NetBufferLists,
  [in] NDIS_PORT_NUMBER                  PortNumber,
  [in] ULONG                             SendFlags
);