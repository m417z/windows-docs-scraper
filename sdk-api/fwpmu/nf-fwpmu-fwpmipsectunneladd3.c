DWORD FwpmIPsecTunnelAdd3(
  HANDLE                       engineHandle,
  UINT32                       flags,
  const FWPM_PROVIDER_CONTEXT3 *mainModePolicy,
  const FWPM_PROVIDER_CONTEXT3 *tunnelPolicy,
  UINT32                       numFilterConditions,
  const FWPM_FILTER_CONDITION0 *filterConditions,
  const GUID                   *keyModKey,
  PSECURITY_DESCRIPTOR         sd
);