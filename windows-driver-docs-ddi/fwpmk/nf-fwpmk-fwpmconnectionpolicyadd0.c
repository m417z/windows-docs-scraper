NTSTATUS FwpmConnectionPolicyAdd0(
  [in]                             HANDLE                       engineHandle,
  [in]                             const FWPM_PROVIDER_CONTEXT3 *connectionPolicy,
  [in]                             FWP_IP_VERSION               ipVersion,
  [in]                             UINT64                       weight,
  [in]                             UINT32                       numFilterConditions,
  [in, reads(numFilterConditions)] const FWPM_FILTER_CONDITION0 *filterConditions,
  [in, optional]                   PSECURITY_DESCRIPTOR         sd
);