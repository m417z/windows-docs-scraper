NTSTATUS FwpmProviderContextEnum0(
  [in]  HANDLE                 engineHandle,
  [in]  HANDLE                 enumHandle,
  [in]  UINT32                 numEntriesRequested,
  [out] FWPM_PROVIDER_CONTEXT0 ***entries,
  [out] UINT32                 *numEntriesReturned
);