BOOL WINAPI CSCGetSpaceUsageW(
  _Inout_ LPTSTR  lptzLocation,
  _In_    DWORD   dwSize,
  _Inout_ LPDWORD lpdwMaxSpaceHigh,
  _Inout_ LPDWORD lpdwMaxSpaceLow,
  _Inout_ LPDWORD lpdwCurrentSpaceHigh,
  _Inout_ LPDWORD lpdwCurrentSpaceLow,
  _Inout_ LPDWORD lpcntTotalFiles,
  _Inout_ LPDWORD lpcntTotalDirs
);