VOID NdisOpenConfigurationKeyByIndex(
  [out] PNDIS_STATUS Status,
  [in]  NDIS_HANDLE  ConfigurationHandle,
  [in]  ULONG        Index,
  [out] PNDIS_STRING KeyName,
  [out] PNDIS_HANDLE KeyHandle
);