NTSTATUS FwpmProviderContextAdd3(
  [in]            HANDLE                       engineHandle,
  [in]            const FWPM_PROVIDER_CONTEXT3 *providerContext,
  [in, optional]  PSECURITY_DESCRIPTOR         sd,
  [out, optional] UINT64                       *id
);