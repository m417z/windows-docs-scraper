NTSTATUS FwpmNetEventEnum4(
  [in]  HANDLE          engineHandle,
  [in]  HANDLE          enumHandle,
  [in]  UINT32          numEntriesRequested,
  [out] FWPM_NET_EVENT4 ***entries,
  [out] UINT32          *numEntriesReturned
);