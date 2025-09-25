NTSTATUS FwpmProviderContextEnum3(
  [in]  HANDLE                 engineHandle,
  [in]  HANDLE                 enumHandle,
  [in]  UINT32                 numEntriesRequested,
  [out] FWPM_PROVIDER_CONTEXT3 ***entries,
  [out] UINT32                 *numEntriesReturned
);