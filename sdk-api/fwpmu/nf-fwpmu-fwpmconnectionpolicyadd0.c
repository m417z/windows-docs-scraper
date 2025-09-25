DWORD FwpmConnectionPolicyAdd0(
  HANDLE                       engineHandle,
  const FWPM_PROVIDER_CONTEXT3 *connectionPolicy,
  FWP_IP_VERSION               ipVersion,
  UINT64                       weight,
  UINT32                       numFilterConditions,
  const FWPM_FILTER_CONDITION0 *filterConditions,
  PSECURITY_DESCRIPTOR         sd
);