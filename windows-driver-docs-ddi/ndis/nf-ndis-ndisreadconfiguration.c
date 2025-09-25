VOID NdisReadConfiguration(
  [out] PNDIS_STATUS                  Status,
  [out] PNDIS_CONFIGURATION_PARAMETER *ParameterValue,
  [in]  NDIS_HANDLE                   ConfigurationHandle,
  [in]  PNDIS_STRING                  Keyword,
  [in]  NDIS_PARAMETER_TYPE           ParameterType
);