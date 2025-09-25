NTSTATUS FwpmIPsecTunnelAdd0(
  [in]                              HANDLE                       engineHandle,
  [in]                              UINT32                       flags,
  [in, optional]                    const FWPM_PROVIDER_CONTEXT0 *mainModePolicy,
  [in]                              const FWPM_PROVIDER_CONTEXT0 *tunnelPolicy,
  [in]                              UINT32                       numFilterConditions,
  [ in, reads(numFilterConditions)] const FWPM_FILTER_CONDITION0 *filterConditions,
  [in, optional]                    PSECURITY_DESCRIPTOR         sd
);