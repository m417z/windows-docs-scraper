BOOL WINAPI CSCFindNextFileW(
  _In_  HANDLE           hFind,
  _Out_ WIN32_FIND_DATAW *lpFind32,
  _Out_ LPDWORD          lpdwStatus,
  _Out_ LPDWORD          lpdwPinCount,
  _Out_ LPDWORD          lpdwHintFlags,
  _In_  FILETIME         *lpOrgFileTime
);