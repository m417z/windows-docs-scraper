NTSTATUS FwpmNetEventEnum5(
  [in]  HANDLE          engineHandle,
  [in]  HANDLE          enumHandle,
  [in]  UINT32          numEntriesRequested,
  [out] FWPM_NET_EVENT5 ***entries,
  [out] UINT32          *numEntriesReturned
);