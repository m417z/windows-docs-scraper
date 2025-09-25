NTSTATUS FwpmNetEventEnum3(
  [in]  HANDLE          engineHandle,
  [in]  HANDLE          enumHandle,
  [in]  UINT32          numEntriesRequested,
  [out] FWPM_NET_EVENT3 ***entries,
  [out] UINT32          *numEntriesReturned
);