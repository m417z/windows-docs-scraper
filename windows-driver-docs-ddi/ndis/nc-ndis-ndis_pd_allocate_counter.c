NDIS_PD_ALLOCATE_COUNTER NdisPdAllocateCounter;

NTSTATUS() NdisPdAllocateCounter(
  [in]  NDIS_PD_PROVIDER_HANDLE ProviderHandle,
  [in]  const NDIS_PD_COUNTER_PARAMETERS *CounterParameters,
  [out] NDIS_PD_COUNTER_HANDLE *CounterHandle
)
{...}