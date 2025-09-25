NET_API_STATUS NET_API_FUNCTION NetQueryDisplayInformation(
  [in]  LPCWSTR ServerName,
  [in]  DWORD   Level,
  [in]  DWORD   Index,
  [in]  DWORD   EntriesRequested,
  [in]  DWORD   PreferredMaximumLength,
  [out] LPDWORD ReturnedEntryCount,
  [out] PVOID   *SortedBuffer
);