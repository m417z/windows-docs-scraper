NTSTATUS FwpmProviderContextAdd1(
  [in]            HANDLE                       engineHandle,
  [in]            const FWPM_PROVIDER_CONTEXT1 *providerContext,
  [in, optional]  PSECURITY_DESCRIPTOR         sd,
  [out, optional] UINT64                       *id
);