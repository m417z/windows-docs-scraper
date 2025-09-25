VOID NdisReadNetworkAddress(
  [out] PNDIS_STATUS Status,
  [out] PVOID        *NetworkAddress,
  [out] PUINT        NetworkAddressLength,
  [in]  NDIS_HANDLE  ConfigurationHandle
);