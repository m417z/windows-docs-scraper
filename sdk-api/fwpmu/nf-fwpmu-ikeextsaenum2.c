DWORD IkeextSaEnum2(
  [in]  HANDLE             engineHandle,
  [in]  HANDLE             enumHandle,
  [in]  UINT32             numEntriesRequested,
  [out] IKEEXT_SA_DETAILS2 ***entries,
  [out] UINT32             *numEntriesReturned
);