NDIS_STATUS NdisIfRegisterInterface(
  [in] NDIS_HANDLE         NdisProviderHandle,
  [in] NET_LUID            NetLuid,
  [in] NDIS_HANDLE         ProviderIfContext,
  [in] PNET_IF_INFORMATION pIfInfo,
       PNET_IFINDEX        pfIndex
);