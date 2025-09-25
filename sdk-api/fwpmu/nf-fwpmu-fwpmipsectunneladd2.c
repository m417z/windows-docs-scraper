DWORD FwpmIPsecTunnelAdd2(
  [in]           HANDLE                       engineHandle,
  [in]           UINT32                       flags,
  [in, optional] const FWPM_PROVIDER_CONTEXT2 *mainModePolicy,
  [in]           const FWPM_PROVIDER_CONTEXT2 *tunnelPolicy,
  [in]           UINT32                       numFilterConditions,
  [in]           const FWPM_FILTER_CONDITION0 *filterConditions,
  [in, optional] const GUID                   *keyModKey,
  [in, optional] PSECURITY_DESCRIPTOR         sd
);