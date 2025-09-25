typedef enum _NDIS_ISOLATION_MODE {
  NdisIsolationModeNone,
  NdisIsolationModeNativeVirtualSubnet,
  NdisIsolationModeExternalVirtualSubnet,
  NdisIsolationModeVlan
} NDIS_ISOLATION_MODE, *PNDIS_ISOLATION_MODE;