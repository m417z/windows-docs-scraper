DWORD FwpmProviderContextAdd0(
  [in]            HANDLE                       engineHandle,
  [in]            const FWPM_PROVIDER_CONTEXT0 *providerContext,
  [in, optional]  PSECURITY_DESCRIPTOR         sd,
  [out, optional] UINT64                       *id
);