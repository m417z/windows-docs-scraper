NTSTATUS FwpsInjectTransportReceiveAsync0(
  [in]           HANDLE                injectionHandle,
  [in, optional] HANDLE                injectionContext,
                 PVOID                 reserved,
  [in]           UINT32                flags,
  [in]           ADDRESS_FAMILY        addressFamily,
  [in]           COMPARTMENT_ID        compartmentId,
  [in]           IF_INDEX              interfaceIndex,
  [in]           IF_INDEX              subInterfaceIndex,
  [in, out]      NET_BUFFER_LIST       *netBufferList,
  [in]           FWPS_INJECT_COMPLETE0 completionFn,
  [in, optional] HANDLE                completionContext
);