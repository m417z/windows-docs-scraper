NTSTATUS FwpmProviderContextAdd2(
  [in]            HANDLE                       engineHandle,
  [in]            const FWPM_PROVIDER_CONTEXT2 *providerContext,
  [in, optional]  PSECURITY_DESCRIPTOR         sd,
  [out, optional] UINT64                       *id
);