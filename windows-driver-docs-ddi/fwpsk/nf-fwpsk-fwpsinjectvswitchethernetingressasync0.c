NTSTATUS FwpsInjectvSwitchEthernetIngressAsync0(
  [in]           HANDLE                injectionHandle,
  [in, optional] HANDLE                injectionContext,
  [in]           UINT32                flags,
  [in, optional] void                  *reserved,
  [in]           const FWP_BYTE_BLOB   *vSwitchId,
  [in]           NDIS_SWITCH_PORT_ID   vSwitchSourcePortId,
  [in]           NDIS_SWITCH_NIC_INDEX vSwitchSourceNicIndex,
                 NET_BUFFER_LIST       *netBufferLists,
  [in]           FWPS_INJECT_COMPLETE  completionFn,
  [in, optional] HANDLE                completionContext
);