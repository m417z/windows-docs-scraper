VOID NdisWriteConfiguration(
  [out] PNDIS_STATUS                  Status,
  [in]  NDIS_HANDLE                   ConfigurationHandle,
  [in]  PNDIS_STRING                  Keyword,
  [in]  PNDIS_CONFIGURATION_PARAMETER ParameterValue
);