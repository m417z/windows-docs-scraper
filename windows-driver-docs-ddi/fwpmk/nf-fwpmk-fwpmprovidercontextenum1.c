NTSTATUS FwpmProviderContextEnum1(
  [in]  HANDLE                 engineHandle,
  [in]  HANDLE                 enumHandle,
  [in]  UINT32                 numEntriesRequested,
  [out] FWPM_PROVIDER_CONTEXT1 ***entries,
  [out] UINT32                 *numEntriesReturned
);