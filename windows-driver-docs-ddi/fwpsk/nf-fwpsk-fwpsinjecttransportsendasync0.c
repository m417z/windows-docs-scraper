NTSTATUS FwpsInjectTransportSendAsync0(
  [in]           HANDLE                      injectionHandle,
  [in, optional] HANDLE                      injectionContext,
  [in]           UINT64                      endpointHandle,
  [in]           UINT32                      flags,
  [in, optional] FWPS_TRANSPORT_SEND_PARAMS0 *sendArgs,
  [in]           ADDRESS_FAMILY              addressFamily,
  [in]           COMPARTMENT_ID              compartmentId,
  [in, out]      NET_BUFFER_LIST             *netBufferList,
  [in]           FWPS_INJECT_COMPLETE0       completionFn,
  [in, optional] HANDLE                      completionContext
);