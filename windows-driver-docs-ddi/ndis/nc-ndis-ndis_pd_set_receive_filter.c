NDIS_PD_SET_RECEIVE_FILTER NdisPdSetReceiveFilter;

NTSTATUS() NdisPdSetReceiveFilter(
  [in]  NDIS_PD_PROVIDER_HANDLE ProviderHandle,
  [in]  const NDIS_PD_FILTER_PARAMETERS *FilterParameters,
  [out] NDIS_PD_FILTER_HANDLE *FilterHandle
)
{...}