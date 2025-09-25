NDIS_STATUS NdisIfQueryBindingIfIndex(
  [in]  NDIS_HANDLE  NdisBindingHandle,
  [out] PNET_IFINDEX pBoundIfIndex,
  [out] PNET_LUID    pBoundIfNetLuid,
  [out] PNET_IFINDEX pLowestIfIndex,
  [out] PNET_LUID    pLowestIfNetLuid
);