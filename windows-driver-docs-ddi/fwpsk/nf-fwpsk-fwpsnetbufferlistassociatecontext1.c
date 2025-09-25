NTSTATUS FwpsNetBufferListAssociateContext1(
  [in, out] NET_BUFFER_LIST                 *netBufferList,
  [in]      UINT16                          layerId,
  [in]      UINT64                          context,
  [in]      UINT64                          contextTag,
            GUID                            *providerGuid,
  [in, out] void                            *deviceObject,
  [in]      FWPS_NET_BUFFER_LIST_NOTIFY_FN1 notifyFn,
  [in]      UINT32                          flags
);