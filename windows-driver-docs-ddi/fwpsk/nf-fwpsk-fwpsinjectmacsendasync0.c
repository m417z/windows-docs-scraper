NTSTATUS FwpsInjectMacSendAsync0(
  [in]           HANDLE               injectionHandle,
  [in, optional] HANDLE               injectionContext,
  [in]           UINT32               flags,
  [in]           UINT16               layerId,
  [in]           IF_INDEX             interfaceIndex,
  [in]           NDIS_PORT_NUMBER     NdisPortNumber,
  [in, out]      NET_BUFFER_LIST      *netBufferLists,
  [in]           FWPS_INJECT_COMPLETE completionFn,
  [in, optional] HANDLE               completionContext
);