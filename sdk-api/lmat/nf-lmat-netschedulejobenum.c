NET_API_STATUS NET_API_FUNCTION NetScheduleJobEnum(
  [in, optional] LPCWSTR Servername,
  [out]          LPBYTE  *PointerToBuffer,
  [in]           DWORD   PrefferedMaximumLength,
  [out]          LPDWORD EntriesRead,
  [out]          LPDWORD TotalEntries,
  [in, out]      LPDWORD ResumeHandle
);