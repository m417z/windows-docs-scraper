NTSTATUS IkeextSaEnum1(
  [in]  HANDLE             engineHandle,
  [in]  HANDLE             enumHandle,
  [in]  UINT32             numEntriesRequested,
  [out] IKEEXT_SA_DETAILS1 ***entries,
  [out] UINT32             *numEntriesReturned
);